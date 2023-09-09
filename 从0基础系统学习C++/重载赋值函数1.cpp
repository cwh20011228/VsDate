#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    int *m_ptr; // 准备使用堆空间
    void show();
    CGirl();
    ~CGirl();
    CGirl &operator=(const CGirl &g0);
};

CGirl::CGirl()
{
    m_ptr = nullptr;
    cout << "The CGirl() constructor was called." << endl;
}

CGirl::~CGirl()
{
    if (m_ptr)
        delete m_ptr;
    cout << "The ~CGirl() destructor was called." << endl;
}

void CGirl::show()
{
    // 如果m_ptr=nullptr , 那么 *m_ptr会出错，
    cout << "bh=" << m_bh << "   name=" << m_name << /*"  *m_ptr=" << *m_ptr << */"  m_ptr=" << m_ptr << endl;
}

//TODO: 深拷贝
// 重载赋值运算符,返回值是CGirl& ，目的是 可以连续调用 ， g1=g2=g3=g4;
CGirl &CGirl::operator=(const CGirl &g0)
{
    //TODO： g0是源对象，*this是目标对象   g1=g0;   源对象：g0    目标对象：g1
    if (this != &g0)
    {
        if (g0.m_ptr == nullptr) // 如果源对象的指针为空，则清空目标对象的内存和指针
        {
            if (this->m_ptr != nullptr)
            {
                delete this->m_ptr;
                this->m_ptr = nullptr;
            }
        }
        else // 如果源对象的指针不为空
        {
            // 如果目标对象的指针为空。先分配内存
            if (this->m_ptr == nullptr)
                this->m_ptr = new int;
            //  然后，把源对象内存中的数据复制到目标对象的内存中
            memcpy(this->m_ptr, g0.m_ptr, sizeof(int));
        }
        this->m_bh = g0.m_bh;
        this->m_name = g0.m_name;
        cout << "The operator=(const CGirl& g0) overload function was called." << endl;
        return *this;
    }
    return *this;
}

int main(void)
{
    CGirl g1, g2;
    g1.m_bh = 8;
    g1.m_name = "西施";
    g1.m_ptr=new int(3);
    g1.show();
    g2.show();

    g2=g1;
    g2.show();
    cout<<"*g1.m_ptr="<<*g1.m_ptr<<"   *g2.m_ptr="<<*g2.m_ptr<<endl;
    return 0;
}