#include <iostream>
using namespace std;

int main(void)
{
	//size_t v1 = 42;	// size_t 是 unsigned long long 
	//auto f = [&v1]() ->size_t { return v1; };	// 使用值捕获，将v1拷贝到名为f的可调用对象
	//v1 = 0;
	//size_t v2 = f();
	//cout << v2 << endl;

	/*int a = 123;
	auto f = [=]() ->void { cout << a << endl; };
	f();

	auto f1 = [&]()->void {cout << a++ << endl; };
	f1();
	cout << a << endl;*/

	//int i = 2;
	//int j = 3;
	//auto f = [=, &j]()->int {return j + i; };

	/*int a = 123;
	auto f = [a]() mutable ->void {cout << ++a << endl; };
	f();
	cout << a << endl;*/

	int a = 10;
	int b = 20;
	auto f = [=](const int c)->int {return a + c; };

	int c = f(b);

	cout << c <<endl;

}