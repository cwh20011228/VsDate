#include <iostream>
using namespace std;

int main(void)
{
	int ii = 3;
	double dd = 3.8;
	auto f = [&](const int& no) {
		ii = ii + 2;
		cout << "ii=" << ii << endl;
		//cout << "dd=" << dd << endl;
		cout << "亲爱的" << no << "号，我是一只小小鸟" << endl;
	};

	//! lambda 函数的函数体内，可以直接使用父作用域中的局部变量(将变量名写在捕获列表中)
	//! 如果要捕获多个变量，在捕获列表中把要想捕获的变量名写出来，中间用逗号隔开
	f(8);
	return 0;
}