#include <iostream>
using namespace std;
//TODO: 引用的本质是指针常量 ，  类型 * const 指针名  (eg: int *const rb=&a;), 指针必须初始化
// C++怎么将指针常量伪装为引用？对编译器来说，即字符串的替换， int &ra=a;  int &替换为 int * const ,  a 替换为 &a
int main(void)
{
    int a=3;
    int &ra =a;             // ra是a的别名， 引用必须在创建的时候就初始化， 即是已存在每个变量的别名
    int * const rb=&a;      // 声明指针常量rb,让它指向a
    cout<<" a的地址是:  "<<&a<<",  a的值是:  "<<a<<endl;
    cout<<"ra的地址是:  "<<&a<<", ra的值是:  "<<ra<<endl;
    cout<<"rb的地址是:  "<<rb<<", rb的值是:  "<<*rb<<endl;

    int b = 5;

    ra = 5;
    cout<<" b的地址是:  "<<&b<<",  b的值是:  "<<b<<endl;
    cout<<" a的地址是:  "<<&a<<",  a的值是:  "<<a<<endl;
    cout<<"ra的地址是:  "<<&a<<", ra的值是:  "<<ra<<endl;
    cout<<"rb的地址是:  "<<rb<<", rb的值是:  "<<*rb<<endl;
}