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
		cout << "�����˻����Ĭ�Ϲ��캯��A()." << endl;
	}
	A(int a, int b) :m_a{ a }, m_b{ b }
	{
		cout << "�����˻���Ĺ��캯��A(int a, int b)." << endl;
	}
	A(const A& a) :m_a{ a.m_a + 1 }, m_b{ a.m_b + 1 }
	{
		cout << "�����˻���Ŀ������캯��A(const A& a)." << endl;
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
		cout << "�������������Ĭ�Ϲ��캯��B()." << endl;
	}
	B(int a, int b,int c) :m_c{ c }, A(),m_d(a,b)
	{
		cout << "������������Ĺ��캯��B(int a, int b,int c)." << endl;
	}
	B(const A& a, int c) :A{ a }, m_c{ c },m_d(c,c)
	{
		cout << "������������Ĺ��캯��B(const A& a, int c)." << endl;
	}
	void showB()
	{
		cout << "m_c=" << m_c << endl;
	}
};

// ����ļ̳��У���һ��ԭ�򣺻���ĳ�Ա�����ɻ���Ĺ��캯����ʼ���������������ĳ�Ա������������Ĺ��캯����ʼ��

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