#include <iostream>
using namespace std;
// 在这个程序中，operator new  和 operator delete  是全局函数，将接管全部new和delete分配内存的工作。
void* operator new(size_t size)  // 参数必须是size_t,返回值必须是void*  ,   size_t    -->   unsigned long long
{
    cout<<"调用了全局重载的new:"<<size<<"字节。\n";
    void *ptr = malloc(size); // 申请内存   ，ptr就指向分配内存的起始地址。如果申请失败，返回null
    cout<<"申请到的内存的起始地址是："<<ptr<<endl;
    return ptr;  // 返回分配的这块内存的起始地址，因为通过这个地址可以找到这块内存，所以返回值必须是  void*
}


void operator delete(void* ptr) //  参数必须是void*，返回值必须是 void
{
    cout<<"调用了全局重载的delete.\n";
    if(ptr==nullptr)  return ;  // 对空指针delete是安全的
    free(ptr);  // 释放内存
}

//TODO： 如果为类重载new和delete函数，作用的范围将是类，而不是全局
class CGirl 
{
public:
    int m_bh;
    int m_xw;
    CGirl(int bh,int xw);
    ~CGirl();
    void* operator new(size_t size);
    void operator delete(void* ptr);
};

CGirl::CGirl(int bh,int xw):m_bh(bh),m_xw(xw)
{
    cout<<"The CGirl(int ,int ) constructor was called."<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}
//TODO: 为类创建的重载new和delete,默认是staic 成员函数，只能调用static成员 
void* CGirl::operator new(size_t size)  // 参数必须是size_t,返回值必须是void*  ,   size_t    -->   unsigned long long
{
    cout<<"调用了类的重载的new:"<<size<<"字节。\n";
    void *ptr = malloc(size); // 申请内存   ，ptr就指向分配内存的起始地址。如果申请失败，返回null
    cout<<"申请到的内存的起始地址是："<<ptr<<endl;
    return ptr;  // 返回分配的这块内存的起始地址，因为通过这个地址可以找到这块内存，所以返回值必须是  void*
}


void CGirl::operator delete(void* ptr) //  参数必须是void*，返回值必须是 void
{
    cout<<"调用了类的重载的delete.\n";
    if(ptr==nullptr)  return ;  // 对空指针delete是安全的
    free(ptr);  // 释放内存
}


int main(void)
{
    int *p1 = new int(3); // 声明整型指针p1 ,指向用new分配的内存 ,内存中的值是3
    cout<<"p1="<<(void*)p1<<"  *p1="<<*p1<<endl;
    delete p1;

    cout<<endl;

    CGirl* g=new CGirl(25,36);
    cout<<"The address of g is "<<g<<"     m_bh="<<g->m_bh<<"     m_xw="<<g->m_xw<<endl; 
    delete g;
    return 0;

    // int *l  = new int[5];
    // delete[] l;
}