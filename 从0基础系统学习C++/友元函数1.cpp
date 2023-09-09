#include <iostream>
using namespace std;
// 将CBoy的func1函数声明为CGirl的友元函数
// TODO： (1) CGirl类的声明前置 (2)CBoy的定义放在CGril的定义之前 （3）把CBoy的成员函数的函数体从类的定义中拿出来，放在定义CGirl类的后面
// TODO： (4)把CBoy类的成员函数声明为CGirl类的友元函数

class CGirl; // TODO： CGirl类的前向声明
class CBoy
{
public:
    void func1(const CGirl &g);
    void func2(const CGirl &g);
};



class CGirl
{
    friend void CBoy::func1(const CGirl &g);
    // friend void CBoy::func2(const CGirl &g);

public:
    string m_name;
    CGirl();
    ~CGirl();
    void showname();

private:
    int m_xw;
    void showxw() const;
};

CGirl::CGirl()
{
    m_name = "西施";
    m_xw = 87;
    cout << "The CGir() constructor was called." << endl;
}

CGirl::~CGirl()
{
    cout << "The ~CGir() destructor was called." << endl;
}

void CGirl::showname()
{
    cout << "姓名：" << m_name << endl;
}

void CGirl::showxw() const
{
    cout << "胸围：" << m_xw << endl;
}

// 常对象只能访问const约束的成员
void CBoy::func1(const CGirl &g)
{
    cout << "女朋友的xw是：" << g.m_xw << endl;
}

void CBoy::func2(const CGirl &g)
{
    cout << "女朋友的姓名是：" << g.m_name << endl;
}

int main(void)
{
    CGirl g;
    CBoy b;
    b.func1(g);
    b.func2(g);
    return 0;
}