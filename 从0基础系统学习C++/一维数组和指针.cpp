#include <iostream>
using namespace std;

int main(void)
{
    // char a; cout<<"sizeof(char)="<<sizeof(char)<<endl;
    // short b; cout<<"sizeof(short)="<<sizeof(short)<<endl;
    // int c;  cout<<"sizeof(int)="<<sizeof(int)<<endl;
    // double d; cout<<"sizeof(double)="<<sizeof(double)<<endl;
    
    // cout<<"a�ĵ�ַ�ǣ�"<<(void*)&a<<endl;
    // cout<<"a�ĵ�ַ+1�ǣ�"<<(void*)(&a+1) <<endl;

    // cout<<"b�ĵ�ַ�ǣ�"<<&b<<endl;
    // cout<<"b�ĵ�ַ+1�ǣ�"<<&b+1<<endl;

    // cout<<"c�ĵ�ַ�ǣ�"<<&c<<endl;
    // cout<<"c�ĵ�ַ+1�ǣ�"<<&c+1<<endl;

    // cout<<"d�ĵ�ַ�ǣ�"<<&d<<endl;
    // cout<<"d�ĵ�ַ+1�ǣ�"<<&d+1<<endl;


    int a[5]={3,6,5,8,9};
    // cout<<"a��ֵΪ��"<<(long long)a<<endl;
    // cout<<"&a��ֵΪ��"<<(long long)&a<<endl;
    // cout<<"a[0]�ĵ�ַ�ǣ�"<<(long long)&a[0]<<endl;
    // cout<<"a[1]�ĵ�ַ�ǣ�"<<(long long)&a[1]<<endl;
    // cout<<"a[2]�ĵ�ַ�ǣ�"<<(long long)&a[2]<<endl;
    // cout<<"a[3]�ĵ�ַ�ǣ�"<<(long long)&a[3]<<endl;
    // cout<<"a[4]�ĵ�ַ�ǣ�"<<(long long)&a[4]<<endl;
    // cout<<"a[0]��ֵ�ǣ�"<<a[0]<<endl;
    // cout<<"a[1]��ֵ�ǣ�"<<a[1]<<endl;
    // cout<<"a[2]��ֵ�ǣ�"<<a[2]<<endl;
    // cout<<"a[3]��ֵ�ǣ�"<<a[3]<<endl;
    // cout<<"a[4]��ֵ�ǣ�"<<a[4]<<endl;
    // cout<<endl;
    int *p = a;
    cout<<"p��ֵ�ǣ�"<<(long long)(p)<<endl;
    cout<<"p+0��ֵ�ǣ�"<<(long long)(p+0)<<endl;
    cout<<"p+1��ֵ�ǣ�"<<(long long)(p+1)<<endl;
    cout<<"p+2��ֵ�ǣ�"<<(long long)(p+2)<<endl;
    cout<<"p+3��ֵ�ǣ�"<<(long long)(p+3)<<endl;
    cout<<"p+4��ֵ�ǣ�"<<(long long)(p+4)<<endl;
    cout<<"*(p+0)��ֵ�ǣ�"<<*(p+0)<<endl;
    cout<<"*(p+1)��ֵ�ǣ�"<<*(p+1)<<endl;
    cout<<"*(p+2)��ֵ�ǣ�"<<*(p+2)<<endl;
    cout<<"*(p+3)��ֵ�ǣ�"<<*(p+3)<<endl;
    cout<<"*(p+4)��ֵ�ǣ�"<<*(p+4)<<endl;
    cout<<"sizeof(a)="<<sizeof(a)/sizeof(a[0])<<endl;
    return 0;
}