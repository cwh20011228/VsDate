//! 模板类具体化（特化，特例化）有两种：完全具体化和部分具体化
//! 具体化程度高的类优于具体化程度低的类，具体化的类优先于没有具体化的类

#include <iostream>
using namespace std;

template <class T1,class T2>
class AA {
public:
	T1 m_x;
	T2 m_y;
	AA(const T1 x, const T2 y) :m_x{ x }, m_y{ y }
	{
		cout << "类模板：构造函数。\n";
	}

	void show() const;
};

template <class T1,class T2>
void AA<T1, T2>::show() const 
{
	cout << "类模板：x= " << m_x << "  ,y= " << m_y << endl;
}


//TODO: 类模板完全具体化

template<>
class AA<int, string> {
public:
	int m_x;
	string m_y;

	AA(const int x, const string y) :m_x{ x }, m_y{ y }
	{
		cout << "完全具体化：构造函数.\n";
	}

	void show() const;
};


void AA<int, string>::show() const
{
	cout << "完全具体化类模板：x= " << m_x << "  ,y= " << m_y << endl;
}


//TODO: 类模板部分显示具体化

template<class T1>
class AA<T1, string> {
public:
	T1 m_x;
	string m_y;

	AA(const T1 x, const string y) :m_x{ x }, m_y{ y }
	{
		cout << "部分具体化：构造函数.\n";
	}

	void show() const;
};

template<class T>
void AA<T, string>::show() const
{
	cout << "部分具体化类模板：x= " << m_x << "  ,y= " << m_y << endl;
}


int main(void)
{
	AA<int, string> aa{ 8,"我是一只傻傻鸟" };
	aa.show();

	return 0;
}