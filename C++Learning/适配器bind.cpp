#include <iostream>
#include <functional>
using namespace std;

void show(int bh,const string& message)
{
	cout << "亲爱的" << bh << "号，" << message << endl;
}

// 普通函数show()的函数类型与function对象要求的类型是相同的

int main(void)
{
	function<void(int, const string&)> fn1=show;  // 创建一个function类的对象
	function<void(int, const string&)> fn2=bind(show,placeholders::_1,placeholders::_2);		// 用bind()绑定一个可调用对象给function对象fn2
	// placeholders::_n 是参数占位符， placeholders::_1 表示function对象的第一个参数放这个位置， placeholders::_2 表示function对象的第2个参数放这个位置，

	fn1(1, "我是一只傻傻鸟");
	fn2(1, "我是一只傻傻鸟");

	// 创建function类的对象fn3,返回类型是void ， 参数列表是 const string&, int
	function<void(const string&, int)> fn3 = bind(show,placeholders::_2,placeholders::_1);
	fn3("我是一只傻傻鸟",1);


	int bh = 3;
	// 创建function类的对象，返回类型是 void ，参数列表是 const string&
	//function<void(const string&)> fn4 = bind(show, bh, placeholders::_1);	// 提前绑定的缺省是值传递
	function<void(const string&)> fn4 = bind(show, std::ref(bh), placeholders::_1);	// 提前绑定的是引用传递

	// function对象只需要一个参数，但是show()有两个参数，这样的话，可以把function对象不需要的那个参数(编号bh)提前绑定
	// 用bind()提前绑定参数，有一个细节要注意：被绑定的参数缺省是值传递
	bh = 8;
	fn4("我是一只傻傻鸟");

	function<void(int, const string&, int)> fn5 = bind(show, placeholders::_1, placeholders::_2);
	fn5(1, "我是一只傻傻鸟", 2);
}