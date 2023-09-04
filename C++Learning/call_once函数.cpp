#include <iostream>
#include <mutex>	// std::call_once()和std::once_flag函数需要包含的头文件
#include <thread>
using namespace std;

once_flag onceflag;	// 定义一个once_flag的全局变量。本质是取值为0和1的锁

// 在线程中，打算只调用一次（假设只能在线程的任务函数中调用）
void once_func(const int bh, const string& str)
{
	cout << "once_func()  bh=" << bh << ",str=" << str << endl;
}

// 在多线程的程序中，多个线程可能用同一个线程任务函数，这样的话，每个线程都会执行这行代码，调用once_func()函数
void func(int bh, const string& str)
{
	call_once(onceflag,once_func,0, "个位观众老爷，我要开始表白了");

	for (int ii = 1; ii <= 3; ii++) {
		cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
		this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒
	}
}



int main(void)
{
	//用普通函数创建线程
	thread t1(func, 3, "我是一只傻傻鸟");
	thread t2(func, 8, "我是一只小小鸟");

	t1.detach();	// 分离子线程t1
	t2.detach();	// 分离子线程t1

	this_thread::sleep_for(chrono::seconds(10));	// 主线程休眠10秒

}