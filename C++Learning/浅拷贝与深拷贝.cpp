#include <iostream>
using namespace std;

class CGirl {
public:
	string m_name;
	int m_age;
	int* m_ptr;

	CGirl();
	CGirl(const CGirl& gg);
	~CGirl();
	void show();
	void SetValue(string name, int age);
};

CGirl::CGirl()
{
	m_name.clear();
	m_age = 0;
	m_ptr = nullptr;
	cout << "调用了CGirl()" << endl;
}
// 编译器提供的拷贝构造函数是浅拷贝
CGirl::CGirl(const CGirl& gg)
{
	m_age = gg.m_age;
	m_name = gg.m_name;
	// m_ptr = gg.m_ptr; // 浅拷贝
	m_ptr = new int;  // 深拷贝：（1）分配内存 
	// *m_ptr = *gg.m_ptr;	 // （2） 拷贝数据
	memcpy(m_ptr, gg.m_ptr, sizeof(int)); // (2) 复杂一点的拷贝数据
	cout << "调用了CGirl(const CGirl& gg)" << endl;
}
CGirl::~CGirl()
{
	if (m_ptr != nullptr) { delete m_ptr; m_ptr = nullptr; }
	cout << "调用了~CGirl()" << endl;
}

void CGirl::show()
{
	cout << "姓名：" << m_name << "  年龄：" << m_age << " m_ptr=" << m_ptr << "  *m_ptr=" << *m_ptr << endl;
}

void CGirl::SetValue(string name, int age)
{
	m_name = name;
	m_age = age;
	m_ptr = new int{ 3 };
}
// 对空指针解引用是非法的
int main(void)
{
	CGirl g1;
	g1.SetValue("西施", 23);

	g1.show();

	CGirl g2{ g1 };
	*g2.m_ptr = 8;
	g1.show();
	g2.show();

	return 0;
}

// 第二次析构的时候，操作了野指针，程序奔溃