#include <iostream>
using namespace std;

int main(void)
{
    int a;
    char b;
    bool c;
    string d;

    int *pa;
    char*pb;
    bool *pc;
    string *pd;
    cout<<"&a="<<(long long)&a<<endl;
    cout<<"&b="<<(long long)&b<<endl;
    cout<<"&c="<<(long long)&c<<endl;
    cout<<"&d="<<(long long)&d<<endl;
    cout<<endl;

    cout<<"pa="<<(long long)pa<<endl;
    cout<<"pb="<<(long long)pb<<endl;
    cout<<"pc="<<(long long)pc<<endl;
    cout<<"pd="<<(long long)pd<<endl;

    return 0;
}