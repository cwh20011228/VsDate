#include <iostream>
#include <cstring>
using namespace std;

class CGirl{
    public:
        string m_name;
        int m_age;
        int *m_ptr;
    CGirl();
    CGirl(string name,int age);
    // CGirl(string name,int age,int *ptr);
    CGirl(const CGirl& g0); // 默认的拷贝构造函数
    CGirl(const CGirl& g0,int ii);
    ~CGirl();
    void show();
};

CGirl::CGirl()
{
    m_name.clear();
    m_age=0;
    m_ptr=nullptr;
    cout<<"The CGirl() constructor was called."<<endl;
}

CGirl::CGirl(string name,int age)
{
    m_name=name;
    m_age=age;
    m_ptr=nullptr;
    cout<<"The CGirl(string name,int age) constructor was called."<<endl;
}

CGirl::CGirl(const CGirl& g0)
{
    m_name = g0.m_name;
    m_age=g0.m_age;
    m_ptr=new int; // 分配内存
    *m_ptr = *g0.m_ptr; // 拷贝数据
    //TODO： memcpy(m_ptr,g0.m_ptr,sizeof(int));  复杂一点的用memcpy
    cout<<"The CGirl(const CGirl&) Copy constructor was called"<<endl;
}

CGirl::CGirl(const CGirl& g0,int ii)
{
    m_name = g0.m_name;
    m_age=g0.m_age;
    m_ptr=g0.m_ptr;
    cout<<"The CGirl(const CGirl&,int ii) Copy constructor was called"<<endl;
}
CGirl::~CGirl()
{
    if(m_ptr!=nullptr)
    {
        delete m_ptr;
        m_ptr=nullptr;
    }
    cout<<"The ~CGirl() destructor was called."<<endl;
}

void CGirl::show()
{
    cout<<"name="<<m_name<<"  age="<<m_age<<"  m_ptr="<<m_ptr<<"  *m_ptr="<<*m_ptr<<endl;
}
/* 
TODO:   对空指针解引用 *p   (p=nullptr)  是非法的
浅拷贝造成了程序的崩溃，引起堆区数据的混乱（类中的指针指向同一数据区）
TODO: 深拷贝：指针A指向一块内存，那么就重新分配一块相同大小的内存，让指针B指向新内存，然后再把指针A指向的内存中的数据拷贝到新内存中。这种拷贝的方法很彻底，在拷贝后，大家各自操作自己的指针和内存
编译器提供的拷贝构造函数是浅拷贝
深拷贝有两个步骤：1.分配内存   2. 拷贝数据
*/
int main(void)
{
    CGirl g1("Smith",25);
    g1.m_ptr= new int(3); // 只有一个对象销毁成功（g2）,g1销毁的时候，m_ptr成为了野指针，程序崩溃，只调用了一次destructor
    g1.show(); 
    CGirl g2(g1);
    *g2.m_ptr=8;
    g1.show();
    g2.show();
    return 0;
}