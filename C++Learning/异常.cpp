#include <iostream>
using namespace std;


int main(void)
{
	try
	{
		// 可能抛出的异常
		int ii = 0;
		cout << "你是一只什么鸟?(1-傻傻鸟  2-小小鸟)：";
		cin >> ii;

		if (ii == 1) {	// throw抛出const char* 类型的异常
			throw "不好，有人说我是一只傻傻鸟";
		}

		if (ii == 2)	// throw抛出int类型的异常
		{
			throw ii;
		}

		if (ii == 3)	// throw抛出string类型的异常
		{
			throw string("不好，有人说我是一只傻傻鸟");
		}


		cout << "我不是一只傻傻鸟" << endl;
	}

	catch (int ii)
	{
		cout << "异常的类型为int=" << ii << endl;
	}

	catch (const char* ss)
	{
		cout << "异常的类型为const char*=" << ss << endl;
	}

	catch (string str)
	{
		cout << "异常的类型为string=" << str << endl;
	}

	//catch (...)		// 不管什么异常，都在这处理
	//{
	//	cout << "捕获到异常，具体没管是什么异常" << endl;
	//}

	cout << "程序继续运行..." << endl;	// 执行完try ... catch...后，将继续执行程序中其他的代码
	return 0;
}