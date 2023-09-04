#include <iostream>
using namespace std;

// 基类中的虚函数一般用于实现缺省的，通用的功能。
// 如果不需要缺省的，通用的功能，就把基类中的虚函数设置为纯虚函数

class AA {
public:
	AA() { cout << "调用了基类的默认构造函数AA()" << endl; }
	virtual void func() = 0 { cout << "调用了基类的函数func()" << endl; }
	virtual ~AA() = 0{ cout << "调用了基类的析构函数~AA()" << endl; }
};

// 基类中的纯虚析构函数必须要用代码实现
// 原因：当派生类对象被销毁时，调用派生类的析构函数destructor,再自动调用基类的析构函数
class BB :public AA {
public:
	BB() { cout << "调用了派生类的默认构造函数BB()" << endl; }
	void func() { cout << "调用了派生类的函数func()" << endl; }
	~BB() { cout << "调用了派生类的析构函数~BB()" << endl; }
};

int main(void)
{
	BB b;
	AA* p = &b;
	p->func();



	return 0;
}
//class Hero {
//public:
//	int viablity;
//	int attack;
//	virtual void skill1() = 0;
//	virtual void skill2() = 0;
//	virtual void skill3() = 0;
//};
//
//class XS :public Hero {
//public:
//	void skill1() { cout << "西施释放了一技能" << endl; }
//	void skill2() { cout << "西施释放了二技能" << endl; }
//	void skill3() { cout << "西施释放了大招" << endl; }
//};
//
//
//int main(void)
//{
//	XS xs;
//	xs.skill1();
//	xs.skill2();
//	xs.skill3();
//	return 0;
//}

