#include <iostream>
using namespace std;

// 运行阶段类型识别(RTTI  RunTime Type Identification),为程序再运行阶段确定对象的类型，只适用于包含虚函数的类，
// 多态的思想：基类指针指向派生类对象，如何知道基类指针指向的是哪种派生类对象？（想调用派生类中的非虚函数）
// dynamic_cast 运算符用指向基类的指针来生成派生类的指针

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
	void skill3() { cout << "西施释放了大招." << endl; }
	void show()  { cout << "我是天下第一美女" << endl; }
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
	int id = 0;
	cout << "输入的id:  ";
	cin >> id;

	Hero* ptr = nullptr;
	if (id == 1) {
		ptr = new XS;
	}
	else if (id == 2) {
		ptr = new HX;
	}
	else if (id == 3) {
		ptr = new LB;
	}

	if (ptr != nullptr) {
		ptr->skill1();
		ptr->skill2();
		ptr->skill3();
		// 如果基类指针指向的对象是西施，那么就调用西施的show()函数
		// 想要调用派生类西施show()函数，必须把基类指针转化为派生类西施的指针

		//! typeid() 可以用于多态的场景，用于在运行阶段识别对象的数据模型
		// ptr是基类指针，虽然他指向了XS对象，但是它的类型是Hero指针,所以typeid(ptr)==typeid(XS*)不成立
		XS* xsptr = nullptr;
		if (typeid(ptr)==typeid(XS*) ){
			xsptr = dynamic_cast<XS*>(ptr);
		}

		// 这里不能用指针判断数据类型，应该用指针指向的对象来判断
		if (typeid(*ptr) == typeid(XS) )  {
			xsptr = dynamic_cast<XS*>(ptr);
		}

		// 如果转换成功，返回对象的地址；否则，返回nullptr;
		if (xsptr != nullptr) {
			xsptr->show();
		}
		delete ptr;
	}
	// 使用dynamic_cast的时候，它要查找虚函数表，如果不是多态类型，编译就过不去

	return 0;
}