#include <iostream>
using namespace std;

class CGirl
{
    public:
        mutable string m_name;
        int m_age;
        CGirl(const string& name,int age);
        ~CGirl();
        void show1() const; // show()���������޸ĳ�Ա����
        void show2() const;
        void show3() ;
        void show4() ;
};

CGirl::CGirl(const string& name,int age):m_name(name),m_age(age)
{
    cout<<"The CGir(const string& name,int age) constructor was called."<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}


void CGirl::show1() const  
{
    m_name="SMith   show1";
    cout<<"name: "<<m_name<<"  age:  "<<m_age<<endl;
    // show3();
}

void CGirl::show2() const  
{
    m_name="SMith   show2";
    cout<<"name: "<<m_name<<"  age:  "<<m_age<<endl;
}

void CGirl::show3()   
{
    m_name="SMith   show3";
    cout<<"name: "<<m_name<<"  age:  "<<m_age<<endl;
    show4();
    show1();
}

void CGirl::show4() 
{
    m_name="SMith   show4";
    cout<<"name: "<<m_name<<"  age:  "<<m_age<<endl;
}

int main(void)
{
    CGirl g0("JACK",25);
    g0.show1();
    g0.show2();
    g0.show3();
    
    const CGirl g1("Boyh",28); //TODO: ������ֻ�ܷ��ʼ���const�ĳ�Ա����,g1ֻ�ܷ���show1()��show2()
    g1.show1();
    g1.show2();
    return 0;
}