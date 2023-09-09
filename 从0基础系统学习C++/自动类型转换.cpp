#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    double m_weight;
    CGirl():m_bh(0),m_weight(0) { m_name.clear(); cout<<"The CGirl() constructor was called."<<endl;}
    void show() { cout<<"bh="<<m_bh<<"   name="<<m_name<<"   weight="<<m_weight<<endl;}
    CGirl(int bh):m_bh(bh),m_weight(0) {m_name.clear(); cout<<"The CGirl(int) constructor was called."<<endl;}  // 除了是constructor,还是转换函数
    CGirl(const CGirl& g):m_bh(g.m_bh),m_name(g.m_name),m_weight(g.m_weight) {cout<<"The CGirl(const CGirl&) constructor was called."<<endl;}
    CGirl(double weight):m_bh(0),m_weight(weight) { m_name.clear(); cout<<"The CGirl(double) constructor was called."<<endl;}
    ~CGirl() {cout<<"调用了析构函数\n";}
};

void func(CGirl g)
{
    g.show();
}

CGirl func1(){    return 8;}

CGirl func2(){    char c = 8;    return c;}


int main(void)
{
    // CGirl g1(8);    // 显示转换  
    // CGirl g2 = CGirl(8); //显示转换 
    // CGirl g3=8;  // 隐式转换,直接创建  CGirl g3(8);
    // CGirl g4;
    // g4 = 8;  //  隐式转换,用CGirl(8)创建临时对象,再赋值给g4

    // g1.show();
    // g2.show();
    // g3.show();
    // g4.show();

    // CGirl g5 = 8.7;
    // g5.show();

    func(8);    // 将int值传递给接受 CGirl参数的函数时，发生了  隐式转换
    func1();    // 返回值被声明为 CGirl 的函数试图返回 int 值 ， 隐式转换 ，调用了参数为int的转换函数
    func2();    // 如果值不是整数的话，可以转换为整数，调用转换函数
    return 0;
}