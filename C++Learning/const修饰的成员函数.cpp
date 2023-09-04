#include <iostream>
using namespace std;

class CGirl {
public:
	mutable string m_name;
	int m_age;
	CGirl(const string& name, int age);
	void show1() const;
	void show2() const;
	void show3() ;
	void show4() ;
};

CGirl::CGirl(const string& name, int age):m_name{name},m_age{age}
{
	cout << "调用了CGirl(const string& name,int age)构造函数" << endl;
}

void CGirl::show1() const
{
	m_name = "冰冰show1";
	cout << "姓名：" << m_name << "  年龄：" << m_age << endl;
	show2();
}

void CGirl::show2() const
{
	m_name = "冰冰show2";
	cout << "姓名：" << m_name << "  年龄：" << m_age << endl;
}

void CGirl::show3() 
{
	m_name = "冰冰show3";
	cout << "姓名：" << m_name << "  年龄：" << m_age << endl;
	show1();
	show4();
}

void CGirl::show4() 
{
	m_name = "冰冰show4";
	cout << "姓名：" << m_name << "  年龄：" << m_age << endl;
}

int main(void)
{
	//CGirl g1{ "彬彬",18 };
	//g1.show1();

	const CGirl g1{ "Jack",32 };
	g1.show1();
	/*g1.show3();*/

}