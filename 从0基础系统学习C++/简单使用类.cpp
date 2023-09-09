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
        enum{girl=1,boy=2}; // 匿名枚举


};

CGirl::CGirl()
{
    m_name.clear(); 
    m_age = 0;
    m_sex=1;
    cout<<"调用了CGirl()构造函数."<<endl;
}

CGirl::CGirl(string name)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    cout<<"调用了CGirl(string name)构造函数."<<endl;
}

CGirl::CGirl(string name,int age)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    cout<<"调用了CGirl(string name,int age)构造函数."<<endl;

}

CGirl::~CGirl()
{
    cout<<"调用了~CGirl()"<<endl;
}

// void CGirl::setvalue(string name,int age,int sex)
// {
//     m_age=age;
//     m_name=name;
//     m_sex=sex;
// }

void CGirl::show()
{
    cout<<"姓名:"<<m_name<<"  年龄:"<<m_age;
    if(m_sex==girl){ cout<<"  女孩"<<endl;}
    else if(m_sex==boy) cout<<"  男孩"<<endl;
}




int main(void)
{
    // CGirl girl("Smith",23);
    CGirl girl;
    // girl.show();
    girl.~CGirl();
    return 0;
}