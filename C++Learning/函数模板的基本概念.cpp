#include <iostream>
using namespace std;

// 函数模板是通用的函数描述，使用任意类型(范型)来描述函数
// 编译的时候，编译器推导实参的数据类型，根据实参的数据类型和函数模板，生成该类型的函数定义(函数的代码)
// 生成函数定义的过程被称为 实例化

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//! 函数模板的原理：
//! 编译的时候，编译器先检查源代码中全部函数调用的代码，如果找到23行，发现Swap()函数是函数模板，
//! 分析实参a和b的类型,是int型。 然后根据Swap()函数模板,生成一个形参为int的Swap()函数


/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
/// 
/// 

//! 函数模板用 typename   类模板用 class 
int main(void)
{
	int a = 10, b = 20; // string a = "张三", b = "李四";
	Swap(a, b);
	// 如果不想让编译器自动推导，可以在 函数模板名<> 尖括号中填写数据类型
	// Swap<int>(a, b);
	cout << "a=" << a << "  b=" << b << endl;

	return 0;
}