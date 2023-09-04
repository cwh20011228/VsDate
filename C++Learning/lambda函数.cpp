#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 表白函数
void zssshow(const int& no)
{
	cout << "亲爱的" << no << "号：我是一只傻傻鸟" << endl;
}

// 表白仿函数
class czs {
public:
	void operator()(const int& no)
	{
		cout << "亲爱的" << no << "号：我是一只傻傻鸟" << endl;
	}
};

int main(void)
{
	vector<int> vv = { 5,8,3 };	// 存放超女编号的容器

	// 第三个参数是普通函数
	for_each(vv.begin(), vv.end(), zssshow);

	// 第三个参数是仿函数
	for_each(vv.begin(), vv.end(), czs());

	auto f = [](const int& no)->double {
		cout << "亲爱的" << no << "号：我是一只傻傻鸟" << endl;
		return 1.3;
	};
	// 第三个参数是Lambda表达式
	for_each(vv.begin(), vv.end(),f);
	// 采用lambda表达式不需要提前准备好函数或仿函数，用到的时候，临时写一段代码
	f(333);		// 像使用普通函数一样，使用Lambda函数
}