#include <iostream>
#include <memory>
using namespace std;

// 多态的应用场景：基类中的成员函数(虚函数)实现基本功能，派生类中重定义虚函数进行扩充功能
// 对普通继承来说，成员变量的地址是静态的，不会出现在内存模型中

// 如果类中没有虚函数，编译的时候，编译器直接将成员函数的地址链接到二进制文件中。
// 如果类中由虚函数，编译的时候，编译器不会把虚函数的地址链接到二进制文件中，
// 在有虚函数的类中，多了一个隐身的成员，即虚函数指针（vfptr）,程序在运行的过程中，
// 如果创建了对象，除了给对象的成员分配内存，还会创建一个虚函数表（vftable）,
// 用虚函数指针指向虚函数表。
/*
* 在程序中，如果调用的是普通成员函数，编译器将成员函数地址链接到二进制文件中，直接执行函数
* 如果调用的是虚函数，要先查找虚函数表，得到函数的地址，再执行函数
*/

class Hero {
public:
	int viablity;
	int attack;
	virtual void skill1() { cout << "英雄释放了一技能." << endl; }
	virtual void skill2() { cout << "英雄释放了二技能." << endl; }
	virtual void skill3() { cout << "英雄释放了大招." << endl; }
	Hero() :viablity{ 0 }, attack{ 0 } {  }
};

class XS :public Hero {
public:

	void skill1() { cout << "西施释放了一技能." << endl; }
	void skill2() { cout << "西施释放了二技能." << endl; }
	//void skill3() { cout << "西施释放了大招." << endl; }
};

class HX :public Hero {
public:
	void skill1() { cout << "韩信释放了一技能." << endl; }
	void skill2() { cout << "韩信释放了二技能." << endl; }
	void skill3() { cout << "韩信释放了大招." << endl; }
};

class LB :public Hero {
public:
	void skill1() { cout << "李白释放了一技能." << endl; }
	void skill2() { cout << "李白释放了二技能." << endl; }
	void skill3() { cout << "李白释放了大招." << endl; }
};

int main(void)
{
		// 创建基类指针，让它指向派生类，用基类指针调用派生类的成员函数
		int id = 0;
		cout << "请输入英雄(1:西施  2：韩信 3：李白)：";
		cin >> id;
		// 1:西施  2：韩信 3：李白
		unique_ptr<Hero> ptr;
	
		if (id == 1) {	
			ptr = unique_ptr<XS>(new XS);
		}
		else if (id == 2) {
			ptr = unique_ptr<HX>(new HX);
		}
		else if (id == 3) {
			//ptr=new LB;
			ptr = unique_ptr<LB>(new LB);
		}

		if (ptr != nullptr) {
			ptr->skill1();
			ptr->skill2();
			ptr->skill3();

		}
		
		return 0;
}