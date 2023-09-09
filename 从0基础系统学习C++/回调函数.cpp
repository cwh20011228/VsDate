#include <iostream>
using namespace std;
// TODO: 回调函数：把一个函数的代码嵌入到另一个函数
// 给回调函数传递参数两种
// 1. 由调用者函数提供参数
// 2. 把实参从外面传进来

void zs(int a)
{
    cout<<"a="<<a<<"  我要先翻三个跟头再表白。\n";
}

void ls(int a)
{
    cout<<"a="<<a<<"我有一只小小鸟。\n";
}

void show(void (*pf)(int))
{
    cout<<"表白之前的准备工作已经完成。\n";
    int b=3; //TODO:由调用者函数提供参数
    pf(b);
    cout<<"表白之后的首位工作已完成。\n";
}

void show(void (*pf)(int),int b) //TODO: 把实参从外面传进来
{
    cout<<"表白之前的准备工作已经完成。\n";
    pf(b);
    cout<<"表白之后的首位工作已完成。\n";
}

int main(void)
{
    show(zs);
    show(ls,3);
    return 0;
}