#include <iostream>
using namespace std;

int* func();

int main(void)
{
    // int *n;
    // cout<<"n="<<n<<", *n="<<*n<<endl;

    int *p = new int{3};
    cout<<"p="<<p<<", *p="<<*p<<endl;
    delete p;
    cout<<"p="<<p<<", *p="<<*p<<endl;

    // int *p = func();
    // cout<<"p="<<p<<", *p="<<*p<<endl;
    return 0;
}

// int* func()
// {
//     int a=3;
//     cout<<"&a="<<&a<<", a="<<a<<endl;
//     return &a;
// }