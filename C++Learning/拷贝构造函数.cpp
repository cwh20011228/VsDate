#include <iostream>
using namespace std;

class CGirl {
public:
	string m_name;
	int m_age;
	CGirl();
	~CGirl();
	void show();
	void SetValue(string name, int age);
	CGirl(const CGirl& g,int ii);
};

CGirl::CGirl() {
	m_name.clear();
	m_age = 0;
	cout << "The constructor CGirl() was called." << endl;
}

void CGirl::show()
{
	cout << "姓名:" << m_name << " 年龄:" << m_age << endl;
}

CGirl::~CGirl()
{
	cout << "The destructor ~CGirl() was called." << endl;
}

void CGirl::SetValue(string name, int age)
{
	m_name = name;
	m_age = age;
}

CGirl::CGirl(const CGirl& g,int ii)
{
	m_name = "漂亮的"+g.m_name;
	m_age = g.m_age-ii;
	cout << "The Copy constructor CGirl(const CGirl& g,int ii) was called." << endl;
}


//void func(CGirl g)
//{
//	g.show();
//}

CGirl func1() {
	CGirl gg;
	gg.m_age = 24;
	gg.m_name = "Hjsa";
	cout << "对象gg的地址是" << &gg << endl;
	return gg;
	
}

int main(void)
{
	CGirl g1;
	g1.SetValue("Jack", 25);

	//CGirl g2(g1,3);
	CGirl g2(g1);
	g2.show();
	//func(g1);

	/*CGirl g = func1();
	g.show();
	cout << "对象g的地址是" << &g << endl;*/
	return 0;
}