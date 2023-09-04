#include <iostream>
using namespace std;

class A {
public:
	int m_a = 10;
	void func() { cout << "调用了A的func（）函数" << endl; }
	void func(int a) { cout << "调用了A的func（int a）函数" << endl; m_a = a; }
};

class B :public A {
public:
	int m_a = 20;
	void func() { cout << "调用了B的func（）函数" << endl; }
	
};

class C :public B {
public:
	int m_a = 30;
	void func() { cout << "调用了C的func（）函数" << endl; }
};
int main(void)
{
	C c;
	cout << "C::m_a=" << c.C::m_a << endl;
	cout << "B::m_a=" << c.B::m_a << endl;
	cout << "A::m_a=" << c.B::A::m_a << endl;
	c.C::func();
	c.B::func();
	c.B::A::func();
	return 0;
}

