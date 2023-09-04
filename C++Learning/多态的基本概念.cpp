#include <iostream>
using namespace std;
// 如果想发生多态，基类中的虚函数与派生类中重定义的函数。特征必须相同，派生类中的重载函数不算
class CAllComers {
public:
	int m_bh=0;
	 virtual void show();
	 virtual void show(int a);
};

void CAllComers::show()
{
	cout << "CAllComers::show():我是" << m_bh << "号。" << endl;
}


void CAllComers::show(int a)
{
	cout << "CAllComers::show(int a):我是" << m_bh << "号。" << endl;
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
	cout << "CGirl::show():我是" << m_bh << "号，" << m_age<<"岁。"<<endl;

}

void CGirl::show(int a)
{
	cout << "CGirl::show(int a):我是" << m_bh << "号，" << m_age << "岁。" << endl;
}

void CGirl::func()
{
	cout << "调用了func()函数。" << endl;
}

// 有了虚函数，基类指针指向基类对象时就使用基类的成员函数和数据，
// 基类指针指向派生类对象时，就使用派生类的成员函数和数据
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