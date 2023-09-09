#include <iostream>
using namespace std;

int main(void)
{
    long long a = 9223372036854775807; cout<<"sizeof(a)="<<sizeof(a)<<",a="<<a<<endl;
    long long b = 9223372036854775907; cout<<"sizeof(a)="<<sizeof(b)<<",b="<<b<<endl;
    return 0;
}