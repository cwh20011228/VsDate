#include <iostream>
using namespace std;

class CGirl {
	friend bool operator==(const CGirl& g1, const CGirl& g2);
	friend bool operator>(const CGirl& g1,const CGirl& g2);
	friend bool operator<(const CGirl& g1, const CGirl& g2);
private:
	string m_name;
	int m_yz;	//��ֵ
	int m_sc;	// ���
	int m_acting;	//�ݼ�
public:
	/*bool operator==(const CGirl& g);
	bool operator>(const CGirl& g);
	bool operator<(const CGirl& g);*/
	CGirl(string name, int yz, int sc, int acting) :m_name{ name }, m_yz{ yz }, m_sc{ sc }, m_acting{ acting } { }
};
// ��������صķ���ֵҪ�����������ĺ���һ��


//bool CGirl::operator==(const CGirl& g)
//{
//	if ((this->m_acting + this->m_sc + this->m_yz) == (g.m_acting + g.m_sc + g.m_yz)) return true;
//	return false;
//}
//
//bool CGirl::operator>(const CGirl& g)
//{
//	if ((this->m_acting + this->m_sc + this->m_yz) < (g.m_acting + g.m_sc + g.m_yz)) return true;
//	return false;
//}
//
//bool CGirl::operator<(const CGirl& g)
//{
//	if ((this->m_acting + this->m_sc + this->m_yz) > (g.m_acting + g.m_sc + g.m_yz)) return true;
//	return false;
//}

//TODO: �ǳ�Ա�����汾������
bool operator==(const CGirl& g1, const CGirl& g2)
{
	if ((g1.m_acting + g1.m_sc + g1.m_yz) == (g2.m_acting + g2.m_sc + g2.m_yz)) return true;
	return false;
}

bool operator>(const CGirl& g1, const CGirl& g2)
{
	if ((g1.m_acting + g1.m_sc + g1.m_yz) < (g2.m_acting + g2.m_sc + g2.m_yz)) return true;
	return false;
}

bool operator<(const CGirl& g1, const CGirl& g2)
{
	if ((g1.m_acting + g1.m_sc + g1.m_yz) > (g2.m_acting + g2.m_sc + g2.m_yz)) return true;
	return false;
}

int main()
{
	CGirl g1{ "��ʩ",1,2,3 }, g2{ "����",3,2,1 };
	if (g1 == g2)
		cout << "��ʩ�ͱ�����ҵ��ֵһ����" << endl;
	else if (g1 > g2)
		cout << "��ʩ��ҵ��ֵ�ȱ�����" << endl;
	else if (g1 < g2)
		cout << "������ҵ��ֵ����ʩ��" << endl;
}