#include <iostream>
using namespace std;

int main(void)
{
    typedef unsigned int u_int;
    typedef long long l_long;
    typedef unsigned long long ul_long;
    u_int a = 1024;
    l_long b = 545785;
    ul_long c = 12345689665;
    cout<<"sizeof(a)"<<sizeof(u_int)<<",a="<<a<<endl;
    cout<<"sizeof(b)"<<sizeof(l_long)<<",b="<<b<<endl;
    cout<<"sizeof(c)"<<sizeof(ul_long)<<",c="<<c<<endl;
cout<<sizeof(long);
    // TODO: 创建别名的代码放在头文件中
    // 在 windos下， short是两个字节，int 是四个字节，long是4个字节，long long 是8个字节
    // typedef short      int16_t; // 16位的整数
    // typedef int        int32_t; // 32位的整数
    // typedef long long  int64_t; // 64位的整数

    // 在 linux下， short是两个字节，int 是四个字节，long是8个字节，long long 是8个字节
    // typedef short      int16_t; // 16位的整数
    // typedef int        int32_t; // 32位的整数
    // typedef long       int64_t; // 64位的整数
    return 0;
}