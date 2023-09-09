#include <iostream>
using namespace std;

void func(string varname,void *p)
{
    cout<<"&"<<varname<<"="<<p<<endl;
}

int main(void)
{
    int a;
    string b="csve";
    char c='a';
    cout<<"&a="<<(void *)&a<<endl;
    cout<<"&b="<<(void*)&b<<endl;
    cout<<"&c="<<(void*)&c<<endl;
          
    func("a",&a);
    func("b",&b);
    func("c",&c);
    
    return 0;
}