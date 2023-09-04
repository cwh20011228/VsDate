#include <iostream>
using namespace std;

//TODO: 利用模板类的参数，自动生成友元函数
template <class T1,class T2>
class AA {
	//friend void show(const AA<char, string>& a);
private:
	T1 m_x;
	T2 m_y;
public:
	AA(const T1 x,const T2 y):m_x{x},m_y{y} { }
	//TODO: 非模板友元：友元函数不是模板函数，而是利用模板类生成的函数，只能在类内实现。
	friend void show(const AA<T1, T2>& a)
	{
		cout << "x=" << a.m_x << "   y=" << a.m_y << endl;
	}
};



int main(void)
{
	AA<int, string> aa(88, "我是一只傻傻鸟");
	show(aa);

	AA<char, string> bb(88, "我是一只傻傻鸟");
	show(bb);

	return 0;
}