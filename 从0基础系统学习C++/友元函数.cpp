#include <iostream>
using namespace std;

class CGirl
{
    // friend class CBoy;
    friend void func();
    friend int main();
    //TODO： 把main()函数声明为CGirl类的友元函数,声明友元的代码放在类的什么地方都可以，不受public和private关键字的约束，一般放在最上面
    // 在mian函数中就可以访问CGirl的私有成员
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

void func()
{
    CGirl g;
    g.showname();
    g.showxw();
}

// class CBoy
// {
// public:
//     void func1(const CGirl &g);
// };

// 常对象只能访问const约束的成员
// void CBoy::func1(const CGirl &g)
// {
//     cout << "女朋友的姓名是：" << g.m_name << endl;
//     cout << "女朋友的xw是：" << g.m_xw << endl;
//     g.showxw();
// }

// 友元成员函数，可以访问另一个类的所有成员。注意声明和定义的顺序
int main(void)
{
    func();
    CGirl g;
    g.showname();
    g.showxw();

    // CGirl g;
    // CBoy b;
    // b.func1(g);

    return 0;
}