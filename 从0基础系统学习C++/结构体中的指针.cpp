#include <iostream>
#include <cstring>
using namespace std;

struct St
{
    int a;
    int *p;
};

struct ss{
    string name;  // string是一个类,里面有一个指针动态申请空间
};

int main(void)
{   
    int *pointer=nullptr;
    cout<<"指针的大小是"<<sizeof(pointer)<<endl;
    St stt;
    memset(&stt,0,sizeof(stt));
    stt.p=new int[100];
    cout<<"sizeof(stt)="<<sizeof(stt)<<endl;
    cout<<"调用前 stt.a="<<stt.a<<"  stt.p="<<stt.p<<endl;

    // memset(&stt,0,sizeof(stt));
    stt.a=0;  // 清空成员a
    memset(stt.p,0,sizeof(int)*100); // 清空p指向的内存中的内容
    cout<<"调用后 stt.a="<<stt.a<<"  stt.p="<<stt.p<<endl;
    //TODO: 在动态申请内存之后，使用memeset 清0，p指向的地址变为0 , 继续对其操作，就是操作空指针。指针p原来指向的内存没有被释放，产生内存泄漏。最后的结果是堆中的内存越来越少，系统越来越慢，程序也会崩溃。
    // 在没有动态申请内存之前，就可以用 memset函数清空结构体
    cout<<"--------------------------"<<endl;
    ss st;
    st.name="西施";
    cout<<"st.name="<<st.name<<endl;
    memset(&st,0,sizeof(st));
    st.name="刘小备";
    cout<<"st.name="<<st.name<<endl;
    delete [] stt.p;   // 释放动态申请的内存

    return 0;
} 