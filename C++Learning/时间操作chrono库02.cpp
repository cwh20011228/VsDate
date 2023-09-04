#include <iostream>
#include <chrono>
using namespace std;

int main(void)
{
	// 静态成员函数 chrono::steady_clock::now()获取开始的时间点
	//chrono::steady_clock::time_point start = chrono::steady_clock::now();
	auto start = chrono::steady_clock::now();

	// 执行一些代码，让它消耗一些时间
	cout << "计时开始....." << endl;
	for (int ii = 0; ii < 1000000; ii++) {
		//cout << "我是一只傻傻鸟" << endl;
	}
	cout << "计时结束...." << endl;

	// 静态成员函数 chrono::steady_clock::now()获取结束的时间点
	//chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();

	// 计算消耗的时间
	auto dt = end - start;
	cout << "耗时：" << dt.count() << "纳秒（" << (double)dt.count() / (1000 * 1000 * 1000) << "秒）" << endl;
}