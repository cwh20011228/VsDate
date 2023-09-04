#include <iostream>
using namespace std;

using Fun = void(int, const string&);	// 给普通函数类型起一个别名

struct AA{
	static void show(int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号," << message << endl;
	}
};

int main(void)
{
	AA::show(1, "我是一只傻傻鸟");	//直接调用AA的静态成员函数

	// c风格的
	void(*pfun)(int, const string&) = AA::show;		// 声明函数指针，指向类的静态成员函数
	void(&func)(int, const string&) = AA::show;		// 声明函数引用，引用类的静态成员函数

	pfun(2, "我是一只傻傻鸟");		// 用函数指针调用类的静态成员函数
	func(3, "我是一只傻傻鸟");		// 用函数引用调用类的静态成员函数

	//C++风格
	Fun* pfun1 = AA::show;	// 声明函数指针，指向类的静态成员函数
	Fun& func1 = AA::show;	// 声明函数引用，引用类的静态成员函数
	
	pfun1(2, "我是一只傻傻鸟");	// 用函数指针调用类的静态成员函数
	func1(3, "我是一只傻傻鸟");	// 用函数引用调用类的静态成员函数

}