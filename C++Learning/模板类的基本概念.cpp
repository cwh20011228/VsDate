#include <iostream>
using namespace std;

template <class T1, class T2=string>		// 第二个通用参数缺省的数据类型是string
class AA {
public:
	T1 m_a;		// 通用类型用于模板类
	T2 m_b;		// 通用类型用于模板类

	AA() { m_a.aaaaaaaa(); }
	AA(T1 a,T2 b):m_a{a},m_b{b} { }		// 通用类型用于成员函数的参数
	
	// 通用类型用于成员函数的返回值
	T1 geta();
	T2 getb();
	
};

template <class T1,class T2>
T1 AA<T1,T2>::geta()
{
	T1 a = 2;
	return m_a + a;
}


template <class T1,class T2>
T2 AA<T1,T2>::getb()
{
	T2 b = "was";
	return m_b + b;
}


int main(void)
{
	//! 使用函数模板时，编译器根据实参自动推导出形参的数据类型，也可以手动显示指定数据类型，生成该类型的函数定义
	//! 类模板不一样，不存在自动推导类型的说法。怎么指定？用类模板创建对象的时候指定
	//! 使用类模板时，数据类型必须适应类模板中的代码
	//! 类模板可以为通用数据类型指定缺省的数据类型，（c++11标准的函数模板也可以）
	//! 类的成员函数也可以在类外实现
	//! 可以用new创建模板类对象
	//! 模板类的成员函数使用了才会创建
	
	/*AA<int> aa;
	aa.m_a = 20;
	aa.m_b = "西施";
	cout << "aa.geta()=" << aa.geta() << endl << "aa.getb()=" << aa.getb() << endl;
	*/

	// 类模板不是一种通用数据类型，创建对象时，要显示指定具体数据类型，
	AA<int, string>* a = new AA<int, string> {30,"西瓜"};
	auto b = a;
	a->geta();
	a->getb();
	cout << "a->geta()=" << a->geta() << endl << "a->getb()=" << a->getb() << endl;

	delete a;
	a = nullptr;
	

	AA<int, string>* c;
	// 虽然创建了类的指针，但是没有创建类的对象，不会调用构造函数，
	// 模板类的任何成员函数，只要程序中没有调用，就不会创建。
	// 所以尽管没有 m_a.aaaaaaaa(); 这个函数，依旧没有报错



}