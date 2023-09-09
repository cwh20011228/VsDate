#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    double m_weight;
    CGirl():m_bh(8),m_name("西施"),m_weight(50.7){ cout<<"The CGirl() Constructor was called."<<endl;}
    operator int() {return m_bh;}
    operator double() {return m_weight;}
    operator string() {return m_name;}
    int to_int() {return m_bh;}
};

//TODO: explicit 使得转换函数必须显示的调用

int main(void)
{
    CGirl g;
    // 隐式转换，编译器根据 = 号左边变量的数据类型，决定调用哪个转换函数
    int a=g;            cout<<"g.m_bh="<<g.m_bh<<"   a="<<a<<endl;
    string b=g;         cout<<"g.m_name="<<g.m_name<<"   b="<<b<<endl;
    double c=g;         cout<<"g.m_weight="<<g.m_weight<<"   c="<<c<<endl;

    // 显示转换，在对象名前面指定数据类型
    int d=(int)g;       cout<<"g.m_bh="<<g.m_bh<<"   d="<<d<<endl;
    string e=(string)g; cout<<"g.m_name="<<g.m_name<<"   e="<<e<<endl;
    double f=(double)g; cout<<"g.m_weight="<<g.m_weight<<"   f="<<f<<endl;
    // 显示转换
    int k=int(g);       cout<<"g.m_bh="<<g.m_bh<<"   k="<<k<<endl;
    string h=string(g); cout<<"g.m_name="<<g.m_name<<"   h="<<h<<endl;
    double j=double(g); cout<<"g.m_weight="<<g.m_weight<<"   j="<<j<<endl;

    // short l = g;  // 出现二义性，int() 和 double() 都可以，编译器不知道选择哪个
    int m= g.to_int();
    return 0;
}