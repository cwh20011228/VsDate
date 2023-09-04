#include <iostream>
using namespace std;

class AA {
private:
	int m_a;
	int m_b;
	double m_c;
public:
	// ��һ�������Ĺ��캯������ʼ��m_c
	AA(double c) 
	{
		m_c = c + 3;
		cout << "AA(double c)" << endl;
	}
	// �����������Ĺ��캯������ʼ�� m_a �� m_b
	AA(int a, int b)
	{
		m_a = a + 1;
		m_b = b + 2;
		cout << "AA(int a, int b)" << endl;
	}
	// ���캯��ί��AA(int a, int b)��ʼ��m_a�� m_b
	AA(int a, int b, const string& str):AA(a,b)
	{
		cout << "m_a=" << m_a << ",m_b=" << m_b << ",str=" << str << endl;
	}

	// ���캯��ί��AA(double c)��ʼ�� m_c
	AA(double c, const string& str):AA(c)
	{
		m_a = 0;
		m_b = 0;
		cout << "m_a=" << m_a << ",m_b=" << m_b<<",m_c=" << m_c << ",str=" << str << endl;
	}
};

int main(void)
{
	AA a1{ 10,20,"����һֻɵɵ��" };

	AA a2{ 3.8,"����һֻɵɵ��" };
}