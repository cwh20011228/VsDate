#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

// typeid运算符用于获取数据类型的信息。
// typeid(数据类型)   typeid(变量名或表达式) 
// typeid运算符返回type_info类对象的引用（type_info类在<typeinfo>头文件中定义）
// type_info类中有name()成员函数，返回值是一个字符串，通常是类名
// type_info类的实现随编译器而异，

class AA {
public:
	AA() {}
};


int main(void)
{
	// typeid 用于自定义的数据类型
	/*int ii = 3;
	int* pii = &ii;
	int& rii = ii;
	cout << "typeid(int)= " << typeid(int).name() << endl;
	cout << "typeid(ii)= " << typeid(ii).name() << endl;
	cout << "typeid(int*)= " << typeid(int*).name() << endl;
	cout << "typeid(pii)= " << typeid(pii).name() << endl;
	cout << "typeid(int&)= " << typeid(int &).name() << endl;
	cout << "typeid(rii)= " << typeid(rii).name() << endl;*/

	// typeid 用于自定义的数据类型
	AA aa;
	AA* paa = &aa;
	AA& raa = aa;
	cout << "typeid(AA)= " << typeid(AA).name() << endl;
	cout << "typeid(aa)= " << typeid(aa).name() << endl;
	cout << "typeid(AA*)= " << typeid(AA*).name() << endl;
	cout << "typeid(paa)= " << typeid(paa).name() << endl;
	cout << "typeid(AA&)= " << typeid(AA&).name() << endl;
	cout << "typeid(raa)= " << typeid(raa).name() << endl;

	// type_info重载了== 与 != 运算符，用于对类型进行比较
	if (typeid(AA) == typeid(aa)) {
		cout << "ok1" << endl;
	}

	if (typeid(AA*) == typeid(paa)) {
		cout << "ok2" << endl;
	
	}

	if (typeid(AA) == typeid(raa)) {
		cout << "ok3" << endl;
	}

	if (typeid(AA) == typeid(*paa)) {
		cout << "ok4" << endl;
	}
	return 0;
}