#include <iostream>
using namespace std;

int main(void)
{
    char a = 'X'+3;
    cout << "a=" << a << endl
        << "sizeof(char)=" << sizeof(char) << endl;
    char b = 51;
    cout<<"b="<<b<<endl;
    if('3'>51) cout<<"ok\n"<<endl;
    if('3'==51) cout<<"ok2\n"<<endl;
    if('3'<51) cout<<"ok3\n"<<endl;
    return 0;
}