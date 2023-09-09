#include <iostream>
using namespace std;

int main(void)
{

    cout<<"sizeof(int)="<<sizeof(int)<<endl;
    cout<<"sizeof(float)="<<sizeof(float)<<endl;
    cout<<"sizeof(double)="<<sizeof(double)<<endl;
    cout<<"sizeof(bool)="<<sizeof(bool)<<endl;
    cout<<"sizeof(char)="<<sizeof(char)<<endl;
    cout<<"sizeof(int *)="<<sizeof(int *)<<endl;
    // TODO: sizeof 的用法
    // sizeof 后面直接跟变量名  /*sizeof 变量名
    int i; cout<<"sizeof(int)="<<sizeof i <<endl;
    float a; cout<<"sizeof(float)="<<sizeof a <<endl;
    double b; cout<<"sizeof(double)="<<sizeof b<<endl;
    bool c; cout<<"sizeof(bool)="<<sizeof c <<endl;
    char d; cout<<"sizeof(char)="<<sizeof d <<endl;
    int *e; cout<<"sizeof(int *)="<<sizeof e <<endl;
    return 0;
}