#include <iostream>
using namespace std;

int main(void)
{
    char a = 30;
    int b = 102400;
    long long c = 150000000000001;
    cout << "a+b+c=" << a + b + c << endl;
    cout << "8/5=" << (double)8 / 5 << endl;
    int d = (int)23.6;
    cout<<"d="<<d<<endl;
    unsigned int e = (unsigned int)4294967295+100; //TODO: 值被截断，从高位截断
    cout<<"e="<<e<<endl;
    // 4294968295       11111111111111111111111111111111
    // 4294967296  0001 00000000000000000000000000000000 --> （高位截断） 00000000000000000000000000000000
    // 4294967297  0001 00000000000000000000000000000001 -->             00000000000000000000000000000001
    
    return 0;
}