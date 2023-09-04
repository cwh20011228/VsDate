#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

// 普通函数
void func(int bh, const string& str)
{
	for (int ii = 1; ii <= 10; ii++) {
		cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
		Sleep(1000);	// 休眠1秒
	}
}

class mythread1 {
public:
	void operator()(int bh, const string& str)
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			Sleep(1000);	// 休眠1秒
		}
	}
};


class mythread2 {
public:
	static void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			Sleep(1000);	// 休眠1秒
		}
	}
};

class mythread3 {
public:
	void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			Sleep(1000);	// 休眠1秒
		}
	}
};

//! main函数中的代码叫主程序，主线程或主进程
//! 对象t1是子线程。主线程只有一个，子线程可以有很多，与计算机的硬件资源有关（普通的电脑可以创建几百个子线程，好的服务器可以创建几千个子线程）

int main(void)
{	
//TODO: 程序一边执行func()函数中的任务，一边执行main函数中的任务，两个任务是同时执行的
	
	thread t1(func, 3, "我是一只傻傻鸟");
	thread t2(func, 8, "我是一只小小鸟");

	t1.detach(); t2.detach();	// 将子线程t1和t2分离出去
	// 用Lambda函数创建线程
	auto f = [](int bh, const string& str)->void
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
			Sleep(1000);	// 休眠1秒
		}
	};
	//thread t3(f, 3, "我是一只傻傻鸟");

	// 用仿函数创建线程
	//thread t4(mythread1(), 3, "我是一只傻傻鸟");	// 第一个参数用仿函数的匿名对象

	// 用类的静态成员创建线程
	//thread t5(mythread2::func, 3, "我是一只傻傻鸟");	// 类的静态成员函数与普通函数的性质是一样的

	// 用类的普通函数创建线程
	//mythread3 myth;	// 必须先创建类的对象，必须保证对象的生命周期比子线程要长
	//thread t6(&mythread3::func,&myth, 3, "我是一只傻傻鸟");	
	// 第一个参数填成员函数的地址，第二个参数填对象的地址，即this指针

	//cout << "任务开始" << endl;
	//for (int ii = 0; ii < 12; ii++) {
	//	cout << "执行任务中..." << endl;
	//	Sleep(1000);
	//}
	//cout << "任务完成" << endl;
	////return 0;

	//t1.join();	// 回收线程t1的资源
	//t2.join();	// 回收线程t2的资源
	//t3.join();	//回收线程t3的资源
	//t4.join();		//回收线程t4的资源
	//t5.join();		//回收线程t5的资源
	//t6.join();	

	// 主线程在退出前，回收子线程的资源
	Sleep(12000);
}