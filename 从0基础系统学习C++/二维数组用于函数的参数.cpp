#include <iostream>
using namespace std;
// void func(int p[][3],int len)
void func(int (*p)[3],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<3;j++)
            cout<<"p["<<i<<"]["<<j<<"]="<<p[i][j]<<"    ";
        cout<<endl;
    }
}
int main(void)
{
    // int a[10];
    // cout<<"����a��0��Ԫ�صĵ�ַ:"<<(long long)a<<endl;
    // cout<<"����a�ĵ�ַ:"<<(long long)&a<<endl;

    // cout<<"����a��0��Ԫ�صĵ�ַ+1:"<<(long long)(a+1)<<endl;
    // cout<<"����a�ĵ�ַ+1:"<<(long long)(&a+1)<<endl;

    // int *p1=a;
    // int (*p2)[10]=&a;
    int a[2][3]={{1,2,3},{10,11,12}};  //TODO: ��ά����a[2][3] �е�������a   -->   ���鳤��Ϊ3����ָ��  int (*p)[3]
    int (*q)[3]=a;
    // int *q1=a; // this is error
    func(a,2);
    return 0;
}