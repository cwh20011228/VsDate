#include <iostream>
using namespace std;
// ����뷢����̬�������е��麯�������������ض���ĺ���������������ͬ���������е����غ�������
class CAllComers {
public:
	int m_bh=0;
	 virtual void show();
	 virtual void show(int a);
};

void CAllComers::show()
{
	cout << "CAllComers::show():����" << m_bh << "�š�" << endl;
}


void CAllComers::show(int a)
{
	cout << "CAllComers::show(int a):����" << m_bh << "�š�" << endl;
}

class CGirl:public CAllComers {
public:
	int m_age = 0;
	void show();
	void show(int a);
	void func();
};

void CGirl::show()
{
	cout << "CGirl::show():����" << m_bh << "�ţ�" << m_age<<"�ꡣ"<<endl;

}

void CGirl::show(int a)
{
	cout << "CGirl::show(int a):����" << m_bh << "�ţ�" << m_age << "�ꡣ" << endl;
}

void CGirl::func()
{
	cout << "������func()������" << endl;
}

// �����麯��������ָ��ָ��������ʱ��ʹ�û���ĳ�Ա���������ݣ�
// ����ָ��ָ�����������ʱ����ʹ��������ĳ�Ա����������
int main(void)
{
	/*CGirl g;
	g.m_bh = 8;
	g.m_age = 23;
	g.show();

	CAllComers* pa = &g;
	pa->show();*/

	CAllComers a; a.m_bh = 3;
	CGirl g;	  g.m_bh = 8; g.m_age = 23;

	CAllComers* p;
	//p = &a;	p->show();
	p = &g; p->show();
	p->CAllComers::show(3);

	/*CAllComers& q = g;	q.show();
	CAllComers& rq = a;	rq.show();*/
	

	return 0;
}