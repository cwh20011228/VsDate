#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class AA {
public:
	string m_name;
	AA() { cout << m_name << "	调用了构造函数AA()" << endl; }
	AA(const string& name) :m_name(name) { cout << m_name << "	调用了构造函数AA(const string& name)" << endl; }
	~AA() { cout << "调用了析构函数~AA()	" << m_name << endl; }
};


void func(unique_ptr<AA>* pp)
{
	cout << "m_name=" << ( * pp)->m_name << endl;
}

int main(void)
{
	//AA* p = new AA("西施");		// 定义原始指针p,分配内存
	//unique_ptr<AA> pu1(p);
	unique_ptr<AA> pu1(new AA("西施"));		// 创建智能指针对象pu1，用于管理原始指针p

	func(&pu1);
	//cout << "裸指针的值是：         " << p << endl;
	//cout << "pu1输出的值是：        " << pu1 << endl;
	//cout << "pu1.get()输出的结果是：" << pu1.get() << endl;
	//cout << "pu1的地址是：          " << &pu1 << endl;
	////!智能指针就是类，类中有一个成员，管理着原始指针


}