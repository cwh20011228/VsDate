#include <iostream>
using namespace std;

class A {
public:
	int m_a;
private:
	int m_b;
public:
	A() : m_a(0), m_b(0)
	{
		cout << "调用了基类的默认构造函数A()." << endl;
	}
	A(int a, int b) :m_a{ a }, m_b{ b }
	{
		cout << "调用了基类的构造函数A(int a, int b)." << endl;
	}
	A(const A& a) :m_a{ a.m_a + 1 }, m_b{ a.m_b + 1 }
	{
		cout << "调用了基类的拷贝构造函数A(const A& a)." << endl;
	}

	void showA()
	{
		cout << "m_a=" << m_a << ",m_b=" << m_b << endl;
	}
};

class B :public A {
public:
	int m_c;
	A m_d;
	B() :m_c{ 0 },m_d()
	{
		cout << "调用了派生类的默认构造函数B()." << endl;
	}
	B(int a, int b,int c) :m_c{ c }, A(),m_d(a,b)
	{
		cout << "调用了派生类的构造函数B(int a, int b,int c)." << endl;
	}
	B(const A& a, int c) :A{ a }, m_c{ c },m_d(c,c)
	{
		cout << "调用了派生类的构造函数B(const A& a, int c)." << endl;
	}
	void showB()
	{
		cout << "m_c=" << m_c << endl;
	}
};

// 在类的继承中，有一个原则：基类的成员变量由基类的构造函数初始化，派生类新增的成员变量由派生类的构造函数初始化

int main(void)
{
	B b1;
	b1.showA();
	b1.showB();

	cout << endl;

	B b2(1, 2, 3);
	b2.showA();
	b2.showB();

	A a{ 10,20 };
	B b3{ a,30 };
	b3.showA();
	b3.showB();

	return 0;
}