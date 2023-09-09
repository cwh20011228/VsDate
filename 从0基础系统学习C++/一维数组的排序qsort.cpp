#include <iostream>
using namespace std;

int compasc(const void *p1, const void *p2)
{
    // if(*((int*)p1) <  *((int*)p2)) return -1;
    // if(*((int*)p1) == *((int*)p2)) return  0;
    // if(*((int*)p1) >  *((int*)p2)) return  1;
    return *((int*)p1) - *((int*)p2);  // 优化
}
/*  qsort() c++的函数，用于对各种数据类型的数组进行排序。
    原型： void qsort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *));
    base: 数组的起始地址
    nmemb： 数组元素的个数（数组长度）
    size： 数组元素的大小 sizeof(数组的数据类型)
    compar: 回调函数的地址
*/

int compdesc(const void *p1, const void *p2)
{
    return  *((int*)p2)-*((int*)p1);
}

int main(void)
{
    int a[8] = {4,2,7,5,8,6,1,3};

    qsort(a,sizeof(a)/sizeof(int),sizeof(int),compasc); // 对数组a升序

    for(int i=0;i<8;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    cout<<endl;
    qsort(a,sizeof(a)/sizeof(int),sizeof(int),compdesc); // 对数组a降序

    for(int i=0;i<8;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    return 0;
}