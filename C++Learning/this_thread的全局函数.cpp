// 在多线程的程序中，每个线程都有一个id，用于识别线程，就像身份证号码一样，每个人都有，不会重复
// 相同的程序，每次运行，产生的线程id是不一样的
#include <iostream>
#include <Windows.h>
#include <thread>
using namespace std;


void func(int bh, const string& str)
{
	cout << "子线程:" << this_thread::get_id() << endl;	// this_thread表示子线程的id
	for (int ii = 1; ii <= 10; ii++) {
		cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
		//Sleep(1000);	// 休眠1秒
		this_thread::sleep_for(chrono::seconds(1));	//休眠1秒
	}
}

int main(void)
{
	// 用普通函数创建线程
	thread t1(func, 3, "我是一只傻傻鸟");
	thread t2(func, 8, "我是一只小小鸟");

	cout << "子线程t1:" << t1.get_id() << endl;
	cout << "子线程t2:" << t2.get_id() << endl;

	t1.swap(t2);	// 交换t1和t2

	cout <<"主线程:" << this_thread::get_id() << endl;	// 这行代码出现在主程序中，this_thread表示主线程
	
	thread t3 = move(t2);	// t2被转移资源后，就不再代表线程了，join()会报错，t3才代表线程

	// 用线程对象的get_id()成员函数获取子线程的id
	cout << "子线程t1:" << t1.get_id() << endl;
	cout << "子线程t2:" << t2.get_id() << endl;

	t1.join();	// 回收线程t1的资源
	t3.join();	// 回收线程t3的资源
}