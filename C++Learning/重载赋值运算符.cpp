#include <iostream>
using namespace std;

/*
todo: c++���������ܸ�������ĸ�������
	Ĭ�Ϲ��캯������ʵ��
	Ĭ��������������ʵ��
	Ĭ�Ͽ������캯����ǳ����
	Ĭ�ϸ�ֵ�������Գ�Ա��������ǳ����
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

// todo: �Կ�ָ������ã�error
void CGirl::show() {
	cout << "��ţ�" << m_bh << "  ������" << m_name<<" ,m_ptr="<<m_ptr<</*"  *m_ptr="<<*m_ptr <<*/ endl;
}

//! ���ظ�ֵ����
CGirl& CGirl::operator=(const CGirl& gg)
{
	if (this == &gg) return *this;
	this->m_bh = gg.m_bh;
	this->m_name = gg.m_name;
	if (gg.m_ptr == nullptr)	// ���Դ�����ָ��Ϊ�գ������Ŀ�������ڴ��ָ��
	{
		delete m_ptr;
		m_ptr = nullptr;
	}
	else
	{
		if(m_ptr==nullptr) 
			m_ptr = new int;	// ���Ŀ������ָ��Ϊ�գ������ڴ�
		//*m_ptr = *gg.m_ptr;
		memcpy(m_ptr, gg.m_ptr, sizeof(int));  //��Դ�����ڴ�����ݸ�ֵ��Ŀ�������
	}


	cout << "���������ظ�ֵ����" << endl;
	return *this;
}

int main(void)
{
	CGirl g1, g2;
	g1.m_bh = 8;
	g1.m_name = "��ʩ";
	g1.m_ptr = new int{ 3 };
	g1.show();
	g2.show();

	g2 = g1;
	g2.show();
	cout << "*g1.m_ptr=" << *g1.m_ptr << "  *g2.m_ptr" << *g2.m_ptr << endl;
}

/*
* ��ֵ���㣺�Ѵ���������������һ������ĳ�Ա������ֵ������һ����Ա������ CGirl g1,g2;  g1=g2;
* �������죺ԭ���Ķ��󲻴��ڣ����Ѵ��ڵĶ�����й��졣 CGirl g1;  CGirl g2=g1;
*/