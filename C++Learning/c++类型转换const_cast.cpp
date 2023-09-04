#include <iostream>
using namespace std;

//! const_cast可以丢掉指针或引用的const和volitale属性


void func(int* ptr)
{

}

int main(int argc,char* argv[])
{
	const int* aa=nullptr;
	int* bb=(int*)aa;		// c风格，强制转换，丢掉const限定符
	int* cc = const_cast<int*>(aa); // c++风格，强制转换，丢掉const限定符
	

	func(const_cast<int*>(aa));
	return 0;

}