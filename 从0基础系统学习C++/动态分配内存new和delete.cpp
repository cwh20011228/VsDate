#include <iostream>
using namespace std;

int main(void)
{
    int *p = new int{5};
    cout << "*p=" << *p << " "
         << "p=" << (void *)p << endl;
    *p = 16;
    cout << "*p=" << *p << " "
         << "p=" << (void *)p << endl;
     delete p;
    // TODO: 如果new后不释放 ,程序有可能奔溃 ，比如下面的code
    // for(int i=1;i>0;i++)
    // {
    //     int *p = new int[100000];
    //     cout<<"*p="<<*p<<" "<<"i="<<i<<endl;
    // }
     return 0;
}