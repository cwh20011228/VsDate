#include <iostream>
using namespace std;

/*
todo: c++编译器可能给类添加四个函数：
	默认构造函数，空实现
	默认析构函数，空实现
	默认拷贝构造函数，浅拷贝
	默认赋值函数，对成员变量进行浅拷贝
*/

class CGirl {
public:
	int m_bh;
	string m_name;
	int* m_ptr;
	void show();
	CGirl& operator=(const CGirl& gg);
	CGirl();
	~CGirl();
};

CGirl::CGirl()
{
	m_ptr = nullptr;
}

CGirl::~CGirl()
{
	if(m_ptr)
		delete m_ptr;
}

// todo: 对空指针解引用，error
void CGirl::show() {
	cout << "编号：" << m_bh << "  姓名：" << m_name<<" ,m_ptr="<<m_ptr<</*"  *m_ptr="<<*m_ptr <<*/ endl;
}

//! 重载赋值函数
CGirl& CGirl::operator=(const CGirl& gg)
{
	if (this == &gg) return *this;
	this->m_bh = gg.m_bh;
	this->m_name = gg.m_name;
	if (gg.m_ptr == nullptr)	// 如果源对象的指针为空，则清空目标对象的内存和指针
	{
		delete m_ptr;
		m_ptr = nullptr;
	}
	else
	{
		if(m_ptr==nullptr) 
			m_ptr = new int;	// 如果目标对象的指针为空，分配内存
		//*m_ptr = *gg.m_ptr;
		memcpy(m_ptr, gg.m_ptr, sizeof(int));  //把源对象内存的数据赋值到目标对象中
	}


	cout << "调用了重载赋值函数" << endl;
	return *this;
}

int main(void)
{
	CGirl g1, g2;
	g1.m_bh = 8;
	g1.m_name = "西施";
	g1.m_ptr = new int{ 3 };
	g1.show();
	g2.show();

	g2 = g1;
	g2.show();
	cout << "*g1.m_ptr=" << *g1.m_ptr << "  *g2.m_ptr" << *g2.m_ptr << endl;
}

/*
* 赋值运算：已存在了两个对象，用一个对象的成员变量的值赋给另一个成员变量。 CGirl g1,g2;  g1=g2;
* 拷贝构造：原来的对象不存在，用已存在的对象进行构造。 CGirl g1;  CGirl g2=g1;
*/