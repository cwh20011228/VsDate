#include <iostream>
using namespace std;

//Todo: ������������ֻ����ʹ�÷ǳ�Ա����汾����

class CGirl {
	friend ostream& operator<<(ostream& cout,const CGirl& g);
private:
	string m_name;
	int m_xw;
	int m_score;
public:
	CGirl():m_name{"��ʩ"},m_xw{87},m_score{30} { }
	void show();
	//ostream& operator<<(ostream& cout);
};

void CGirl::show()
{
	cout << "������" << m_name << "XW= " << m_xw << "������" << m_score << endl;
}

// todo:��Ա�汾������
//ostream& CGirl::operator<<(ostream& cout)
//{
//	cout << "������" << this->m_name << "XW= " << this->m_xw << "������" << this->m_score;
//	return cout;
//}

ostream& operator<<(ostream& cout, const CGirl& g)
{
	cout<< "������" << g.m_name << "XW= " << g.m_xw << "������" << g.m_score << endl;
	return cout;
}

int main()
{
	CGirl g;
	cout << g << endl;

}