#include <iostream>
using namespace std;

// 括号运算符只能用类的成员函数重载
// 用重载了括号运算符的类创建的对象也叫函数对象或仿函数
void show(string str)
{
	cout << "普通函数：" << str << endl;
}

class CGirl {
public:
	void operator()(string str);
};

void CGirl::operator()(string str)
{
	cout<< "重载函数：" << str << endl;
}

int main(void)
{
	CGirl show;
	show("我是一只傻傻鸟");
	
	::show("我是一只傻傻鸟"); // 调用的是全局函数   ::show()

	return 0;
}