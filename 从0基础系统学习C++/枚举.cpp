#include <iostream>
using namespace std;

int main(void)
{
    enum colors {red,blue,yellow,other};
    colors cc = colors(0);  // 强制转化， 枚举类型(常数)

    cout<<"red="<<red<<"  blue="<<blue<<"  yellow="<<yellow<<"  other="<<other<<endl;
    switch(cc)
    {
        case red: cout<<"红色"<<endl; break;
        case blue: cout<<"蓝色"<<endl; break;
        case yellow: cout<<"黄色"<<endl; break;
        default:  cout<<"其他颜色"<<endl;
    }
}