//TODO: 普通类继承模板类的实例版本

#include  <iostream>
using namespace std;

//TODO: 模版类BB
template <class T1, class T2>
class BB {
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x, const T2 y) :m_x{ x }, m_y{ y } { cout << "调用了BB的构造函数.\n"; }
	void func2() { cout << "调用了func2()函数: m_x= " << m_x << ", m_y=" << m_y << endl; }

};


//TODO: 普通类AA
class AA:public BB<int,string> {
public:
	int m_a;
	AA(int a,const int x,const string y):m_a{a},BB(x,y) { cout << "调用了AA的构造函数.\n"; }
	void func1() { cout << "调用了func1()函数:m_a= " << m_a << endl;  }
};




int main(void)
{
	AA aa(3, 8, "我是一只傻傻鸟");
	aa.func1();
	aa.func2();

	return 0;
}