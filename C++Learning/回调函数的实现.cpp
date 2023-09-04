#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>	// 队列容器
#include <deque>	// 双端队列容器
#include <string>
#include <functional>
using namespace std;

// 框架要求回调函数只能有一个参数，需要处理的数据是string类型
void show(const string& message)	// 处理业务的普通函数
{
	cout << "处理数据：" << message << endl;
}

struct BB {	// 处理业务的类
	void show(const string& message)	
	{
		cout << "处理表白数据：" << message << endl;
	}
};
class AA {
private:
	mutex m_mutex;	// 创建互斥锁
	condition_variable m_cond;	//条件变量
	queue<string,deque<string>> m_q;	// 换从队列
	function<void(const string&)> m_callback;	// 回调函数对象
 public:
	 // 注册回调函数，回调函数只有一个参数（消费者接收到的数据）
	 template<typename Fn,typename ...Args>
	 void callback(Fn&& fn, Args&& ...args)
	 {
		 m_callback = bind(forward<Fn>(fn), forward<Args>(args)...,std::placeholders::_1); // 绑定回调函数
		// 如果传进来的可调用对象是成员函数，需要把对象的this指针传进来（谁调用成员函数，this指针就指向谁，所以this指针是对象的地址 &cc），可变参数包中将有一个参数
		// 如果传进来的可调用对象不是成员函数，那么可变参数包中就没有参数了
		// 第三个参数是占位符，因为框架在调用回调函数的时候，会把数据传进来
	 }

	void incache(int num)	// 生产数据，num指定数据的个数
	{
		lock_guard<mutex> lock(m_mutex);	// 申请加锁
		for (int ii = 1; ii <= num; ii++) {
			static int bh = 1;
			string message = to_string(bh++) + "号超女";
			m_q.push(message);	// 把生产的数据入队
		}
		m_cond.notify_all();	// 唤醒被当前条件变量阻塞的线程
	}

	void outcache()
	{
		while (true) {
			string message;
			{
				unique_lock<mutex> lock(m_mutex);	// 把mutex转换为unique_lock
				while (m_q.empty()) {
					m_cond.wait(lock);
				}

				// 数据出队
				message = m_q.front();
				m_q.pop();
				cout << "线程" << this_thread::get_id() << ", " << message << endl;
			}
			// 处理数据
			this_thread::sleep_for(chrono::milliseconds(1));
			if (m_callback) m_callback(message);	// 回调函数，把收到的数据传给它
			// 如果注册了回调函数，那么就调用它，把出队的数据message传给它，让回调函数去处理业务
		}
	}

};

int main(void)
{
	AA aa;
	// 在创建线程之前，先注册回调函数
	//aa.callback(show);	// 回调函数用普通函数
	BB bb;
	aa.callback(&BB::show, &bb);	// 回调函数用类的成员函数

	thread t1(&AA::outcache, &aa);
	thread t2(&AA::outcache, &aa);
	thread t3(&AA::outcache, &aa);

	this_thread::sleep_for(chrono::seconds(2));
	aa.incache(2);

	this_thread::sleep_for(chrono::seconds(3));
	aa.incache(5);

	t1.join();
	t2.join();
	t3.join();
}