#include <iostream>
using namespace std;

int main(void)
{
    typedef unsigned int u_int;
    typedef long long l_long;
    typedef unsigned long long ul_long;
    u_int a = 1024;
    l_long b = 545785;
    ul_long c = 12345689665;
    cout<<"sizeof(a)"<<sizeof(u_int)<<",a="<<a<<endl;
    cout<<"sizeof(b)"<<sizeof(l_long)<<",b="<<b<<endl;
    cout<<"sizeof(c)"<<sizeof(ul_long)<<",c="<<c<<endl;
cout<<sizeof(long);
    // TODO: ���������Ĵ������ͷ�ļ���
    // �� windos�£� short�������ֽڣ�int ���ĸ��ֽڣ�long��4���ֽڣ�long long ��8���ֽ�
    // typedef short      int16_t; // 16λ������
    // typedef int        int32_t; // 32λ������
    // typedef long long  int64_t; // 64λ������

    // �� linux�£� short�������ֽڣ�int ���ĸ��ֽڣ�long��8���ֽڣ�long long ��8���ֽ�
    // typedef short      int16_t; // 16λ������
    // typedef int        int32_t; // 32λ������
    // typedef long       int64_t; // 64λ������
    return 0;
}