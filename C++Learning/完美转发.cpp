#include <iostream>
using namespace std;

void func1(int& ii)	// 如果参数是左值，调用此函数
{
	cout << "参数是左值=" << ii << endl;
}

void func1(int&& ii)	// 如果参数是右值，调用此函数
{
	cout << "参数是右值=" << ii << endl;
}

//void func2(int& ii)	// 左值版本
//{
//	func1(ii);
//}

//void func2(int&& ii)	// 右值版本
//{
//	func1(move(ii));
//}

//template<typename T>
//void func2(T&& ii)	// 右值
//{
//	func1(move(ii));
//}

//template<typename T>
//void func2(T& ii)	// 左值
//{
//	func1(ii);
//}
// 我们希望的是：func2()把参数传给func1()的时候，也要有左值和右值之分

template<typename T>
void func2(T&& ii)
{
	func1(forward<T>(ii));
}

// 编译器可以区分左值和右值，调用模板的时候，它把参数的左，右值属性存起来。
// forward()模板函数再读取存起来的信息，然后转发出去

int main(void)
{
	int ii = 3;
	func2(ii);	// 将调用左值函数
	func2(8);	// 将调用右值函数


}