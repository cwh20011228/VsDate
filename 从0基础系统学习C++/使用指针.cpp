#include <iostream>
using namespace std;

int main(void)
{
    int a = 3;
    int *p = &a;
    int *p1 = &a;
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    cout << "*p1=" << *p1 << endl;
    // *p = 8;
    a = 8;
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    cout << "*p1=" << *p1 << endl;

    cout<<"&a="<<&a<<endl;
    cout<<"p="<<p<<endl;
    cout<<"p1="<<p1<<endl;

    return 0;
}