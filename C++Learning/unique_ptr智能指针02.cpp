#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class AA {
public:
	string m_name;
	AA() { cout << "调用了构造函数AA()" << endl; }
	AA(const string& name) :m_name(name) { cout << "调用了构造函数AA(const dtring& name):" << m_name << endl; }
	~AA() { cout << "调用了析构函数~AA()：" << m_name << endl; }

};


unique_ptr<AA> func()
{
	unique_ptr<AA> pp(new AA("西施3"));
	return pp;
}

// 函数func1()需要一个指针，但不对这个指针负责(释放资源的事情，这个函数不管)
void func1(const AA* a)
{
	cout << a->m_name << endl;

}

// 函数func2()需要一个指针，对这个指针负责（ 释放资源的事情由func2()管 ）
void func2(AA* a)
{
	cout << a->m_name << endl;
	delete a;
}

// 函数func3()需要一个unique_ptr对象，不会对这个unique_ptr对象负责
void func3(const unique_ptr<AA>& a)
{
	cout << a->m_name << endl;
}

// 函数func4()需要一个unique_ptr对象，对这个unique_ptr对象负责
void func4(unique_ptr<AA> a)
{
	cout << a->m_name << endl;
}




int main(void)
{
	//AA* parr1 = new AA[2]; // 普通指针数组
	////AA* parr1 = new AA[2]{ string("西施1"),string("西施2") };
	//parr1[0].m_name = "西施1";
	//cout << "parr1[0].m_name= " << parr1[0].m_name << endl;
	//parr1[1].m_name = "西施2";
	//cout << "parr1[1].m_name= " << parr1[1].m_name << endl;
	//delete[] parr1;

	unique_ptr<AA[]> parr1(new AA[2]);	// unique_ptr数组
	// unique_ptr<AA[]> parr1(new AA[2]{string("西施1"),string("西施2")});  // 指定初始化
	parr1[0].m_name = "西施1";
	cout << "parr1[0].m_name= " << parr1[0].m_name << endl;
	parr1[1].m_name = "西施2";
	cout << "parr1[1].m_name= " << parr1[1].m_name << endl;


	
	
}