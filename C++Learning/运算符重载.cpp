#include <iostream>
using namespace std;

class CGirl
{
	friend CGirl& operator+(int score, CGirl& g);
	friend CGirl& operator+(CGirl& g, int score);
	friend CGirl& operator+(CGirl& g, CGirl& g1);
	friend void operator-(CGirl& g, int score);
private:
	int m_xw;
	int m_score;
public:
	string m_name;
	CGirl() :m_name{ "西施" }, m_score{ 30 }, m_xw{ 87 } {  }
	/*CGirl& operator+(int score);*/
	void show();
};

void CGirl::show()
{
	cout << "姓名：" << m_name << "  分数：" << m_score << " xw：" << m_xw << endl;
}

//CGirl& CGirl::operator+(int score)	// 成员函数版本的重载
//{
//	this->m_score = this->m_score + score;
//	return *this;
//}

// 如果把函数名写为 operator+ ，那么调用函数的代码可以写为 g+30  的形式
// 函数的实参书写在了运算符+的两边，代替了	operator+(g,30)

// 重载的运算符有几个参数，参数列表中就需要几个参数

CGirl& operator+( int score,CGirl& g )
{
	g.m_score = g.m_score + score;
	return g;
}

CGirl& operator+(CGirl& g, int score)
{
	g.m_score = g.m_score + score;
	return g;
}

CGirl& operator+(CGirl& g, CGirl& g1)
{
	g.m_score = g.m_score + g1.m_score;
	return g;
}

void operator-(CGirl& g, int score)
{
	g.m_score = g.m_score - score;
}

void operator+(int a, int b)
{

}
int main(void)
{
	CGirl g;
	//operator+(g,30);s
	//g=g + 20+15;
	//g = operator+(operator+(g, 20), 15);
	g = g+10+20 + g;
	g.show();
	
	g - 30;
	g.show();
}