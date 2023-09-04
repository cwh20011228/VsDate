#include <iostream>
#include <vector>
using namespace std;

class AA {
public:
	string m_name;
	AA() { cout << "默认构造函数AA()" << endl; }
	AA(const string& name) :m_name{ name } { cout << "构造函数，name=" << m_name << endl; }
	AA(const AA& a) :m_name{ a.m_name } { cout << "拷贝构造函数，name=" << m_name << endl; }
	AA& operator=(const AA& a) { m_name = a.m_name; cout << "赋值函数，name=" << m_name << endl; }
	~AA() { cout << "析构函数，name=" << m_name << endl; }

};
int main(void)
{
	
	/*int vv[]= { 1,2,3,4,5,6,7,8,9,10 };*/

	/*for (auto it = vv.begin(); it != vv.end(); ++it) {
		cout << *it << "  ";
	}
	cout << endl;*/
	vector<int> vv = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto val : vv)	//用基于范围的for循环遍历容器vv,把容器中的元素逐个赋值给val
	{
		cout << val<<"  ";
		vv.push_back(10);
	}
	cout << endl;

	vector<AA> v;
	cout << "0000,v.capacity()=" << v.capacity() << endl;
	v.emplace_back("西施");
	cout << "1111,v.capacity()=" << v.capacity() << endl;
	v.emplace_back("冰冰");
	// vector容器进行了扩容，扩容分为四个步骤：
	// 1）分配新的可以存放两个元素的内存空间
	// 2）构造新插入的元素冰冰，调用了构造函数AA(const string& name)
	// 3）把西施从原来的内存空间拷过来，调用了拷贝构造函数AA(const AA& a)
	// 4）释放原来的内存空间，调用了析构函数
	cout << "2222,v.capacity()=" << v.capacity() << endl;
	v.emplace_back("蜜蜜");
	cout << "3333,v.capacity()=" << v.capacity() << endl;
	for (const auto &a:v)
	{
		cout << a.m_name << "  ";
	}
	cout << endl;
}