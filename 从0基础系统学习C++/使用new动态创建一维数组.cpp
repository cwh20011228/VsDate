#include <iostream>
using namespace std;

int main(void)
{
    // int *array = new int[5]{1,2,3,4,5};
    // cout<<sizeof(array)<<endl;
    // for(int i=0;i<5;i++)
    // {
    //     cout<<"array["<<i<<"]="<<array[i]<<endl;
    // }
    //TODO:  声明普通数组的时候，数组长度可以用变量,相当于在栈上动态分配数组
    //TODO:如果有大量的数据，应该用堆来分配空间
    //TODO: new(std::nothrow) 如果内存不够，返回空地址nullptr ,
    // int b;
    // cin>>b;
    // int num[b]={0};
    // int *array = new int[5];
    // for(int i=0;i<5;i++)
    // {
    //     array[i]=i+100;
    //     cout<<"*(array+"<<i<<")="<<*(array+i)<<endl;
    // }
    // delete[] array;
    // array = nullptr;

    int *a=new(std::nothrow) int[100000000000001];
    
    if(a==nullptr)
        cout<<"分配内存失败.\n";
    else{
        a[100000000000000]=8;
        delete[] a;
    }
    
    return 0;
}