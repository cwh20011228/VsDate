#include <iostream>
using namespace std;

union 
{
    int a;
    double b;
    char c[21];
}data;  // data为匿名共同体


int main(void)
{
    // udata data;
    cout<<"sizeof(data)="<<sizeof(data)<<endl;
    cout<<"data.a的地址="<<(void*)&data.a<<endl;
    cout<<"data.b的地址="<<(void*)&data.b<<endl;
    cout<<"data.c的地址="<<(void*)&data.c<<endl;

    data.b=30;
    cout<<"data.a="<<data.a<<endl;
    cout<<"data.b="<<data.b<<endl;
    cout<<"data.c="<<data.c<<endl;

    return 0;
}