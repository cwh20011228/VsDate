#include <iostream>
using namespace std;

int main(void)
{
    cout<<"sizeof(float)="<<sizeof(float)<<endl;
    cout<<"sizeof(double)="<<sizeof(double)<<endl;
    cout<<"sizeof(long double)="<<sizeof(long double)<<endl;
    float aa = 12345123.456789f; cout<<"aa="<<aa<<endl;
    double bb = 123451230123456789.456789; cout<<"bb="<<bb<<endl;
    long double cc = 123451230123456789.456789; cout<<"cc="<<cc<<endl;
    printf("aa=%lf\n",aa);
    printf("bb=%lf\n",bb);
    //TODO: long double    %Lf
    printf("cc=%Lf\n",cc);
    return 0;
}