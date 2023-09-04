#include <iostream>
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
	/*cout << "调用了Swap()函数" << endl;*/
}

template <typename T>
T Add(T a, T b)
{
	return a + b;
}


template <typename T1,typename T2>
void show(T1 no, T2 message)
{
	cout << "no="<<no << "  message="<<message << endl;
}


template <typename T>
void func(T a)
{
	cout << "func(T a)" << endl;
}

template <typename T1,typename T2>
void func(T1 a, T2 b)
{
	cout << "func(T1 a, T2 b)" << endl;
}

template <typename T1,typename T2>
void func(T1 a, T2 b, int c)
{
	cout << "func(T1 a, T2 b, int c)" << endl;
}

//class CGirl {
//public:
//	template <typename T>
//	CGirl(T a)
//	{
//		cout << "a=" << a << endl;
//	}
//
//	template <typename T>
//	void show(T b)
//	{
//		cout << "b=" << b << endl;
//	}
//
//
//};

int main()
{
	//CGirl a("西施");
	//a.show(2);
	//a.show("李白");

	//int a = 1;
	//int b = 2;
	//Swap(a,b);
	//cout << "a=" << a << "   b=" << b << endl;
	/*Swap<int>();*/

	int a = 10;
	char b = '20';
	int c = Add<int>(10, 20);
	cout << "c=" << c << endl;

	int bh = 3;
	string message = "我是一只傻傻鸟";
	show(bh, message);
	/*string a = "西瓜";
	string b = " 西施";
	string c = Add(a, b);*/

	/*CGirl a;
	CGirl b;
	CGirl c = Add(a, b);*/

	func(2);
	func(1, 2);
	func(1, 2, 3);

	return 0;
}


//! 函数模板的注意事项：
//! （1）可以为类的成员函数创建模板，但不能是虚函数和析构函数
//! （2）使用函数模板时，必须明确数据类型，确保实参与函数模板能匹配上
//! （3）使用函数模板时，推导的数据类型必须适应函数模板中的代码
//! （4）...，如果是自动类型推导，不会发生隐式类型转换；如果显示指定了函数模板的数据类型，可以发生隐式转换
//! （5）函数模板支持多个通用数据类型的参数
//! （6）函数模板支持重载，可以有非通用数据类型的参数