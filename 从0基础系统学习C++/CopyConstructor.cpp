#include <iostream>
using namespace std;

class CGirl{
    public:
        string m_name;
        int m_age;
    CGirl();
    CGirl(string name,int age);
    CGirl(const CGirl& g0); // 默认的拷贝构造函数
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
// 拷贝构造函数可以重载，重载的时候，形参中一定要有类本身的常引用 const 类名&
// 如果普通函数中没有类本身的常引用，就成了普通的构造函数
int main(void)
{
    CGirl g1{"Jack",23};
    // CGirl g2(g1);
    // // CGirl g2=g1;
    // g2.show();
    func(g1); // 以值传递的方式调用函数，如果函数的实参是对象，会调用拷贝构造函数  


    /*CGirl g = func1(); // g++做了优化，没必要重新创建对象，可以不销毁func()函数中创建的那个对象gg,在main函数中换个变量名，就可以继续用
    g.show();
    cout<<"The address of object g is  "<<&g<<endl;*/

    /*CGirl g1{"Jack",23};
    CGirl g2(g1);
    g2.show();*/
    return 0;
}