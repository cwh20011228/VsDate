#include <iostream>
// #include <cstring>
using namespace std;

class CGirl{
    public:
        void show();
        void setvalue(string name,int age,int sex);
        CGirl();
        CGirl(string name);
        CGirl(string name,int age);
        ~CGirl();
        string m_name;
    private:
        int m_age=38;
        int m_sex;  // 1-girl ,2-boy
        enum{girl=1,boy=2}; // ����ö��


};

CGirl::CGirl()
{
    m_name.clear(); 
    m_age = 0;
    m_sex=1;
    cout<<"������CGirl()���캯��."<<endl;
}

CGirl::CGirl(string name)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    cout<<"������CGirl(string name)���캯��."<<endl;
}

CGirl::CGirl(string name,int age)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    cout<<"������CGirl(string name,int age)���캯��."<<endl;

}

CGirl::~CGirl()
{
    cout<<"������~CGirl()"<<endl;
}

// void CGirl::setvalue(string name,int age,int sex)
// {
//     m_age=age;
//     m_name=name;
//     m_sex=sex;
// }

void CGirl::show()
{
    cout<<"����:"<<m_name<<"  ����:"<<m_age;
    if(m_sex==girl){ cout<<"  Ů��"<<endl;}
    else if(m_sex==boy) cout<<"  �к�"<<endl;
}




int main(void)
{
    // CGirl girl("Smith",23);
    CGirl girl;
    // girl.show();
    girl.~CGirl();
    return 0;
}