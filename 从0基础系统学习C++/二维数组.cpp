#include <iostream>
#include <cstring>
using namespace std;


int main(void)
{
    int a=8;
    int b[a]={0};
    int c[a/2]={0};
    
    int bh[2][3]={{1,2,3},{4,5,6}};
    // memset(bh,0,sizeof(bh));
    int hh[6]={0};
    memcpy(hh,bh,sizeof(bh));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"bh["<<i<<"]["<<j<<"]="<<bh[i][j]<<"  ";
        }
        cout<<endl;
    }

    int *p=(int *)hh;
    for(int i=0;i<6;i++)
    {
        cout<<"p["<<i<<"]="<<p[i]<<"  ";
    }
    return 0;
}