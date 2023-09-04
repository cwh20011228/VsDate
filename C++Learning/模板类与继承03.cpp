//TODO: 模板类继承模板类

#include <iostream>
using namespace std;


//TODO: 模板类BB
template <class T1,class T2>
class BB {
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x,const T2 y):m_x{x},m_y{y} { cout << "调用了BB的构造函数.\n";  }
	void func2() { cout << "调用了func2()函数: m_x= " << m_x << ", m_y=" << m_y << endl; }
};


//TODO: 模板类AA
template <class T,class T1,class T2>
class AA :public BB<T1,T2>{
public:
	T m_a;
	AA(const T a,const T1 x,const T2 y):m_a{a},BB<T1,T2>(x,y) { cout << "调用了AA的构造函数.\n"; }
	void func1() { cout << "调用了func1()函数:m_a= " << m_a << endl; }
};


int main(void)
{
	AA<int, int, string> aa{ 3,8,"我是一只傻傻鸟" };
	aa.func1();
	aa.func2();

	return 0;
}