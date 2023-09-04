#include <iostream>
using namespace std;

// C++中，字符，各种整数，浮点数，布尔型都是数字，是兼容的，可以自动转换
// 调用一个参数的构造函数用作自动转换函数，自动进行的，不需要显示的转换
// 多个参数的构造函数，出第一个参数外，如果其他参数都有缺省值，那么也可以作为转换函数
// 声明一个参数的构造函数的时候，可以使用explicit关键字来关闭自动转换的特性

class mystring {
private:
	string m_ptr;
public:
	mystring(const string& ss):m_ptr{ss}{ }
	
};

class CGirl {
public:
	int m_bh;
	string m_name;
	double m_weight;

	CGirl();
	void show() const;
	explicit CGirl(int bh);
	explicit CGirl(double weight);
	/*CGirl(int bh, double weight=25.3);*/
};

CGirl::CGirl() 
{
	m_bh = 0;
	m_name.clear();
	m_weight = 0;
	cout << "调用了CGirl()" << endl;
}

void CGirl::show() const
{
	cout << "bh= " << m_bh << "  name= " << m_name << "  weight=" << m_weight << endl;
}

CGirl::CGirl(int bh)
{
	m_bh = bh;
	m_name.clear();
	m_weight = 0;
	cout << "调用了CGirl(int bh)" << endl;
}

CGirl::CGirl(double weight)
{
	m_bh = 0;
	m_name.clear();
	m_weight = weight;
	cout << "调用了CGirl(double weigh)" << endl;
}

//CGirl::CGirl(int bh, double weight )
//{
//	m_bh = bh;
//	m_name.clear();
//	m_weight = weight;
//	cout << "调用了CGirl(int bh, double weight)" << endl;
//}


void func(CGirl g)
{
	g.show();
}

//CGirl func1(CGirl g)
//{
//	return g.m_bh;
//}

int main(void)
{
	/*string s1 = "我是一只傻傻鸟";
	const mystring s2 = s1;*/

	CGirl g1{ 25 };	//常规的写法
	CGirl g2 = CGirl{ 26 }; // 显示转换
	//CGirl g3 = 'a';	// 隐式转换
	/*g3.show();*/
	//CGirl g4;	// 创建对象
	//g4 = 28;	// 用CGirl(8) 创建临时对象，再赋值给g4

	/*CGirl g5 = 5;
	g5.show();*/
	//g1.show();
	/*g2.show();*/
	
	//g4.show();

	/*func(3.8);*/
	/*func1(g3);*/

	CGirl g3 =(CGirl)'a';

	return 0;
}


