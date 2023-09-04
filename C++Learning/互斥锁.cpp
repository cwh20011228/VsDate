#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;	// 创建互斥锁对象，保护共享资源cout对象

//普通函数
void func(int bh, const string& str)
{
	for (int ii = 1; ii <= 10; ii++) {
		// 在线程中，每次使用cout全局对象之前，申请加锁
		mtx.lock(); // 申请加锁
		cout << "第" << ii << "次表白：亲爱的" << bh << "号，" << str << endl;
		mtx.unlock();	// 用完了就解锁
		this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒
	}
}
// cout是全局对象，每个线程都使用它向屏幕输出数据，如果在同一时刻有多个线程使用cout，那么结果会有点乱
//! 用互斥锁给 全局对象cout 加锁

int main(void)
{
	//用普通函数创建线程
	thread t1(func, 1, "我是一只傻傻鸟");
	thread t2(func, 2, "我是一只傻傻鸟");
	thread t3(func, 3, "我是一只傻傻鸟");
	thread t4(func, 4, "我是一只傻傻鸟");
	thread t5(func, 5, "我是一只傻傻鸟");


	t1.join();	// 回收t1的资源
	t2.join();	// 回收t2的资源
	t3.join();	// 回收t3的资源
	t4.join();	// 回收t4的资源
	t5.join();	// 回收t5的资源

}