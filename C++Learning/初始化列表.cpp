#include <iostream>
using namespace  std;

class CBoy
{
public:
	string m_xm;
	/*CBoy();*/
	CBoy(string xm);
	CBoy(const CBoy& bb);
};

//CBoy::CBoy()
//{
//	m_xm.clear();
//	cout << "������Ĭ�Ϲ��캯��CBoy()" << endl;
//}

CBoy::CBoy(string xm) :m_xm{ xm }
{
	cout << "�����˹��캯��CBoy(string xm)" << endl;
}

CBoy::CBoy(const CBoy& bb) :m_xm{ bb.m_xm }
{
	cout << "�����˿������캯��CBoy(const CBoy& bb)" << endl;
}



class CGirl
{
public:
	CBoy m_boy;
	string m_name;
	const int m_age;
	/*CGirl()
	{
		cout << "������CGirl()Ĭ�Ϲ��캯��" << endl;
	}	*/
	/*CGirl(const CGirl& gg);*/
	CGirl(string name, int age, CBoy& boy);
	void show();
	~CGirl();

};

//CGirl::CGirl(const CGirl& gg) :m_name{ gg.m_name }, m_age{ gg.m_age }
//{
//	cout << "�����˿������캯��CGirl(const CGirl& gg)" << endl;
//}

void CGirl::show()
{
	cout << "������" << m_name << "  ���䣺" << m_age <<"  �����ѣ�"<<m_boy.m_xm << endl;
}

CGirl::~CGirl()
{
	cout << "��������������~CGirl()" << endl;
}

//CGirl::CGirl(string name, int age, CBoy& boy)
//{
//	m_age = age;
//	m_name = name;
//	m_boy.m_xm = boy.m_xm;
//	cout << "�����˹��캯��CGirl(string name,int age,CBoy& boy)" << endl;
//}

//CGirl::CGirl(string name, int age, CBoy& boy) :m_name{ "Ư����" + name }, m_age{ age - 1 }
//{
//	/*m_age = age;
//	m_name = name;*/
//	m_boy.m_xm = boy.m_xm;
//	cout << "�����˹��캯��CGirl(string name,int age,CBoy& boy)" << endl;
//}


CGirl::CGirl(string name, int age, CBoy& boy) :m_name{ "Ư����" + name }, m_age{ age  -1},m_boy{boy}
{
	cout << "�����˹��캯��CGirl(string name,int age,CBoy& boy)" << endl;
}

int main(int argc,char* argv[])
{
	/*CGirl g1;
	g1.show();

	CGirl g2 = g1;
	g2.show();*/
	CBoy boy{ "Jack" };
	CGirl g3("��ʩ", 23,boy);
	g3.show();

}
// ���ഴ�������ʱ���ȳ�ʼ�����캯�����βζ����ٳ�ʼ����ĳ�Ա
// û�в��ó�ʼ���б�����ĳ�ʼ���͸�ֵ��ʼ�����������������õ��ǳ�Ա�����ͨ���캯��
// ���ó�ʼ���б�����ĳ�ʼ���͸�ֵ��ʼ����һ�����������õ��ǳ�Ա��Ŀ������캯��

// ����������ʱ�����ʼ�������ҳ�ʼ����ֵ���ܱ��޸ġ� const int as = 8; 
// ���ñ���������ʱ��ʼ������ʼ�����ܸı�