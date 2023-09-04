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
	cout << "������CGirl()" << endl;
}
// �������ṩ�Ŀ������캯����ǳ����
CGirl::CGirl(const CGirl& gg)
{
	m_age = gg.m_age;
	m_name = gg.m_name;
	// m_ptr = gg.m_ptr; // ǳ����
	m_ptr = new int;  // �������1�������ڴ� 
	// *m_ptr = *gg.m_ptr;	 // ��2�� ��������
	memcpy(m_ptr, gg.m_ptr, sizeof(int)); // (2) ����һ��Ŀ�������
	cout << "������CGirl(const CGirl& gg)" << endl;
}
CGirl::~CGirl()
{
	if (m_ptr != nullptr) { delete m_ptr; m_ptr = nullptr; }
	cout << "������~CGirl()" << endl;
}

void CGirl::show()
{
	cout << "������" << m_name << "  ���䣺" << m_age << " m_ptr=" << m_ptr << "  *m_ptr=" << *m_ptr << endl;
}

void CGirl::SetValue(string name, int age)
{
	m_name = name;
	m_age = age;
	m_ptr = new int{ 3 };
}
// �Կ�ָ��������ǷǷ���
int main(void)
{
	CGirl g1;
	g1.SetValue("��ʩ", 23);

	g1.show();

	CGirl g2{ g1 };
	*g2.m_ptr = 8;
	g1.show();
	g2.show();

	return 0;
}

// �ڶ���������ʱ�򣬲�����Ұָ�룬������