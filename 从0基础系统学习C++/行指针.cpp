#include <iostream>
using namespace std;

int main(void)
{
    int a[10];

    cout<<"数组a第0个元素地地址："<<a<<endl;
    cout<<"数组a的地址："<<&a<<endl;

    cout<<"数组a第0个元素的地址+1："<<a+1<<endl;
    cout<<"数组a的地址+1："<<&a+1<<endl;
}
