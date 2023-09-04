#include <iostream>
using namespace std;

class AA {
private:
	int m_a;
	int m_b;
	double m_c;
public:
	// 有一个参数的构造函数，初始化m_c
	AA(double c) 
	{
		m_c = c + 3;
		cout << "AA(double c)" << endl;
	}
	// 有两个参数的构造函数，初始化 m_a 和 m_b
	AA(int a, int b)
	{
		m_a = a + 1;
		m_b = b + 2;
		cout << "AA(int a, int b)" << endl;
	}
	// 构造函数委托AA(int a, int b)初始化m_a和 m_b
	AA(int a, int b, const string& str):AA(a,b)
	{
		cout << "m_a=" << m_a << ",m_b=" << m_b << ",str=" << str << endl;
	}

	// 构造函数委托AA(double c)初始化 m_c
	AA(double c, const string& str):AA(c)
	{
		m_a = 0;
		m_b = 0;
		cout << "m_a=" << m_a << ",m_b=" << m_b<<",m_c=" << m_c << ",str=" << str << endl;
	}
};

int main(void)
{
	AA a1{ 10,20,"我是一只傻傻鸟" };

	AA a2{ 3.8,"我是一只傻傻鸟" };
}