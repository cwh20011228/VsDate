#include <iostream>
using namespace std;

void func(const int* no,const string *str);

int main(void)
{
    int a=3;
    const int *p=&a;
    a=13;
    int b=10;
    cout<<"a="<<a<<"  "<<"*p="<<*p<<endl;
    p=&b;
    cout<<"b="<<b<<"  "<<"*p="<<*p<<endl;
    
    int * const pp=&a ;
    cout<<"pp="<<*pp<<endl;
    return 0;
}

void func(const int *no,const string *str)
{
    cout<<"�װ���"<<*no<<"�ţ�"<<*str<<endl;
    // *no = 8;
    // *str = "����һֻСС��";
}