#include <iostream>
using namespace std;

void Swap(int a, int b)	//普通函数
{
	cout << "使用了普通函数" << endl;
}

template <typename T>		// 函数模板
void Swap(T a, T b)
{
	cout << "使用了函数模板" << endl;
}

template<> 
void Swap(int a, int b)		// 函数模板的具体化版本
{
	cout << "使用了具体化的函数模板" << endl;
}


int main(void)
{
	Swap('2','3');	
	// 调用的是具体化的函数模板，（1）先匹配普通函数，参数不匹配（但可以转化） 
	//（2）与具体化的函数模板匹配，发现参数不匹配
	//（3）与常规模板匹配，编译器推导出的类型是char型， 匹配上了，调用常规模板

	return 0;
}

//! 编译器使用各种函数的规则：
//! （1）普通函数 > 具体化函数模板 > 函数模板    （ > 是优先级 ）
//! （2）如果希望使用函数模板，可以用空模板参数  函数模板名<>  来强制使用函数模板
//! （3） 如果函数模板能产生更好的匹配，使用的是函数模板