#include <iostream>
using namespace std;
//! static_cast不能丢掉指针或引用的const和volitale属性
void func(void* ptr)	//如果调用的函数需要转换指针，可以把它的形参设计为void*  
{	//! 其他类型指针  ->  void* 指针  ->  其他类型指针
	double* pp = static_cast<double*>(ptr);
}

int main(int argc, char* argv[])
{
	//TODO: static_cast 用于内置数据类型之间的转换
	//int ii = 3;
	//long ll = ii;	// 绝对安全，可以隐式转换，不会出现警告

	//double dd = 1.23;
	//long ll1 = dd;	// 可以隐式转换，但是，会出现可能丢失数据的警告
	//long ll2 = (long)dd;	// c风格：显示转换，不会出现警告
	//long ll3 = static_cast<long>(dd);  // c++风格：显示转换，不会出现警告
	//cout << "ll1" <<ll1 <<"  ll2=" << ll2 << "  ll3=" << ll3 << endl;

	//TODO: static_cast 用于指针之间的转换
	int ii = 10;
	// double* pd1 = &ii;	// 错误，不能隐式转换
	double* pd2 = (double*)&ii;		// c风格：强制转换
	//double* pd3 = static_cast<double*>(&ii);	// 错误，static_cast不支持不同类型指针的转换

	void* pv = &ii;		// 任何类型的指针都可以隐式转换为void*
	double* pd4 = static_cast<double*>(pv);		// static_cast 可以把void* 转换为其他类型的指针

	func(&ii);

}
