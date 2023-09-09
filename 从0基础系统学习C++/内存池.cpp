//TODO: 在实际开发中，重载new & delete 运算符的主要目的是实现内存池
// 内存池是预先分配的内存空间。程序启动的时候，先向系统申请一大块连续的空间，在程序中，如果需要使用内存，从内存池中借一小块空间，用完了就还回去  
// 如果没有内存池，就向系统借。如果有内存池，就向内存池借。持续在运行的时候，如果内存池太小了，可以扩展，但是，有一个原则，每次都会向系统申请一大块连续的空间
// 使用内存池的目的主要有两个：（1)提升分配和归还的速度，对于高性能的服务程序来说，频繁的new 和 delete也浪费时间 (2) 减少内存碎片，碎片多了系统管理内存的效率就会下降，系统的性能也会下降
// 对于内存池来说，一般采用成员函数版本，没必要采用全局函数。

#include <iostream>
#include <cstring>
using namespace std;

class CGirl
{
public:
    int m_bh;
    int m_xw;
    //TODO： 内存池需要一个指针，存放它的起始地址。内存池就是一块地址，没有数据类型的说法，用什么类型的指针都可以
    static char* m_pool; // 内存池的起始地址。用字符型指针更合适在这个程序中，因为子符加1就是偏移一个字节
    CGirl(int bh,int xw);
    ~CGirl();
    void* operator new(size_t size);  // 默认为静态成员函数
    void operator delete(void* ptr);    // 默认为静态成员函数
    static bool initpool(); // 初始化内存池的函数
    static void freepool(); // 释放内存池的函数
};



CGirl::CGirl(int bh,int xw):m_bh(bh),m_xw(xw)
{
    cout<<"The CGirl(int ,int) constructor was called."<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}

// 内存池只有两个位置，判断标志位，那个空闲就返回哪一块。如果没有空闲的位置，可以返回空地址，也可以直接向系统申请内存
void* CGirl::operator new(size_t size)  //向内存池申请内存
{
    if(m_pool[0]==0)    // 判断第一个位置是否空闲
    {
        cout<<"分配了第一块内存："<<(void*)(m_pool+1)<<endl;
        m_pool[0]=1;   // 将标志位置1 ，说明已分配占用了
        return m_pool+1;    // 返回第一个用于存放对象的地址
    }
    if(m_pool[9]==0)    // 判断第二个位置是否空闲
    {
        cout<<"分配了第二块内存："<<(void*)(m_pool+9)<<endl;
        m_pool[9]=1;   // 将标志位置1 ，说明已分配占用了
        return m_pool+9;    // 返回第二个用于存放对象的地址
    }

//TODO: 如果内存池用完了，一般有三种处理方法：（1）扩展内存池 （2）直接向系统申请内存 （3）返回空地址
    // 如果以上两个位置都不可用，那就直接系统申请内存

    void* ptr = malloc(size); // 申请内存
    cout<<"申请的系统内存的起始地址是:"<<(void*)ptr<<endl;
    return ptr;
}

void CGirl::operator delete(void* ptr)
{
    if(ptr==0) return;   //如果传进来的地址为空，直接返回

    if(ptr==(m_pool+1))     // 如果传进来的地址是内存池的第一个位置
    {
        cout<<"释放了第一块内存.\n";
        m_pool[0]=0;        // 将第一个位置（标志位）标记为空闲
        return;  // 归还内存后，函数应该立即返回
    }

    if(ptr==(m_pool+9))     // 如果传进来的地址是内存池的第二个位置
    {
        cout<<"释放了第二块内存.\n";
        m_pool[9]=0;        // 将第二个位置（标志位）标记为空闲
        return;  // 归还内存后，函数应该立即返回
    }

    //  如果传进来的地址不属于内存池，把它归还给系统
    free(ptr);
}

bool CGirl::initpool()
{
    m_pool = (char*) malloc(18);  // 向系统申请18字节的内存
    if(m_pool==0) return false; // 如果申请内存失败，返回false
    memset(m_pool,0,18); // 把内存池中的内存初始化为0 (调用memset时，需要加 #include <cstring> 头文件)
    cout<<"内存池的起始地址是："<<(void*)m_pool<<endl;
    return true;
}

void CGirl::freepool()
{
    if(m_pool==0) return ; // 如果内存池为空，不需要释放，直接返回
    free(m_pool);  // 把内存池归还给系统
    cout<<"内存池已释放\n";
}

// 向系统申请连续的18字节的内存空间。 0 ，9 是标志位，1字节，表示后面的空间是否被占用 。后面8个字节刚好存放一个超女对象。 0 表示空闲  1 表示占用
// 18字节的内存池只能存放两个超女对象。当需要为超女对象分配内存的时候，先判断标志位是否被占用，如果没有被占用，就把标志位后面这个内存的地址返回

char* CGirl::m_pool = 0;  //初始化类的静态成员 m_pool ，（在main函数的外面初始化）

int main(void)
{
    // 初始化内存池
    if(CGirl::initpool()==false) {cout<<"初始化内存池失败。\n"; return -1;}

    CGirl *p1=new CGirl(3,8);   //TODO: 将使用内存池的第一个位置
    cout<<"p1的地址是："<<p1<<"  编号："<<p1->m_bh<<"，胸围："<<p1->m_xw<<endl;

    CGirl *p2=new CGirl(4,7);   //TODO: 将使用内存池的第二个位置
    cout<<"p2的地址是："<<p2<<"  编号："<<p2->m_bh<<"，胸围："<<p2->m_xw<<endl;

    CGirl *p3=new CGirl(6,9);   //TODO：将使用系统的内存
    cout<<"p3的地址是："<<p3<<"  编号："<<p3->m_bh<<"，胸围："<<p3->m_xw<<endl;

    delete p1;      // TODO：将释放内存池的第一个位置

    CGirl *p4=new CGirl(5,3);   //TODO: 将使用内存池的第一个位置
    cout<<"p4的地址是："<<p4<<"  编号："<<p4->m_bh<<"，胸围："<<p4->m_xw<<endl;

    delete p2;      // TODO：将释放内存池的第二个位置
    delete p3;      // TODO：将释放系统的内存
    delete p4;      // TODO：将释放内存池的第一个位置

    CGirl::freepool();  //TODO： 释放内存池
    return 0;
}