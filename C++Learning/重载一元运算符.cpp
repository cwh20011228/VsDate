#include <iostream>
using namespace std;

// 3��! �߼���     4��& ȡ��ַ
// 5��~�����Ʒ���  6�� * ������   7�� + һԪ��(����)    8�� - һԪ�󷴣����ţ�

class CGirl {
	friend CGirl& operator++(CGirl& gg);
	friend CGirl operator++(CGirl& gg, int);
public:
	string m_name;
	int m_ranking;

	CGirl();
	void show()  const;
	/*CGirl& operator++();*/
	/*CGirl operator++(int);*/
	CGirl& operator--();
	CGirl operator--(int);
};

CGirl::CGirl() :m_name{ "��ʩ" }, m_ranking{ 5 }
{

}

void CGirl::show() const
{
	cout << "������" << m_name << "  ������" << m_ranking << endl;
}

//CGirl& CGirl::operator++()
//{
//	m_ranking = m_ranking + 1;
//	return *this;
//}

// ��Ա�е���ʱ����������

//CGirl CGirl::operator++(int)
//{
//	CGirl temp = *this;
//	m_ranking = m_ranking + 1;
//	return temp;
//}



CGirl& CGirl::operator--()
{
	this->m_ranking = this->m_ranking - 1;
	return *this;
}

CGirl CGirl::operator--(int)
{
	CGirl temp = *this;
	m_ranking = m_ranking - 1;
	return temp;
}


// �ǳ�Ա����������
CGirl& operator++(CGirl& gg)	// ++i
{
	gg.m_ranking = gg.m_ranking + 1;
	return gg;
}

CGirl operator++(CGirl& gg, int)	// i++
{
	CGirl temp = gg;	//��ʱ����
	gg.m_ranking = gg.m_ranking + 1;
	return temp;	// ������ʱ����
}

int main(void)
{
	CGirl g1,g2;
	CGirl g3=--(--g1);
	cout << "g3.m_ranking=" << g3.m_ranking << "  g1.m_ranking=" << g1.m_ranking << endl;
	CGirl g4=(g2--)--;
	cout << "g4.m_ranking=" << g4.m_ranking << "  g2.m_ranking=" << g2.m_ranking << endl;

	// ǰ�õ�++��--����Ƕ�ף����õ�++��--����Ƕ��
	int ii = 5;
	int jj = 5;
	int xx = --(--(--ii));
	int yy = jj--;
	cout << "xx=" << xx << "  ii=" << ii << endl;
	cout << "yy=" << yy << "  jj=" << jj << endl;

}