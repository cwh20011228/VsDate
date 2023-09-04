#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// 创建互斥锁对象，保护共享资源aa
mutex mtx;

int aa = 0;	// 定义全局变量

// 普通函数，把全局变量aa加1000000次
void func()
{
	for (int ii = 0; ii < 1000000; ii++) {
		cout << "线程" << this_thread::get_id() << "申请加锁" << endl;
		mtx.lock();	// 使用之前，加锁
		cout << "线程" << this_thread::get_id() << "加锁成功" << endl;
		aa++;
		this_thread::sleep_for(chrono::seconds(5));	// 休眠5秒
		mtx.unlock();	// 使用之后，解锁
		cout << "线程" << this_thread::get_id() << "释放了锁" << endl;
		this_thread::sleep_for(chrono::seconds(1));	// 休眠1秒之后，再回到for循环，再去申请加锁
	}
}

// 两个线程申请锁，只有一个成功，另一个在等待，5秒之后释放锁，等待中的线程申请锁成功，所在两个线程之间切换
int main(void)
{
	//func();
	//func();
	timed_mutex tm;
	tm.try_lock_for(chrono::seconds(10));

	thread t1(func);	// 创建线程t1,把全局变量aa加到1000000次
	thread t2(func);	// 创建线程t2,把全局变量aa加到1000000次

	t1.join();	// 回收t1的资源
	t2.join();	// 回收t2的资源

	cout <<"aa= " << aa << endl;
}