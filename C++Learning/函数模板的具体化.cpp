#include <iostream>
using namespace std;

//! 可以提供一个具体化的函数定义，当编译器找到与函数调用匹配的具体化定义时，将使用该定义，不再寻找模板
//! 函数模板通用版本之外的一个特殊版本
//! 不管是函数模板还是具体化函数，他们的声明和定义可以分开
//! 对于一个普通函数名，可以有普通函数，函数模板，具体化的函数模板，以及他们的重载版本

template <typename T>
void Swap(T& a, T& b);	// 函数模板的声明
//{
//	T temp = a;
//	a = b;
//	b = temp;
//	cout << "调用了Swap(T& a,T& b)" << endl;
//}

class CGirl {
public:
	int m_bh;
	string m_name;
	int m_ranking;
};

// 为Swap函数模板写一个具体的函数，专用于超女数据类型，功能是交换两个超女对象中的排名成员m_ranking
//! template<> 具体化函数声明;
//! 具体化函数的 返回值，函数名和形参列表与函数模板相同
//! 对具体化函数来说，不管函数声明，还是函数体的定义，都是具体化的数据类型，没有通用的数据类型

template<> void Swap<CGirl>(CGirl& g1, CGirl& g2);		//	具体化函数的声明
//template<> void Swap(CGirl& g1, CGirl& g2)	// 交换两个超女对象的排名
//{
//	int temp = g1.m_ranking;
//	g1.m_ranking = g2.m_ranking;
//	g2.m_ranking = temp;
//	cout << "调用了Swap(CGirl& g1, CGirl& g2)" << endl;
//}

int main(void)
{
	int a = 10, b = 20;
	Swap(a, b);
	cout << "a=" << a << "     b=" << b << endl;

	CGirl g1, g2;
	
	g1.m_ranking = 1;
	g2.m_ranking = 2;
	Swap(g1, g2);
	cout << "g1.m_ranking=" << g1.m_ranking << "    g2.m_ranking=" << g2.m_ranking << endl;
	//!  编译器根据实参类型，如果能与具体化函数匹配上，会优先使用具体化函数
	
	return 0;
}


template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
	cout << "调用了Swap(T& a,T& b)" << endl;
}

template<> void Swap<CGirl>(CGirl& g1, CGirl& g2)
//template<> void Swap(CGirl& g1, CGirl& g2)	// 交换两个超女对象的排名
{
	int temp = g1.m_ranking;
	g1.m_ranking = g2.m_ranking;
	g2.m_ranking = temp;
	cout << "调用了Swap(CGirl& g1, CGirl& g2)" << endl;
}