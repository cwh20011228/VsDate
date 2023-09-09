#include <iostream>
using namespace std;

int main(void)
{
    // char a; cout<<"sizeof(char)="<<sizeof(char)<<endl;
    // short b; cout<<"sizeof(short)="<<sizeof(short)<<endl;
    // int c;  cout<<"sizeof(int)="<<sizeof(int)<<endl;
    // double d; cout<<"sizeof(double)="<<sizeof(double)<<endl;
    
    // cout<<"a的地址是："<<(void*)&a<<endl;
    // cout<<"a的地址+1是："<<(void*)(&a+1) <<endl;

    // cout<<"b的地址是："<<&b<<endl;
    // cout<<"b的地址+1是："<<&b+1<<endl;

    // cout<<"c的地址是："<<&c<<endl;
    // cout<<"c的地址+1是："<<&c+1<<endl;

    // cout<<"d的地址是："<<&d<<endl;
    // cout<<"d的地址+1是："<<&d+1<<endl;


    int a[5]={3,6,5,8,9};
    // cout<<"a的值为："<<(long long)a<<endl;
    // cout<<"&a的值为："<<(long long)&a<<endl;
    // cout<<"a[0]的地址是："<<(long long)&a[0]<<endl;
    // cout<<"a[1]的地址是："<<(long long)&a[1]<<endl;
    // cout<<"a[2]的地址是："<<(long long)&a[2]<<endl;
    // cout<<"a[3]的地址是："<<(long long)&a[3]<<endl;
    // cout<<"a[4]的地址是："<<(long long)&a[4]<<endl;
    // cout<<"a[0]的值是："<<a[0]<<endl;
    // cout<<"a[1]的值是："<<a[1]<<endl;
    // cout<<"a[2]的值是："<<a[2]<<endl;
    // cout<<"a[3]的值是："<<a[3]<<endl;
    // cout<<"a[4]的值是："<<a[4]<<endl;
    // cout<<endl;
    int *p = a;
    cout<<"p的值是："<<(long long)(p)<<endl;
    cout<<"p+0的值是："<<(long long)(p+0)<<endl;
    cout<<"p+1的值是："<<(long long)(p+1)<<endl;
    cout<<"p+2的值是："<<(long long)(p+2)<<endl;
    cout<<"p+3的值是："<<(long long)(p+3)<<endl;
    cout<<"p+4的值是："<<(long long)(p+4)<<endl;
    cout<<"*(p+0)的值是："<<*(p+0)<<endl;
    cout<<"*(p+1)的值是："<<*(p+1)<<endl;
    cout<<"*(p+2)的值是："<<*(p+2)<<endl;
    cout<<"*(p+3)的值是："<<*(p+3)<<endl;
    cout<<"*(p+4)的值是："<<*(p+4)<<endl;
    cout<<"sizeof(a)="<<sizeof(a)/sizeof(a[0])<<endl;
    return 0;
}