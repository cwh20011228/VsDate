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
    // cout<<"数组a第0个元素的地址:"<<(long long)a<<endl;
    // cout<<"数组a的地址:"<<(long long)&a<<endl;

    // cout<<"数组a第0个元素的地址+1:"<<(long long)(a+1)<<endl;
    // cout<<"数组a的地址+1:"<<(long long)(&a+1)<<endl;

    // int *p1=a;
    // int (*p2)[10]=&a;
    int a[2][3]={{1,2,3},{10,11,12}};  //TODO: 二维数组a[2][3] 中的数组名a   -->   数组长度为3的行指针  int (*p)[3]
    int (*q)[3]=a;
    // int *q1=a; // this is error
    func(a,2);
    return 0;
}