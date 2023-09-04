#include <iostream>
using namespace std;

class AA {
public:
	int m_a=9;
};

AA getTemp()
{
	return AA();	//返回AA匿名对象
}

int main(void)
{
	//int&& a = 3;	// 3是右值，给3取个名字，叫a（a是左值）
	//
	//int b = 8; // b是左值
	//int&& c = b + 5;	// b+5是右值，给b+5取个名字，叫c（c是左值）

	//int& d = c;
	//AA&& aa = getTemp();	// getTemp()的返回值是右值（临时变量）,给它取个名字，叫aa（aa是左值）
	//// getTemp()函数返回值，本来在表达式语句结束后，其生命周期也就该终结了，
	////但是，通过右值引用获得了新生，它的生命周期将与右值引用类型变量aa的生命周期一样
	////（只要aa还活着，该右值临时变量就会一直存活下去）
	//
	////! 右值有了名字之后，就成了普通变量，可以像使用左值一样使用它们,可以取地址...
	//// 为什么要给临时变量虚续命？在某些场景中临时变量还有继续利用的价值。
	//cout << "a=" << a << endl;
	//cout << "c=" << c << endl;
	//cout << "aa.m_a=" << aa.m_a << endl;
	//cout << "&a=" << &a << endl;


	int a = 1;
	const int& ra = a;	// a是非常量左值

	constexpr int b = 1;	// 常量
	const int& rb = b;		// b 是常量左值

	const int& rc = 1;	// 1是右值
}