#include <iostream>
using namespace std;

class AA {
public:
	int m_a;
	int m_b;

	AA(int a) :m_a(a) { cout << "AA(int a)" << endl; }
	AA(int a, int b) :m_a(a), m_b(b) { cout << "AA(int a,int b)" << endl; }
};

class BB :public AA {
public:
	double m_c;
	using AA::AA;	// ʹ�û���Ĺ��캯��
	BB(int a, int b, double c) :AA(a, b), m_c(c) { cout << "BB(int a,int b,double c)" << endl; }
	void show() { cout << "m_a=" << m_a << ",m_b=" << m_b << ",m_c=" << m_c << endl; }
};

int main(void)
{
	BB b1(10);	// ��ʹ�û�����һ�������Ĺ��캯��������ʼ��m_a
	b1.show();

	BB b2(10,20);	// ��ʹ�û��������������Ĺ��캯��������ʼ��m_a,m_b
	b2.show();

	BB b3(10,20,3.56);	// ��ʹ�������������������Ĺ��캯��������ʼ��m_a,m_b,m_c
	b3.show();
}