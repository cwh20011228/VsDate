#include "CGirl.h"

CGirl::CGirl()
{
	m_name.clear();
	m_age = 0;
	m_sex = 1;
	cout << "������CGirl()���캯��" << endl;
}

CGirl::CGirl(string name)
{
	m_name = name;
	m_age = 0;
	m_sex = 1;
	cout << "������CGirl(string name)���캯����" << endl;
}

CGirl::CGirl(string name, int age)
{
	m_name = name;
	m_age = age;
	m_sex = 1;
	cout << "������CGirl(string name,int age)���캯����" << endl;
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
	cout << "������" << m_name << " ����:" << m_age;
	if (m_sex == girl) cout << " Ů��" << endl;
	else if (m_sex == boy) cout << " �к�" << endl;
}


CGirl::~CGirl()
{
	cout << "��������������" << endl;
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