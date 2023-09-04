#include <iostream>
#include <thread>
using namespace std;

template <typename T>
void show(T girl)      // 向超女表白的函数，参数可能是超女编号，也可能是姓名，所以用T。
{
	cout << "亲爱的" << girl << "，我是一只傻傻鸟。\n";
}

// 递归终止时调用的非模板函数，函数名要与展开参数包的递归函数模板相同。
void print()
{
	cout << "递归终止。\n";
}

// 展开参数包的递归函数模板。（整体思路：用递归函数把参数包一次一次的展开）
template <typename T, typename ...Args>	// 第一个是普通模板参数，第二个参数中间有三个圆点，表示可变参数
void print(T arg, Args... args)		//TODO:这是多个参数
{ // 第一个参数 arg用T来定义，表示已展开的参数，也就是这一次取出来的参数
	// 第二个参数args用Args来定义，表示尚未展开的参数包
	
	//cout << "参数： " << arg << endl;         // 显示本次展开的参数。

	show(arg);        // 把参数用于表白。

	//cout << "还有" << sizeof...(args) << "个参数未展开。" << endl;  // 显示未展开变参的个数。

	print(args...);     // 继续展开参数。  //TODO: args... 这是多个参数
}
//! print()是递归函数，每调用一次，就从参数包中取一个参数
// 参数包展开之后，你想怎么用就怎么用

template <typename...Args>
void func(const string& str, Args...args)   // 除了可变参数，还可以有其它常规参数。
{
	cout << str << endl;    // 表白之前，喊句口号。

	print(args...);    // 展开可变参数包。

	cout << "表白完成。\n";
}

// 可变参数模板特殊的地方，递归终止条件，和普通递归终止不一样，是参数为0时，递归结束。
//需要定义一个非模板函数，这个函数没有参数，表示参数包里已经没有参数了（可以理解为print模板函数的没有参数的具体化版本）

int main(void)
{
	//print("金莲", 4, "西施");   // 这多个参数叫参数包，把多个参数打成一个包的意思
	//print("冰冰", 8, "西施", 3);
	func("我是绝世帅歌。", "冰冰", 8, "西施", 3);  // "我是绝世帅歌。"不是可变参数，其它的都是。
}
