#include <iostream>
using namespace std;

class CGirl {
public:
	string m_name;
	int m_yz;

	CGirl(const string& name, int yz);
	void show() const;
	const CGirl& pk2(const CGirl& gg) const;
};

CGirl::CGirl(const string& name, int yz) :m_name{ name }, m_yz{ yz }
{
	cout << "�����˹��캯��CGirl(const string& name, int yz)" << endl;
}

void CGirl::show() const
{
	cout << "���ǣ�" << m_name << "����Ư���ĳ�Ů��  " << endl;
}

const CGirl& CGirl::pk2(const CGirl& gg) const
{
	if (gg.m_yz < this->m_yz) return gg;
	return *this;
}



int main(void)
{
	CGirl g1{"��ʩ",5}, g2{"����",3},g3{"����",4},g4{"����",5},g5{"����",2};
	const CGirl& g6 = g1.pk2(g2).pk2(g3).pk2(g4).pk2(g5);
	g6.show();
}