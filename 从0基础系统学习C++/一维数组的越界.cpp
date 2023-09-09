#include <iostream>
using namespace std;

int main(void)
{
    int a[5]={1,2,3,4,9};
    for(int ii=-2;ii<88;ii++)
    {
        // a[ii]=ii+100;
        // cout<<"a["<<ii<<"]的值是："<<a[ii]<<endl;
        cout<<"a["<<ii<<"]的地址是："<<&a[ii]<<endl;
    }
    int *p= a;
    for(int i=0;i<88;i++)
    {
        cout<<"*(p+"<<i<<")的值是："<<*(p+i)<<endl;
    }
    return 0;
}