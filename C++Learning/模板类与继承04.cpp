//TODO: 模板类继承模板参数给出的基类（基类不能是模板类）

#include <iostream>
using namespace std;

class AA {
public:
	AA() { cout << "调用了AA的构造函数AA().\n"; }
	AA(int a) { cout << "调用了AA的构造函数AA(int a).\n"; }
};

class BB {
public:
	BB() { cout << "调用了BB的构造函数BB().\n"; }
	BB(int a) { cout << "调用了BB的构造函数BB(int a).\n"; }
};


class CC {
public:
	CC() { cout << "调用了CC的构造函数CC().\n"; }
	CC(int a) { cout << "调用了CC的构造函数CC(int a).\n"; }
};


template <class T>
class DD {
public:
	DD() { cout << "调用了DD的构造函数DD().\n"; }
	DD(int a) { cout << "调用了DD的构造函数DD(int a).\n"; }
};

template <class T>
class EE:public T {	
public:	//! 基类是不确定的，可以作为参数来传递
	EE():T() { cout << "调用了EE的构造函数EE().\n"; }
	EE(int a):T(a) { cout << "调用了EE的构造函数EE(int a).\n"; }
};

int main(void)
{
	EE<AA> ea1;
	EE<BB> eb1;
	EE<CC> ec1;
	EE<DD<int>> ed1;	// DD是模板类，也可以作为基类，但必须明确指出模板类DD的数据类型

	return 0;
}