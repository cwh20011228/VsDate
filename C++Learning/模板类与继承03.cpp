//TODO: ģ����̳�ģ����

#include <iostream>
using namespace std;


//TODO: ģ����BB
template <class T1,class T2>
class BB {
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x,const T2 y):m_x{x},m_y{y} { cout << "������BB�Ĺ��캯��.\n";  }
	void func2() { cout << "������func2()����: m_x= " << m_x << ", m_y=" << m_y << endl; }
};


//TODO: ģ����AA
template <class T,class T1,class T2>
class AA :public BB<T1,T2>{
public:
	T m_a;
	AA(const T a,const T1 x,const T2 y):m_a{a},BB<T1,T2>(x,y) { cout << "������AA�Ĺ��캯��.\n"; }
	void func1() { cout << "������func1()����:m_a= " << m_a << endl; }
};


int main(void)
{
	AA<int, int, string> aa{ 3,8,"����һֻɵɵ��" };
	aa.func1();
	aa.func2();

	return 0;
}