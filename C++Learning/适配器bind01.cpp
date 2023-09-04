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
	//function<void(int, const string&)> fn1 = bind(show, placeholders::_1, placeholders::_2);	// 用bind()绑定普通函数给function对象fn1
	auto fn1 = bind(show, placeholders::_1, placeholders::_2);	// bind返回的是function对象
	fn1(1, "我是一只傻傻鸟");	//用function对象调用普通全局函数show

	//类的静态成员函数
	function<void(int, const string&)> fn2 = bind(AA::show, placeholders::_1, placeholders::_2);
	fn2(2, "我是一只傻傻鸟");	// 用function对象调用类的静态成员函数

	// 仿函数
	function<void(int, const string&) > fn3 = bind(BB(), placeholders::_1, placeholders::_2);
	fn3(3, "我是一只傻傻鸟");	// 用function对象调用仿函数

	// 创建Lambda对象
	auto lb = [](int bh, const string& message)
	{
		cout << "亲爱的" << bh << "号，" << message << endl;
	};

	function<void(int, const string&)> fn4 = bind(lb, placeholders::_1, placeholders::_2);
	fn4(4, "我是一只傻傻鸟");	// 用function对象调用lambda函数

	// 可转换为函数指针的类对象，本质与仿函数一样
	DD dd;
	function<void(int, const string&)> fn6 = bind(dd, placeholders::_1, placeholders::_2);
	fn6(6, "我是一只傻傻鸟");

	// 类的非静态成员函数
	CC cc;
	function<void(CC&, int, const string&)> fn5 = bind(&CC::show, placeholders::_1, placeholders::_2, placeholders::_3);	// 参数列表第一个参数要填类对象的引用
	fn5(cc, 5, "我是一只傻傻鸟");	//用function对象调用成员函数

	// 在实际开发中，对于类的非静态成员函数，用function对象调用的时候，不希望把对象传进去，因为这样不能用于模板
	// 为了解决这个问题，可以把对象cc提前绑定
	function<void(int, const string&)> fn7 = bind(&CC::show,&cc, placeholders::_1, placeholders::_2);	// 参数列表第一个参数要填类对象的引用
	fn7(5, "我是一只傻傻鸟");	//用function对象调用成员函数,不需要传对象cc了（可用于模板）

}

// 通过bind适配器，我们把六种可调用对象的代码统一了