#include <iostream>
using namespace std;


class CGirl
{
friend void addscore(CGirl& g1,int score);
// friend void operator+(CGirl& g1,int score);
friend CGirl& operator+(CGirl& g1,int score);
friend CGirl& operator-(CGirl& g1,int score);
friend CGirl& operator+(int score,CGirl& g1);
friend CGirl& operator+(CGirl& g1,CGirl& g2);
/*friend void operator*(int& a,int &b);*/  //todo:重载函数的参数列表中必须有一个用户自定义的类型（类或枚举），否则形参全为内置类型的，直接报错
private:
private:
    int m_xw;
    int m_score;
public:
    string m_name;
    CGirl();
    ~CGirl();
    void show();
    // void operator +(int score);
    // CGirl& operator-(int score);
};

CGirl::CGirl()
{
    m_name="西施";
    m_xw=87;
    m_score=30;
    cout<<"The CGirl() constructor was called. "<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}

void CGirl::show()
{
    cout<<"姓名："<<m_name<<", 胸围："<<m_xw<<"，评分："<<m_score<<endl;
}

// void CGirl::operator+(int score)
// {
//     this->m_score=this->m_score+score;
//     cout<<"The this is "<<this<<endl;
// }

// CGirl& CGirl::operator-(int score)
// {
//     this->m_score = this->m_score-score;
//     return *this;
// }

//TODO: 分数每次加30的友元全局函数
void addscore(CGirl& g1,int score)
{
    g1.m_score = g1.m_score+score;
}

// void operator+(CGirl& g1,int score) // operator+  就是函数名
// {
//     g1.m_score = g1.m_score+score;
// }

CGirl& operator-(CGirl& g1,int score) // operator-  就是函数名
{
    g1.m_score = g1.m_score-score;
    return g1;
}

CGirl& operator+(CGirl& g1,int score) // operator+  就是函数名
{
    g1.m_score = g1.m_score+score;
    return g1;
}

CGirl& operator+(int score,CGirl& g1) // operator+  就是函数名
{
    g1.m_score = g1.m_score+score;
    return g1;
}

CGirl& operator+(CGirl& g1,CGirl& g2)
{
    g1.m_score = g1.m_score+g2.m_score;
    return g1;
}

/*void operator*(int& a,int &b)
{
    a = a*b;
}*/
int main(void)
{
    CGirl g;
    cout<<"The address of g is "<<&g<<endl;
    g+30; //TODO:  本质还是调用函数，operator+(g,30);只不过C++做了特殊的处理，函数的实参写在运算符+的两边，代替了函数名和括号的传统书写方式

    // addscore(g,30);
    // operator+(g,30);
    g.show();
    // g=g-20-5-10; //TODO: 运算符重载可以连续用，本质是函数的多次调用
    //TODO： 第一次 g-20 调用operator- ,返回g。第二次，g-5 调用operator- ,返回g。第二次，g-10 调用operator- ,返回g。
    // 如果用上重载函数名,代码形式如下：
    // g = operator-(operator-(operator-(g,20),5),10);
    // g = 20+5+10+g;  //TODO: 第一次 10+g 调用operator+ ,返回g。第二次，5+g 调用operator+ ,返回g。第二次，20+g 调用operator+ ,返回g。
    g = g+20+5+10+g;  //TODO: 实质为 g+g
    g.show();
    return 0;
};