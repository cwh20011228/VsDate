#include <iostream>
using namespace std;

void show()
{
	cout << "调用了show()函数" << endl;
}

class BB		// 普通类
{
public:
	void operator()()
	{
		cout << "重载了BB类的仿函数" << endl;
	}
};

// 函数模板，参数和返回值是任意类型（支持普通类和模板类和其他类型）

template <typename T>
void func(T tt)
{
	tt();
}


int main(void)
{
	//BB b;
	func(show);

	return 0;
}