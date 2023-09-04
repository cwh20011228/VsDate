#include <iostream>
#include <thread>
using namespace std;

//普通函数
void func(int bh, const string& str)
{
	for (int ii = 1; ii <= 3; ii++) {
		cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
		this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒
	}
}

// 仿函数
class mythread1 {
public:
	void operator()(int bh, const string& str)
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒
		}
	}
};

// 类的静态成员函数
class mythread2 {
public:
	static void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒
		}
	}
};

// 类的非静态成员函数
class mythread3 {
public:
	void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒
		}
	}
};

int main(void)
{
	// 用普通函数创建线程
	thread t1(func, 3, "我是一只傻傻鸟");
	thread t2(func, 8, "我是一只小小鸟");

	//用Lambda函数创建线程
	auto f = [](int bh, const string& str)->void
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒
		}
	};
	thread t3(f, 3, "我是一只傻傻鸟");

	// 用仿函数创建线程
	thread t4(mythread1(), 3, "我是一只傻傻鸟");

	// 用类的静态成员函数创建线程
	thread t5(mythread2::func, 3, "我是一只傻傻鸟");
	
	// 用类的非静态成员函数创建线程
	mythread3 thd;
	thread t6(&mythread3::func, &thd, 3, "我是一只傻傻鸟");
	// 第一个参数是成员函数的地址，第二个参数是对象的地址，即this指针

	 // 主线程（主程序）
	cout << "任务开始" << endl;
	for (int ii = 0; ii < 3; ii++) {
		cout << "执行任务中..." << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "任务完成" << endl;


	t1.join();	// 回收t1的资源
	t2.join();	// 回收t2的资源
	t3.join();	// 回收t3的资源
	t4.join();	// 回收t4的资源
	t5.join();	// 回收t5的资源
	t6.join();	// 回收t6的资源
}