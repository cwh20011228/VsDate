#include <iostream>
using namespace std;

void func(int no,string str);
int main(void)
{
    //TODO: 函数名就是函数的地址
    int bh = 3;
    string message = "我是一只傻傻鸟。";

    func(bh,message);

    void (*pfunc)(int,string); //TODO: 声明一个函数指针，函数指针后面的参数要与函数的参数一致
    pfunc = func; // TODO: 对函数指针赋值，c++中，函数指针名 = 函数名
    pfunc(bh,message); // TODO： 用函数指针名调用函数，C++
    (*func)(bh,message); //TODO: C语言中，用函数指针名调用函数
    return 0;
}

void func(int no,string str)
{
    cout<<"亲爱的"<<no<<"号："<<str<<endl;
}