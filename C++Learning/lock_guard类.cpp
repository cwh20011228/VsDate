#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;	// 创建互斥锁，保护全局变量aa

int aa = 0;	// 定义全局变量

// 普通函数，把全局变量aa加1000000次
void func()
{
	for (int ii = 0; ii < 1000000; ii++) {
		lock_guard<mutex> mlock(mtx);
		aa++;
	}
}

int main(void)
{
	//func();
	//func();

	thread t1(func);	// 创建线程t1,把全局变量aa加到1000000次
	thread t2(func);	// 创建线程t2,把全局变量aa加到1000000次

	t1.join();	// 回收t1的资源
	t2.join();	// 回收t2的资源

	cout << "aa= " << aa << endl;
}