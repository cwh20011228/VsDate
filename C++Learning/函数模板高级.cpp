#include <iostream>
using namespace std;

//template <typename T1,typename T2>
//void func(T1 x, T2 y)
//{
//	auto temp = x + y;
//	cout << "tmp=" << temp << endl;
//}

int func()
{
	cout << "调用了func()函数" << endl;
	return 3;
}

typedef int (*FP)();
FP ptr = func;

int main(void)
{
//	short a = 3;
//	char b = 2;
//	//auto temp = a + b;
//	func(a, b);

	//! decltype(expression) var;
// 1）如果expression是一个没有用括号括起来的标识符，则var的类型与该标识符的类型相同，包括const等限定符。最常见的标识符有 函数名和变量名，包括类的成员变量
// 2）如果expression是一个函数调用，则var的类型与函数的返回值类型相同（函数不能返回void，但可以返回void * ）。
// 3）如果expression是一个左值（能取地址）(要排除第一种情况)、或者用括号括起来的标识符，那么var的类型是expression的引用。
// 4）如果上面的条件都不满足，则var的类型与expression的类型相同。

	short a = 5;
	short b = 10;
	decltype(a) da=b;

	decltype(func()) fa; 

	decltype(++a) dda=b;
	decltype((a)) daf=b;

	decltype((func)) ffa=func;  // 返回的是func的引用
	ffa();

	decltype(5) t;


	decltype(func()) g1;	// 声明一个int变量
	auto g2 = func();	// 声明一个int变量 ， auto dd = 表达式， 会执行表达式，执行函数func()

	typedef decltype(func()) myint;
	
	ptr();
	return 0;
}


//! 在C++11中，decltype 操作符，用于查询表达式的数据类型
//! 语法： decltype(expression) var;
//! decltype分析表达式并得到它的类型，不会计算执行表达式。函数调用也是一种表达式，因此不必担心使用decltype 时执行了函数
//! decltype(表达式) 的结果要么和表达式的类型一样，要么是表达式类型的引用
//! decltype和auto都可以推导表达式的数据类型，decltype不会执行表达式，auto会执行表达式