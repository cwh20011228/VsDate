#include <iostream>
using namespace std;

using Fun = void(int,const string&);	// 普通函数类型的别名
Fun show;	// 声明普通函数   相当于   void show(int,const string&);

int main(void)
{
	show(1, "我是一只傻傻鸟");	// 直接调用普通函数

	void(*fp1)(int, const string&)=show;	 //声明函数指针，指向普通函数
	void(&fr1)(int, const string&) = show;	// 声明函数引用，引用普通函数
	fp1(2, "我是一只傻傻鸟");	// 用函数指针调用普通函数
	fr1(3, "我是一只傻傻鸟");	// 用函数引用调用普通函数

	Fun* fp2 = show;	// 声明函数指针，指向普通函数
	Fun& fr2 = show;	// 声明函数引用，引用普通函数
	fp2(4, "我是一只傻傻鸟");	// 用函数指针调用普通函数
	fr2(5, "我是一只傻傻鸟");	// 用函数引用调用普通函数
}

//定义普通函数
void show(int bh, const string& message)
{
	cout << "亲爱的" << bh << " 号," << message << endl;
}
