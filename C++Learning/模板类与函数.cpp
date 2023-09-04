#include <iostream>
using namespace std;

//! 模板类可以用于函数和返回值，有三种形式：
//! （1）普通函数，参数和返回值是模板类的实例化版本
//! （2）函数模板，参数和返回值是某种的模板类
//! （3）函数模板，参数和返回值是任意类型（支持普通类和模板类和其他类型）

template <class T1,class T2>
class AA {
public:
	T1 m_x;
	T2 m_y;
	AA(const T1 x,const T2 y):m_x{x},m_y{y} { }
	void show() const { cout << "show()  x=" << m_x << "  y=" << m_y << endl; }
};

class BB {
public:
	void show() { cout << "调用了BB()的show()方法" << endl; }
};

// 普通函数，参数和返回值是模板类AA的实例化版本
AA<int,string> func(AA<int,string>& aa)
{
	aa.show();
	cout << "调用了func(AA<int,string>& aa)函数" << endl;
	return aa;
}

// (1)函数模板，参数和返回值是模板类AA
template <typename T1,typename T2>
AA<T1, T2> func(AA<T1, T2>& aa)
{
	aa.show();
	cout << "调用了func(AA<T1, T2>& aa)函数" << endl;
	return aa;
}


// (2)函数模板，参数和返回值是模板类AA，
template <typename T>
T func(T& aa)
{
	aa.show();
	cout << "调用了func(T& aa)函数" << endl;
	return aa;
}

//TODO: （1）的优先级比(2)高，但是（1）只支持AA这一模板，（2）支持任意模板类，普通类也支持

int  main(void)
{
	AA<int, string> a('x', "我是一只傻傻鸟");
	func(a);

	BB b;
	func(b);
	return 0;
}


