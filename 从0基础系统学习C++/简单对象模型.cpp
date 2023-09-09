#include <iostream>
#include <cstring>
using namespace std;
//TODO： 在程序猿看来，C++对象是一个整体，但是，对象的各种成员变量和成员函数实际上是分散在内存的，所以,在C++内部，肯定存放了成员的地址信息，那就是对象的指针表
//TODO: 静态成员属于类，在整个程序中只有一份，不计算在对象的大小中
class CGirl
{  
public:
    static char m_name[3];
    // char m_name[3];
    int m_age;
    int m_bh;
    CGirl();
    void showname();
    void showage();
    ~CGirl();
};
// 类的成员函数是分开存储的，存放在内存四区的代码段中，不管是否创建了对象，都会占用存储空间。不管创建了多少对象，在内存中只有一个副本，也不计算在对象大小之内

char CGirl::m_name[3] = {0}; // 静态成员变量必须在全局区初始化，不会在创建对象的时候初始化

CGirl::CGirl()
{
    memset(m_name,0,sizeof(m_name));
    m_age=0;
    m_bh=0;
    cout<<"The CGir() constructor was called."<<endl;
}

void CGirl::showage()
{
    cout<<"年龄："<<m_age<<endl;
}

void CGirl::showname()
{
    cout<<"姓名："<<m_name<<endl;

}

CGirl::~CGirl()
{
    cout<<"The ~CGir() destructor was called."<<endl;
}

class A{};
int aaa; 
void func() {}

int main(void)
{
    CGirl g;
    cout<<"对象g占用的内存大小是："<<sizeof(g)<<endl;
//TODO：  非静态成员变量的地址是连续的。静态成员变量和全局变量的地址是在一起连续的
//TODO:  对象的地址是第一个非静态成员变量的地址 
    cout<<"对象g的地址是：          "<<&g<<endl;
    cout<<"成员变量m_name的地址是； "<<&g.m_name<<endl;
    cout<<"变量aaa的地址是；        "<<&aaa<<endl;
    cout<<"成员变量m_age的地址是；  "<<&g.m_age<<endl;
    cout<<"成员变量m_bh的地址是；   "<<&g.m_bh<<endl;

// 成员函数的地址和成员变量的地址不在一起
// 类的成员函数的地址和普通函数的地址是在一起的
    printf("成员函数showname()的地址是：%p\n",&CGirl::showname);
    printf("成员函数showage()的地址是： %p\n",&CGirl::showage);
    printf("普通函数func()的地址是：    %p\n",&func);
    // A a;
    // cout<<"对象a占用的内存大小是："<<sizeof(a)<<endl;

    CGirl *g1 = nullptr;
    g1->showname();
    return 0;
}