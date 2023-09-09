#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    void show();
    // CGirl();
    // ~CGirl();
    CGirl &operator=(const CGirl &g0);
};

// CGirl::CGirl()
// {
//     cout<<"The CGirl() constructor was called."<<endl;
// }

// CGirl::~CGirl()
// {
//     cout<<"The ~CGirl() destructor was called."<<endl;
// }

void CGirl::show()
{
    cout << "bh=" << m_bh << "   name=" << m_name << endl;
}

// 重载赋值运算符,返回值是CGirl& ，目的是 可以连续调用 ， g1=g2=g3=g4;
CGirl &CGirl::operator=(const CGirl &g0)
{   // 重载的赋值运算符和编译器提供的默认赋值函数是一样的 
    if (this != &g0)
    {
        this->m_bh = g0.m_bh;
        this->m_name = g0.m_name;
        cout << "The operator=(const CGirl& g0) overload function was called." << endl;
        return *this;
    }
    return *this;
}

int main(void)
{
    CGirl g1, g2,g3;
    g1.m_bh = 8;
    g1.m_name = "西施";
    g1.show();
    g2.show();
    // TODO: 赋值语句中，如果两个参数相同，就没必要执行函数了， g1=g1 , 所以应该在函数中判断 = 两边是不是同一个对象
    g2 =g3= g1; // TODO:(对象的赋值是多对多的关系，但也是一一对应)相当于： g2.m_bh = g1.m_bh;   g2.m_name = g1.m_name;
    // first, g3 = g1 ; 返回值是g3;
    // second,  g2= g3;  反回值是g2;
    g2.show();
    g3.show();
    g1=g1;
    return 0;
}