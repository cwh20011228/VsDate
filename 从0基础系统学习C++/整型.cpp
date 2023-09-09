#include <iostream>
using namespace std;

int main(void)
{
    cout<<"sizeof(short)="<<sizeof(short)<<endl;
    cout<<"sizeof(unsigned short)="<<sizeof(unsigned short)<<endl;
    cout<<"sizeof(int)="<<sizeof(int)<<endl;
    cout<<"sizeof( unsigned int)="<<sizeof( unsigned int)<<endl;
    cout<<"sizeof(long)="<<sizeof(long)<<endl;
    cout<<"sizeof(unsigned long )="<<sizeof(unsigned long)<<endl;
    unsigned short ii=65536+1;
    cout<<"ii="<<ii<<endl;
    return 0;
}