#include <iostream>
using namespace std;

int main(void)
{
    enum colors {red,blue,yellow,other};
    colors cc = colors(0);  // ǿ��ת���� ö������(����)

    cout<<"red="<<red<<"  blue="<<blue<<"  yellow="<<yellow<<"  other="<<other<<endl;
    switch(cc)
    {
        case red: cout<<"��ɫ"<<endl; break;
        case blue: cout<<"��ɫ"<<endl; break;
        case yellow: cout<<"��ɫ"<<endl; break;
        default:  cout<<"������ɫ"<<endl;
    }
}