#include <iostream>
#include <cstring>
using namespace std;

void func(int (*p)[2][3]){
int ii=1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                p[i][j][k]=ii++;
            }
        }
    }
}

int main(void)
{
    int bh[4][2][3];
    memset(bh,0,sizeof(bh));
    
    func(bh);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                cout<<bh[i][j][k]<<"\t";
               
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
}