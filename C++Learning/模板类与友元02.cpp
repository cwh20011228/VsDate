#include <iostream>
using namespace std;
// TODO: 非约束模板友元：模板类实例化时，如果实例化了n个类，也会实例化n个友元函数，每个实例化的类都拥有n个友元函数
template <class T1,class T2>
class AA {
	template <typename T> friend void show(T& a);
private:
	T1 m_x;
	T2 m_y;
public:
	AA(const T1 x,const T2 y):m_x{x},m_y{y}  { }
 };

template <typename T> void show(T& a)
{
	cout << "x=" << a.m_x << "   y=" << a.m_y << endl;
}

template<>
void show(AA<int, string>& a)
{
	cout << "具体化 x=" << a.m_x << "   y=" << a.m_y << endl;
}


int main(void)
{
	AA<int, string> a(88, "我是一只傻傻鸟");
	show(a);

	AA<char, string> a1(88, "我是一只傻傻鸟");
	show(a1);


	return 0;
}