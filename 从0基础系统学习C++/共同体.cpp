#include <iostream>
using namespace std;

union 
{
    int a;
    double b;
    char c[21];
}data;  // dataΪ������ͬ��


int main(void)
{
    // udata data;
    cout<<"sizeof(data)="<<sizeof(data)<<endl;
    cout<<"data.a�ĵ�ַ="<<(void*)&data.a<<endl;
    cout<<"data.b�ĵ�ַ="<<(void*)&data.b<<endl;
    cout<<"data.c�ĵ�ַ="<<(void*)&data.c<<endl;

    data.b=30;
    cout<<"data.a="<<data.a<<endl;
    cout<<"data.b="<<data.b<<endl;
    cout<<"data.c="<<data.c<<endl;

    return 0;
}