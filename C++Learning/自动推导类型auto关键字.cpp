#include <iostream>
using namespace std;

double func(int a, double b, const char* c, float d, short e, long f)
{
	cout << "a= " << a << "  b=" << b << "  c=" << c << "  d=" << d << "  e=" << e << "   f=" << f << endl;
	return 5.2;
}

int main(void)
{
	double (*funcptr)(int, double, const char* , float , short , long ); //! 声明函数指针funcptr
	funcptr = func;
	funcptr(2, 3.3, "李白", 3.6, 2, 8);

	auto funcptr1 = func;	//! 编译器推导出funcptr1为 函数指针double (*funcptr1)(int, double, const char* , float , short , long )
	funcptr1(2, 3.3, "李白", 3.6, 2, 8);

	return 0;
}

//! auto关键字的用途：
//! (1) 代替冗长复杂的变量声明（eg:声明函数指针）
//! (2) 在模板中，用于声明依赖模板参数的变量
//! (3) 函数模板依赖模块参数的返回值
//! (4) 用于lambda表达式