#include <iostream>
using namespace std;



// ������Ԫfriend�Ĵ���������ʲô�ط������ԣ�����public��private��Լ����һ�����������

/*
* ��Ԫ��Ա����
* ��1����CGilr�������ǰ��
* ��2����CBoy��Ķ������CGirl��ǰ��
* ��3����CBoy��ĳ�Ա�����ĺ��������Ķ����ó���,���ڶ���CGirl��ĺ���
* ��4����Cboy��ĳ�Ա��������ΪCGirl�����Ԫ����
*/ 

class CGirl;

class CBoy {
public:
	void func1(const CGirl& g);
	void func2(const CGirl& g);
};



class CGirl {
	//friend class CBoy;
	friend void  CBoy::func1(const CGirl& g);
	friend void  CBoy::func2(const CGirl& g);
public:
	string m_name;
	CGirl() :m_name{ "��ʩ" }, m_xw{ 87 }{  };
	void ShowName();
private:
	int m_xw;
	void ShowXw() const;
};


void CGirl::ShowName()
{
	cout << "������" << m_name << endl;
	/*ShowXw();*/
}

void CGirl::ShowXw() const
{
	cout << "Xm=" << m_xw << endl;
}

// ÿ����Ա��������һ��thisָ�룬˭��������this��ָ����

void CBoy::func1(const CGirl& g)
{
	cout << "func1  Xw = " << g.m_xw << endl;
}

void CBoy::func2(const CGirl& g)
{
	cout << "func2  ���� = " << g.m_name << endl;
}




int main(void)
{
	CGirl g;
	CBoy b;
	b.func1(g);
	b.func2(g);
	return 0;
}