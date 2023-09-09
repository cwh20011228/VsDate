#include <iostream>
using namespace std;
//TODO: 引用使用基本原则：被引用的变量的生命周期要比引用长
int func1() // 返回的是值
{
    int ii=3;
    return ii;
}

// int ii=5;
int& func2() // 返回的是引用
{
    static int ii=3;  //静态局部变量，只初始化一次（在编译时初始化）。如果出了这个函数后，它将保持本次的值，到下次使用的时候，就使用这个值
    // int ii=3;
    return ii;
}

int& func3(int &ra) //返回的是引用
{
    ra++;
    cout<<"ra的地址是:"<<&ra<<"  ra="<<ra<<endl;
    return ra;
}

int main(void)
{
    int a=func1(); cout<<"a="<<a<<endl;
    int c=func2(); cout<<"c="<<c<<endl;
    // int a=3;
    // int &b = func3(a);  // 返回的是引用
    // cout<<"a的地址是:"<<&a<<"  a="<<a<<endl;
    // cout<<"b的地址是:"<<&b<<"  b="<<b<<endl;

    // func3(a)=10;  //返回引用的函数是被引用变量的别名
    // cout<<"a的地址是:"<<&a<<"  a="<<a<<endl;
    // cout<<"b的地址是:"<<&b<<"  b="<<b<<endl;
    return 0;
}