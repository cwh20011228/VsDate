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
	cout << "������CGirl(const string& name,int age)���캯��" << endl;
}

void CGirl::show1() const
{
	m_name = "����show1";
	cout << "������" << m_name << "  ���䣺" << m_age << endl;
	show2();
}

void CGirl::show2() const
{
	m_name = "����show2";
	cout << "������" << m_name << "  ���䣺" << m_age << endl;
}

void CGirl::show3() 
{
	m_name = "����show3";
	cout << "������" << m_name << "  ���䣺" << m_age << endl;
	show1();
	show4();
}

void CGirl::show4() 
{
	m_name = "����show4";
	cout << "������" << m_name << "  ���䣺" << m_age << endl;
}

int main(void)
{
	//CGirl g1{ "���",18 };
	//g1.show1();

	const CGirl g1{ "Jack",32 };
	g1.show1();
	/*g1.show3();*/

}