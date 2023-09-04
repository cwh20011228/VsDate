#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

int main(void)
{
	//atomic<int> a = 3;	// atomic(T val) noexcept; 转换函数
	//cout << "a=" << a.load() << endl;	// 读取原子变量的值
	//a.store(8);	//把8存入到原子变量
	//cout << "a=" << a.load() << endl;	// 读取原子变量的值
	//int old;
	//old=a.fetch_add(1);	// 把原子变量的值加1，返回原值
	//cout << "a=" << a.load() <<  "   old=" << old << endl;	// a=9  old =8

	//old = a.fetch_sub(3);	// 把原子变量的值减3，返回原值
	//cout << "a=" << a.load() << "   old=" << old << endl;	// a=6  old =9

	//old=a.exchange(3);	// 把3存入到原子变量，返回原值
	//cout << "a=" << a.load() << "   old=" << old << endl;

	atomic<int> ii = 3;		// 原子变量
	int expect = 4;		//	期待值
	int val = 5;	// 打算存入原子变量的值

	// 比较原子变量的值和预期值except，如果当两个值相等，把val存入到原子变量中，函数返回true;
	//如果当两个值不相等，用原子变量的值更新预期值，函数返回false。CAS指令
	bool bret = ii.compare_exchange_strong(expect, val);
	cout << "ii=" << ii << "   expect=" << expect << endl;	// ii=5  expect=3
	cout << bret << endl;



}