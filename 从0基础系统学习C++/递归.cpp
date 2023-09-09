#include <iostream>
using namespace std;

int f(int x);

int main(void){
    int n = 3;
    cout<<"f(3)="<<f(3)<<endl;

    return 0;
}

int f(int x)
{
    if(x==0) return 0;
    return x+f(x-1);
}