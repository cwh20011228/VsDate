#include <iostream>
using namespace std;

int main(void)
{
	double* ptr=nullptr;

	// 分配一大块内存
	//try {
	//	ptr = new double[10000000000];
	//	// new分配内存失败，会抛出异常，如果程序中没有处理它抛出的异常，程序会调用 abort() 函数中止
	//}
	//
	//catch (bad_alloc& e)
	//{
	//	cout << "分配内存失败" << endl;
	//}

	ptr = new(std::nothrow) double[10000000000];
	if (ptr == nullptr) cout << "分配内存失败" << endl;
	if (ptr != nullptr)
	{
		delete[] ptr;
	}
}