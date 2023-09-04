//! 模板类继承普通类	(常见)
//! 普通类继承模板类的示例版本（把模板类的通用类型参数指定了）
//! 普通类继承模板类	(常见)
//! 模板类继承模板类
//! 模板类继承模板参数给出的基类(不能是模板类)


#include <iostream>
using namespace std;

//!? 模板类继承普通类（在派生类的构造函数中初始化列表中显示调用基类构造函数）
//TODO: 普通类AA
class AA {
public:
	int m_a;
	//AA() { }
	AA(int a) :m_a{ a } { cout << "调用了AA的构造函数.\n"; }
	void func1() { cout<<"调用了func1()函数:m_a= "<<m_a << endl; }
};


//TODO: 模板类BB
template <class T1,class T2>
class BB :public AA{
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x,const T2 y,int a):m_x{x},m_y{y},AA(a) { cout << "调用了BB的构造函数.\n"; }
	void func2() { cout << "调用了func2()函数: m_x= " << m_x<<", m_y="<<m_y << endl; }
};


int main(void)
{
	BB<int, string> bb{8,"我是一只傻傻鸟",3};
	bb.func2();
	bb.func1();

	return 0;
}