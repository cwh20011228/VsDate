#define _CRT_SECURE_NO_WARNINGS  // localtime()需要这个宏。
#include <iostream>
#include <chrono>
#include <iomanip>   // put_time()函数需要包含的头文件。
#include <sstream>
using namespace std;

int main(void)
{
	//(1) 静态成员函数chrono::system_clock::now()用于获取系统时间（C++时间）
	//chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
	auto now = chrono::system_clock::now();
	
	// (2) 静态成员函数chrono::system_clock::to_time_t()把时间转换为tiem_t。(UTC时间)
	//time_t t_now = chrono::system_clock::to_time_t(now);
	auto t_now = chrono::system_clock::to_time_t(now);
	
	//TODO: 时间的偏移(加上对应的秒)
	t_now = t_now + 24 * 60 * 60;	// 把当前的时间加1天
	//t_now = t_now + (-1 * 60 * 60);	// 把当前时间减1秒
	//t_now = t_now + 120;	// 当前时间减120秒

	// (3) std::localtime()函数把time_t转换为本地时间（北京时间）
	// localtime()不是线程安全的，VS用localtime_s代替，Linux用localtime_r代替
	//tm* tm_now = std::localtime(&t_now);
	auto tm_now = std::localtime(&t_now);

	// (4）格式化输出本地时间
	std::cout << std::put_time(tm_now, "%Y-%m-%d %H:%M:%S")<<std::endl;	
	// Y-年 m-月 d-日 H-小时 M-分钟 S-秒
	std::cout << std::put_time(tm_now, "%Y-%m-%d") << std::endl;
	std::cout << std::put_time(tm_now, "%H:%M:%S") << std::endl;
	std::cout << std::put_time(tm_now, "%Y%m%d%H%M%S") << std::endl;

	// 实际开发中，获取系统时间后，不一定要显示出来。
	stringstream ss; //  创建stringstream对象，需要包含头文件 <sstream>
	ss << std::put_time(tm_now, "%Y-%m-%d");	// 把时间输出到对象ss中
	string timestr = ss.str();	// 把ss转换成string对象
	cout << timestr << endl;
}