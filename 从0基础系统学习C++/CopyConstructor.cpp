#include <iostream>
using namespace std;

class CGirl{
    public:
        string m_name;
        int m_age;
    CGirl();
    CGirl(string name,int age);
    CGirl(const CGirl& g0); // Ĭ�ϵĿ������캯��
    CGirl(const CGirl& g0,int ii);
    ~CGirl();
    void show();
};

CGirl::CGirl()
{
    m_name.clear();
    m_age=0;
    cout<<"The CGirl() constructor was called."<<endl;
}

CGirl::CGirl(string name,int age)
{
    m_name=name;
    m_age=age;
    cout<<"The CGirl(string name,int age) constructor was called."<<endl;
}

CGirl::CGirl(const CGirl& g0)
{
    m_name = g0.m_name;
    m_age=g0.m_age;
    cout<<"The CGirl(const CGirl&) Copy constructor was called"<<endl;
}

CGirl::CGirl(const CGirl& g0,int ii)
{
    m_name = g0.m_name;
    m_age=g0.m_age;
    cout<<"The CGirl(const CGirl&,int ii) Copy constructor was called"<<endl;
}
CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}

void CGirl::show()
{
    cout<<"name="<<m_name<<"  age="<<m_age<<endl;
}

void func(CGirl g)
{
    g.show();
}

CGirl func1()
{
    CGirl gg{"Smith",24};
    cout<<"The address of object gg is  "<<&gg<<endl;
    return gg;
}
// �������캯���������أ����ص�ʱ���β���һ��Ҫ���౾��ĳ����� const ����&
// �����ͨ������û���౾��ĳ����ã��ͳ�����ͨ�Ĺ��캯��
int main(void)
{
    CGirl g1{"Jack",23};
    // CGirl g2(g1);
    // // CGirl g2=g1;
    // g2.show();
    func(g1); // ��ֵ���ݵķ�ʽ���ú��������������ʵ���Ƕ��󣬻���ÿ������캯��  


    /*CGirl g = func1(); // g++�����Ż���û��Ҫ���´������󣬿��Բ�����func()�����д������Ǹ�����gg,��main�����л������������Ϳ��Լ�����
    g.show();
    cout<<"The address of object g is  "<<&g<<endl;*/

    /*CGirl g1{"Jack",23};
    CGirl g2(g1);
    g2.show();*/
    return 0;
}