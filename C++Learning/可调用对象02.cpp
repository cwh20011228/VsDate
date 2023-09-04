#include <iostream>
using namespace std;

struct CC {
	void show(int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号," << message << endl;
	}
};

int main(void)
{
	CC cc;
	cc.show(1, "我是一只傻傻鸟");

	//void(*pfun)(int, const string&)=show;	// 普通成员函数的指针
	void(CC::*fp)(int, const string&) = &CC::show;	// 定义类的成员函数的指针，&CC::show 类成员函数的地址，&不能省略
	(cc.*fp)(2, "我是一只傻傻鸟");	// 用类的成员函数的指针调用成员函数

	// C++11的书写风格
	using Fun = void(CC::*)(int, const string&);	// 类成员函数的指针类型
	Fun fp1 = &CC::show;	// 类的成员函数指针指向类的成员函数的地址
	(cc.*fp1)(2, "我是一只傻傻鸟");	//用类的成员函数的指针调用成员函数

	/*auto p = &CC::show;
	(cc.* p)(1, "我是一只傻傻鸟");*/

}

