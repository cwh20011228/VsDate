#include "CGirl.h"

CGirl::CGirl()
{
	m_name.clear();
	m_age = 0;
	m_sex = 1;
	cout << "调用了CGirl()构造函数" << endl;
}

CGirl::CGirl(string name)
{
	m_name = name;
	m_age = 0;
	m_sex = 1;
	cout << "调用了CGirl(string name)构造函数。" << endl;
}

CGirl::CGirl(string name, int age)
{
	m_name = name;
	m_age = age;
	m_sex = 1;
	cout << "调用了CGirl(string name,int age)构造函数。" << endl;
}

void CGirl::SetValue(string name, int age, int sex)
{
	m_age = age;
	m_name = name;
	m_sex = sex;
	show();
}

void CGirl::show()
{
	cout << "姓名：" << m_name << " 年龄:" << m_age;
	if (m_sex == girl) cout << " 女孩" << endl;
	else if (m_sex == boy) cout << " 男孩" << endl;
}


CGirl::~CGirl()
{
	cout << "调用了析构函数" << endl;
}

int CGirl::GetAge()
{
	return m_age;
}

void CGirl::SetAge(int age)
{
	m_age = age;
}

void CGirl::InitData()
{
	m_name.clear();
	m_age = 0;
	m_sex = girl;
}