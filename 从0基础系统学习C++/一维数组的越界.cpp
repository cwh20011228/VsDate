#include <iostream>
using namespace std;

int main(void)
{
    int a[5]={1,2,3,4,9};
    for(int ii=-2;ii<88;ii++)
    {
        // a[ii]=ii+100;
        // cout<<"a["<<ii<<"]��ֵ�ǣ�"<<a[ii]<<endl;
        cout<<"a["<<ii<<"]�ĵ�ַ�ǣ�"<<&a[ii]<<endl;
    }
    int *p= a;
    for(int i=0;i<88;i++)
    {
        cout<<"*(p+"<<i<<")��ֵ�ǣ�"<<*(p+i)<<endl;
    }
    return 0;
}