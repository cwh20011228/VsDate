#include <iostream>
using namespace std;

void func(int bh,string message)
{
    cout<<"亲爱的"<<bh<<"号："<<message<<endl;
}

int main(void)
{
    int bh = 3;
    string messages = "我是一只小小鸟";
    func(bh,messages);

    void (*pfunc)(int,string); // 声明表白函数的函数指针
    pfunc = func;  // 对函数指针赋值， 语法： 函数指针名 = 函数名，函数名就是函数的地址
    pfunc(bh,messages); // 用函数指针名调用函数，c++语法
    (*func)(bh,messages);  // c语言

    return 0;
}