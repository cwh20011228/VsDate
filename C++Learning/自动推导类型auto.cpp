#include <iostream>
using namespace std;

// 声明变量时，如果不指明数据类型，而使用auto关键字，编译器会根据等号=右边的数据，自动推导出变量的数据类型

//class AA {
//	auto m_a;
//};


string func()
{
	return "李白";
}

//void show(auto aa)
//{
//	cout << "aa= " << aa << endl;
//}

int main(void)
{
	//! c++的自动推导类型
	// 以下滥用了auto关键字
	auto a = 3+1;
	cout << "a= " << a << endl;
	auto b = 3.3+a;
	cout << "b= " << b << endl;
	auto c = "李白";			// 编译器推导的c的变量类型是const char*
	cout << "c= " << c << endl;	
	auto d = func();			// 编译器推导的d的变量类型是 string
	cout << "d= " << d << endl;
	
	/*auto ss[22] = { 0 };*/

	//! 注意：(1) auto声明的变量必须在定义的时候初始化
	//! (2) auto初始化的右值可以是具体的数值，也可以是表达式或返回值
	//! (3) 函数的形参类型不能用auto
	//! (4) auto不能直接声明数组
	//! (5) auto不能定义类的非静态成员变量
	
	return 0;
}