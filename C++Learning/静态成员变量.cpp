#include <iostream>
using namespace std;

class CGirl {
	static  int m_age;
public:
	string m_name;
	
	CGirl(const string& name, int age);
	void ShowName() const;
	static void ShowAge();
};


// ���еľ�̬��Ա����������������ģ��������������ÿ������ʵ���ģ���������Ĺ��캯���ĳ�ʼ���б��в��ܳ�ʼ����ľ�̬��Ա����

CGirl::CGirl(const string& name, int age):m_name{name}
{
	m_age = age;
	cout << "�����˹��캯��CGirl(const string& name, int age)" << endl;
}

void CGirl::ShowName() const
{
	cout << "������" << m_name<<"      "<<m_age << endl;
	ShowAge();
}

void CGirl::ShowAge()
{
	cout << "���䣺" << m_age << endl;

}


int CGirl::m_age=20; // ��ʼ����ľ�̬��Ա����

int main()
{
	
	CGirl g1{ "��ʩ1",23 },g2{"��ʩ2",24},g3{"��ʩ3",25};
	g1.ShowName(); g1.ShowAge();
	g2.ShowName(); g2.ShowAge();
	g3.ShowName(); g3.ShowAge();

	CGirl::ShowAge();
	/*cout << "���䣺" << CGirl::m_age << endl;*/

}