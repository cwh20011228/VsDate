#include <iostream>
using namespace std;

class CGirl
{  
public:
    string m_name;
    static int m_age;
    CGirl(const string& name,int age);
    void showname();
    static void showage();
    ~CGirl();
};



CGirl::CGirl(const string& name,int age):m_name(name)
{
    m_age=age;
    cout<<"The CGir(const string& name,int yz) constructor was called."<<endl;
}

void CGirl::showage()
{
    cout<<"年龄："<<m_age<<endl;
}
// TODO: 静态成员函数只能访问静态成员变量
// 静态成员函数不用创建对象，就可以访问函数
// 静态成员函数不属于对象，没有this指针
void CGirl::showname()
{
    cout<<"姓名："<<m_name<<endl;
    // showage(); //非静态成员可以访问静态和非静态
}

CGirl::~CGirl()
{
    cout<<"The ~CGir() destructor was called."<<endl;
}

int CGirl::m_age=8;  //TODO: 初始化类的静态成员变量

int main(void)
{
    // CGirl::showage();
    // cout<<CGirl::m_age<<endl;
    CGirl g1("西施1",23),g2("西施2",23),g3("西施3",23);
    g1.showage();
    g1.showname();
    g2.showage();
    g2.showname();
    g3.showage();
    g3.showname();
    return 0;
}