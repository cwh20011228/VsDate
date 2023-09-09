#include <iostream>
using namespace std;

class CGirl
{
    friend ostream &operator<<(std::ostream &cout, const CGirl &g1);

private:
    string m_name;
    int m_xw;
    int m_score;

public:
    CGirl();
    ~CGirl();
    void show() const;
};

CGirl::CGirl()
{
    m_name = "西施";
    m_score = 30;
    m_xw = 87;
    cout << "The CGirl() constructor was called." << endl;
}

CGirl::~CGirl()
{
    cout << "The ~CGirl() destructor was called." << endl;
}

void CGirl::show() const
{
    cout << "姓名：" << m_name << "，胸围：" << m_xw << "，评分：" << m_score << endl;
    // TODO: 上面一行实质是多次调用了重载函数。第一次调用的时候，参数是cout对象和 "姓名：" ，函数输出"姓名"后，返回cout对象
    // TODO：第二次调用的输后，函数的两个实参是 cout对象和 m_name ,输出 m_name后，返回值是cout对象
}

ostream &operator<<(std::ostream &cout, const CGirl &g1)
{
    // g1.show();
    cout << "姓名：" << g1.m_name << "，胸围：" << g1.m_xw << "，评分：" << g1.m_score << endl;
    return cout; //TODO: 返回值必须是ostream的对象
}

int main(void)
{
    CGirl g;
    cout << g ;
    return 0;
}