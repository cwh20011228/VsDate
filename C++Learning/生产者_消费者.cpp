#include <iostream>
#include <string>
#include <thread>	// 线程类头文件
#include <mutex>	// 互斥锁类的头文件
#include <deque>	// deque容器头文件，双端队列
#include <queue>	// queue容器的头文件，队列
#include <condition_variable>	// 条件变量的头文件
using namespace std;

// 把生产/消费者的实现写在一个类中，这是比较标准的做法
class AA {
private:
	timed_mutex m_mutex;	// 带超时机制的互斥锁
	condition_variable_any m_cond;	// 条件变量
	queue<string, deque<string>> m_q;	// 缓存队列，底层容器用deque
public:
	//TODO: 生产者线程的任务函数
	void incache(int num)	// 生产数据，num指定数据的个数
	{
		lock_guard<timed_mutex> lock(m_mutex);	// 申请加锁(离开作用域的时候，lock_guard会自动释放锁)
		for (int ii = 0; ii < num; ii++) {
			static int bh = 1;	// 超女编号
			string message = to_string(bh++) + "号超女";	// 拼接出一个数据
			m_q.push(message);	// 把生产出来的数据入队
		}
		//m_cond.notify_one();	// （给消费者线程发送通知，告诉它们有数据要处理）唤醒一个被当前 条件变量阻塞的线程
		m_cond.notify_all();	// 通知所有等待的线程
	}
	// 被条件变量阻塞的消费者线程会形成一个等待队列，轮着来。
	// 但是如果缓存队列中同时有多个数据，那么不应该只让一个消费者线程去处理，合理的做法是让多个线程同时处理，这样的效率才更高。
	
	//TODO: 消费者线程的任务函数
	void outcache()
	{
		while (true) {
			string message;
			{
				// 把互斥锁转换为 unique_lock<mutex> ,并申请加锁（离开作用域的时候，unique_lock会自动释放锁）
				unique_lock<timed_mutex> lock(m_mutex);	// 申请加锁

				//TODO: 只有在加锁成功的情况下，才有机会阻塞在条件变量的wait()函数中。
				//TODO: 如果多个消费者线程一起运行，那么，只能有一个线程申请加锁成功，其他消费者线程都会阻塞在申请互斥锁这里
				 
				//? 只有一个线程阻塞在wait()函数中，其他的线程都会阻塞在申请加锁这里
				// 如果队列中没有数据，这个循环不会中止
				
				//while (m_q.empty()) {	//如果队列为空，进入循环；如果队列不为空，不进入循环，直接处理数据。必须用循环，不能用if
				//	m_cond.wait(lock);	// 等待生产者的唤醒信号（通知），如果没有通知，当前线程会一直阻塞
				//}
				m_cond.wait(lock, [this] {return !m_q.empty();} );

				// 数据元素出队
				message = m_q.front();	// 返回对头的元素
				m_q.pop();	// 再将元素删除（出队）
				cout << "线程:" << this_thread::get_id() << ", " << message << endl;
				//! 离开作用域的时候，unique_lock会自动释放锁
				//lock.unlock();	// 手工解锁
			}
				
			
			// 处理出队的数据（把数据消费掉）
			this_thread::sleep_for(chrono::microseconds(1));	// 假设处理数据需要1毫秒
			
		}
	}
};

//TODO: 使用锁的一个原则：持有锁的时间越短，效率越高
//! 对于消费者线程来说，把数据从队列中拿出来了，就应该立即释放锁。处理数据的时候，已经不需要锁了


int main(void)
{
	AA aa;
	// outcache()成员函数的代码逻辑是死循环，所以，消费者线程创建了，就一直存在，不会退出
	thread t1(&AA::outcache, &aa);	// 创建消费者线程t1
	thread t2(&AA::outcache, &aa);	// 创建消费者线程t2
	thread t3(&AA::outcache, &aa);	// 创建消费者线程t3

	// incache()成员函数只用于生产数据，生产完数据，函数就返回了
	this_thread::sleep_for(chrono::seconds(2));	// 休眠2秒
	aa.incache(2);	//生产3个数据

	this_thread::sleep_for(chrono::seconds(3));	// 休眠3秒
	aa.incache(5);	// 生产5个数据

	t1.join();	// 回收子线程的资源
	t2.join();
	t3.join();
}

// m_cond.notify_one(); 2秒之后，三个消费者线程中的一个线程被唤醒，消费3个数据。5秒之后，另一个线程被唤醒，消费5个数据。因为消费者线程一直再运行，所以程序不会退出
// m_cond.notify_all(); 每生产一批数据后，三个线程都会去竞争它们，如果队列中的数据刚好是三个，那么每个线程抢到一个。
// 如果缓存队列中有5个数据，那么有的线程抢了3个，有的线程抢了1个。

//TODO: 结论：如果生产的数据只有一个，用 notify_one()比较合适；如果生产的数据有多个，用 notify_all()比较合适