#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class AA {
private:
	//mutex m_mutex;
	recursive_mutex m_mutex;	// 递归互斥锁
public:
	void func1() {
		m_mutex.lock();	// 申请加锁
		cout << "调用了funcn1()" << endl;
		m_mutex.unlock();	// 解锁
	}

	void func2() {
		m_mutex.lock();	// 申请加锁
		cout << "调用了funcn2()" << endl;
		func1();
		m_mutex.unlock();	// 解锁
	}
};

int main(void)
{
	AA aa;
	//aa.func1();
	aa.func2();	// 出现了死锁，普通的互斥锁必须在解锁之后才能加锁
	// func2() 加锁后，互斥锁处于锁定状态，再去调用func1()，func1()这边不可能申请到锁，这样就出现了死锁。
}