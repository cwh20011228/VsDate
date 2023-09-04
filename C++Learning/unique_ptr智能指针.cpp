#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class AA {
public:
	string m_name;
	AA() { cout <<m_name<< "	调用了构造函数AA()" << endl; }
	AA(const string& name) :m_name(name) { cout << m_name << "	调用了构造函数AA(const string& name)" << endl; }
	~AA() { cout << "调用了析构函数~AA()	" << m_name << endl; }
};

int main(void)
{
	///*AA* p = new AA("西施");*/
	//unique_ptr<AA> pu1(new AA("西施"));
	//// 模板参数AA表示需要管理的普通指针的基类型（指向的对象的数据类型）是AA，p表示被管理的指针，p指向了new出来的对象的地址
	//// 间接的意思是让智能指针pu1来管理对象
	//// 智能指针是类，有析构函数，在它的析构函数中使用了delete语句
	//// 智能指针重载了 * 和 -> 操作符，像使用普通指针一样使用智能指针

	//cout << "m_name=" << (*pu1).m_name << endl;
	//cout << "m_name=" << pu1->m_name << endl;

	//AA* p = new AA("西施");
	//unique_ptr<AA> pu2(p);

	////TODO: 错误
	//unique_ptr<AA> pu3 = p;		//ERROR，不能把普通指针直接赋值给智能指针（智能指针的构造函数是explicit修饰，不能用于转换函数）
	//unique_ptr<AA> pu4 = new AA("西施"); //error, 不能把普通指针直接赋值给智能指针（
	//
	//unique_ptr <AA> pu5 = pu1;	// error,禁用拷贝构造函数，不能用其他智能指针拷贝构造

	//unique_ptr<AA> pu6;
	//pu6 = pu1;					// error ,不能用 = 对unique_ptr进行赋值
	////! unique_ptr的设计目标是独享对象，即一个unique_ptr对象只对一个资源负责。
	////! 如果unique_ptr对象允许复制，那么会出现多个unique_ptr对象指向同一块内存的情况，当其中一个unique_ptr对象过期的时候，释放内存；其他的unique_ptr对象过期的时候，又会释放内存，造成的结果是对同一块内存释放多次，就成了操作野指针。
	////TODO: 错误

	// 裸指针就是普通指针，也叫原始指针
	// 在实际开发中，如果使用了智能指针，最好不要使用裸指针
	AA* p = new AA("西施");
	unique_ptr<AA> pu1(p);
	unique_ptr<AA> pu2(p);
	unique_ptr<AA> pu3(p);
	return 0;
}