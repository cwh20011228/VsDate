#include <iostream>
using namespace std;

void func(int no,const string &name="西施",const string& str="我喜欢你。");

int main(void)
{
    func(3,"小李","我是一只傻傻鸟");
    func(5,"我是一只老鹰");
    return 0;
}

void func(int no,const string &name,const string& str)
{
    cout<<"亲爱的:"<<name<<" ("<<no<<") "<<str<<endl;
}