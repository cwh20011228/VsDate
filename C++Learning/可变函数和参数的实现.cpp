#include <iostream>
#include <thread>
#include <functional>
using namespace std;

void show0() 
{
	cout << "亲爱的，我是一只小小鸟" << endl;
}

void show1(const string& message)
{
	cout << "亲爱的，" << message << endl;
}

struct CC {
	void show2(int bh, const string& message) {
		cout << "亲爱的" << bh << "号，我是一只小小鸟" << endl;
	}
};

template <typename Fn,typename ...Args>		
auto show(Fn&& fn, Args&& ...args)	// auto作为函数返回值，是C++14的语法 （T&& 可以接受左值和右值）
//auto show(Fn&& fn, Args&& ...args)-> decltype(bind(forward<Fn>(fn), forward<Args>(args)...))
{
	cout << "表白前的准备工作..." << endl;
	auto f= bind(forward<Fn>(fn), forward<Args>(args)...);	// bind()参数也要完美转发
	f();
	cout << "表白完成" << endl;
	return f;
}

int main(void)
{
	show(show0);
	show(show1, "我是一只傻傻鸟");
	CC cc;
	auto f=show(&CC::show2, &cc, 3, "我是一只傻傻鸟");
	f();
}