#include <iostream>
#include <cassert>		// 断言assert宏需要包含的头文件
using namespace std;

void copydata(void* ptr1, void* ptr2)	// 把ptr2中的数据复制到ptr1中
{
	assert(ptr1 && ptr2);		// 断言ptr1与ptr2都不会为空
	cout << "继续执行复制数据的代码" << endl;
}

int main(void)
{
	const int ii = 0,jj = 0;

	static_assert(ii, "ii的值不合法");
	/*copydata(nullptr , &jj);*/
	return 0;
}