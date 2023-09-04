#include <iostream>
using namespace std;

//TODO: 约束模板友元：模板实例化时，每个实例化的类对应一个友元函数(可以具体化，支持多个模板类)
template <typename T>
void show(T& a);		//! （1）在模板类的定义前面，声明友元函数模板

template <class T1,class T2>
class AA {
	friend void show<>(AA<T1, T2>& a);	
	//! (2) 在类模板中，再次声明友元函数模板，让类模板知道实例化的友元函数模板
private:
	T1 m_x;
	T2 m_y;
public:
	AA(const T1 x,const T2 y):m_x{x},m_y{y} { }

};

template <class T1, class T2>
class BB {
	friend void show<>(BB<T1, T2>& a);
	//! (2) 在类模板中，再次声明友元函数模板，让类模板知道实例化的友元函数模板
private:
	T1 m_x;
	T2 m_y;
public:
	BB(const T1 x, const T2 y) :m_x{ x }, m_y{ y } { }

};


template <typename T>
void show(T& a)			//! （2）友元函数模板的定义,可以用于多个模板类
{
	cout << "x=" << a.m_x << "   y=" << a.m_y << endl;
}


template <> 
void show(AA<int, string>& a)
{
	cout << "函数模板的具体化 x=" << a.m_x << "   y=" << a.m_y << endl;
}

template <>
void show(BB<int, string>& a)
{
	cout << "函数模板的具体化 x=" << a.m_x << "   y=" << a.m_y << endl;
}

int main(void)
{
	AA<int, string> a(88, "我是一只傻傻鸟");
	show(a);

	AA<char, string> b(88, "我是一只傻傻鸟");
	show(b);


	BB<int, string> bb(77, "我是一只傻傻鸟");
	show(bb);

	BB<char, string> bbb(77, "我是一只傻傻鸟");
	show(bbb);
	return 0;
}