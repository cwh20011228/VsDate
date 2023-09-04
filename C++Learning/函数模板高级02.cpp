#include <iostream>
using namespace std;

//! 函数后置返回类型 
//! auto是一个占位符(c++11给auto新增的功能),为函数返回值占了一个位置
// int func(){ }
auto func() -> int 
{
	cout << "调用了func()函数" << endl;
	return 3;
}

//! 函数的返回值类型用 decltype(x+y)  ,只能写在后面（后面在形参x和y的作用域），不能写在前面（前面没有在x和y的作用域），
//template <typename T1,typename T2>
//auto Add(T1 x, T2 y) -> decltype(x + y)
//{
//	decltype(x + y) temp = x + y;
//	cout << "temp=" << temp << endl;
//	return temp;
//}


//! c++14标准对函数返回类型推导规则做了优化，函数的返回值类型可以是auto，不用尾随返回类型
template <typename T1, typename T2>
auto Add(T1 x, T2 y){
	decltype(x + y) temp = x + y;
	cout << "temp=" << temp << endl;
	return temp;
}


int main(void)
{
	/*decltype(func()) fa;
	decltype (func) *fp=func;
	fp();*/

	Add(2.3, 5);

	return 0;
}