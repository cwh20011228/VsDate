#include <iostream>
using namespace std;


void func1(int no,string str) //传值
{
    no=8;
    str = "我有一只小小鸟。";
    cout<<"亲爱的"<<no<<"号:"<<str<<endl;
}

void func2(int *no,string *str) //传指针
{
    *no=8;
    *str = "我有一只小小鸟。";
    cout<<"亲爱的"<<*no<<"号:"<<*str<<endl;
}

void func3(int &no,string &str) //传引用
{
    no=8;
    str = "我有一只小小鸟。";
    cout<<"亲爱的"<<no<<"号:"<<str<<endl;
}

int main(void)
{
    int bh = 3;
    string message = "我是一只傻傻鸟.";

    // func1(bh,message);
    // func2(&bh,&message);
    func3(bh,message);
    cout<<"亲爱的"<<bh<<"号:"<<message<<endl;

    return 0;
}