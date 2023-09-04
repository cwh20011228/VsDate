#include <iostream>
#include <initializer_list>
#include <string>

double sum(std::initializer_list<double> ii)
{
	double total = 0;
	for (auto it = ii.begin(); it != ii.end(); it++) {
		total = total + *it;
	}
	return total;
}


void func(const int len1)
{	// 给函数的形参加上const，表示只读变量，调用函数时，实参可能是变量，也可能是常量
	// len1是只读变量，不是常量
	//int array[len1] = { 0 };	// VS报错，Linux平台的数组长度支持变量，不会报错。
	// 在vs中，定义数组的时候，长度必须是常量表达式，不能是变量

	constexpr int len2 = 8;		// 定义变量的时候，加上const，len2才是真正的常量
	int array[len2] = { 0 };	// 正确，len2是常量
}

int main(void)
{
	//double total = sum( 3.14,5.20,8 );	// 错误，没有大括号，这是三个参数。
	//double total = sum({ 3.14,5.20,8 });	// 正确，有大括号，这是一个参数。
	//std::cout << "total=" << total << std::endl;

	//std::string str = "123a45";
	//size_t pos;
	//int val = stoi(str, &pos, 10);
	//std::cout <<"val=" << val << std::endl;	// 输出123
	//std::cout << "pos=" << pos << std::endl;	// 输出3

	func(1);
}