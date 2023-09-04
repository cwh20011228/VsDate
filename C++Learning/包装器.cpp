#include <iostream>
#include <functional>
using namespace std;

// 普通函数
void show(int bh, const string& message)
{
	cout << "亲爱的" << bh << "号，" << message << endl;
}

// 类的静态成员函数
struct AA {
	static void show(int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号，" << message << endl;
	}
};

// 仿函数
struct BB {
	void operator()(int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号，" << message << endl;
	}
};

//类中有普通成员函数
struct CC {
	void show(int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号，" << message << endl;
	}
};

//可被转换为普通函数指针的类
struct DD {
	using Fun = void(*)(int, const string&);	// 函数指针的别名
	operator Fun() {
		return show;	// 返回普通函数show的地址
	}
};


int main(void)
{
	//普通函数
	using fun = void(int, const string&);	// 普通函数show类型的别名
	fun* fp1 = show;	//声明函数指针，指向普通函数
	fp1(1, "我是一只傻傻鸟");	// 用函数指针调用普通函数

	//TODO: 用包装器
	function<void(int, const string&)> fn1 = show;	// 包装普通全局对象,可读性更高
	//function<fun> fn1 = show;   // function模板参数是普通函数类型的别名
	fn1(1, "我是一只傻傻鸟");	//用function对象调用普通全局函数show

	//类的静态成员函数
	using sun = void(int, const string&);	// 普通函数类型的别名
	sun& sp1 = AA::show;	// 声明函数引用，引用类的静态成员函数
	sp1(2, "我是一只傻傻鸟");	//用函数引用调用类的静态成员函数

	//TODO: 包装类的静态成员函数
	function<void(int, const string&)> fn2 = AA::show;	// 包装类的静态成员函数
	fn2(2, "我是一只傻傻鸟");	// 用function对象调用类的静态成员函数

	// 仿函数
	BB bb;
	bb(3, "我是一只傻傻鸟");	// 用仿函数对象调用仿函数

	// TODO: 包装仿函数
	//function<void(int, const string&) > fn3 = bb;	// 包装仿函数
	function<void(int, const string&) > fn3 = BB();	// 用匿名对象
	fn3(3, "我是一只傻傻鸟");	// 用function对象调用仿函数

	// 创建Lambda对象
	auto lb = [](int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号，" << message << endl;
	};
	lb(4, "我是一只傻傻鸟");	// lambda函数的本质是仿函数，仿函数的本质是类

	//TODO: 包装lambda函数
	function<void(int, const string&)> fn4 = lb;
	/*function<void(int, const string&)> fn4 = [](int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号，" << message << endl;
	};	// lambda不一定有名字	*/
	fn4(4, "我是一只傻傻鸟");	// 用function对象调用lambda函数


	// 类的非静态成员函数
	CC cc;
	using cfun = void(CC::*)(int, const string&);	//类成员函数的指针类型
	cfun cpf = &CC::show;	// 类的成员函数指针指向类的成员函数
	(cc.*cpf)(5, "我是一只傻傻鸟");	// 类的成员函数指针调用成员函数

	//TODO: 包装类的非静态成员函数,类成员函数必须用类的对象名才能调用
	function<void(CC&, int, const string&)> fn5 = &CC::show;	// 参数列表第一个参数要填类对象的引用
	fn5(cc, 5, "我是一只傻傻鸟");	//用function对象调用成员函数

	// 可转换为函数指针的类对象，本质与仿函数一样
	DD dd;
	dd(6, "我是一只傻傻鸟");	// 用可以被转换为函数指针的类对象调用普通函数

	//TODO: 包装可转换为函数指针的类对象
	function<void(int, const string&)> fn6 = dd;
	fn6(6, "我是一只傻傻鸟");
}