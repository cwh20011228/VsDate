#include "public1.h"
#include "public2.h"
#include <iostream>
using namespace std;

//TODO: 在命名空间中使用全局变量，而不是使用外部全局变量和静态变量
//TODO: 匿名的命名空间，从创建的位置到文件结束有效。

//namespace aa
//{
//	int ab = 1;		//全局变量
//
//	void func1();		// 全局函数的声明
//
//	class A1
//	{
//	public:
//		void show();	// 类的成员函数
//	};
//
//	void func1()
//	{
//		cout << "调用了aa::func1()函数" << endl;
//	}
//
//	void A1::show()
//	{
//		cout << "调用了a1::A1::show()函数" << endl;
//	}
//
//}
//
//namespace ma = aa;  // ma是命名空间aa的别名

namespace		// 匿名命名空间，它里面的变量可以在当前文件直接使用
{
	int ii = 20;
}


int main(void)
{
	cout << "ii=" << ii << endl;

	//TODO: 第一种方式：  命名空间::名字
	//cout << "ab=" << aa::ab << endl;
	//aa::func1();
	//aa::A1 a1;
	//a1.show();

	//TODO: 第二种方式：  using 命名空间::名字
	//using aa::ab;
	//using aa::A1;
	//using aa::func1;
	//cout << "ab=" << ab << endl;
	//func1();
	//A1 a1;
	//a1.show();

	//TODO: 第三种方式： using 编译指令  using namespace  命名空间
	/*using namespace aa;
	cout << "ab=" << ab << endl;
	func1();
	A1 a1;
	a1.show();
	int ab = 50;
	cout << "aa::ab=" << aa::ab << endl;*/

	using namespace aa;
	using namespace bb;
	cout << "ab=" << aa::ab << endl;
	aa::func1();
	aa::A1 a1;
	a1.show();
	cout << "ab=" << bb::ab << endl;
	return 0;

}