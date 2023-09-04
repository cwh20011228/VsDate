#include <iostream>
using namespace std;

#define BH 3
#define MESSAGE "我是一只傻傻鸟"

int main(void)
{
	/*cout << "亲爱的" << BH << "号，" << MESSAGE << endl;
	cout << __FILE__ << endl;
	cout << __FUNCTION__ << endl;
	cout << __LINE__ << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __TIMESTAMP__ << endl;
	cout << __cplusplus << endl;*/

//TODO: 在VS中，long是32位，long long 是64位。  linux中 long 是64位
	// 不同操作系统的宏：  __linux__   _WIN32

//！#ifdef  #else #endif   这是条件编译指令，如果条件满足，就是用这段代码，用这段代码来编译。如果条件不满足，就不适用这段代码，当它不存在，也不会编译它
#ifdef _WIN32
	cout << "这是windows系统" << endl;
	typedef long long int64;
#else
	cout << "这不是windows系统" << endl;
	typedef long int64;
#endif

	int64 a = 10;
	cout << "a=" << a << endl;

	return 0;
}