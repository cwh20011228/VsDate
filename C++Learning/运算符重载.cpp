#include <iostream>
using namespace std;

class CGirl
{
	friend CGirl& operator+(int score, CGirl& g);
	friend CGirl& operator+(CGirl& g, int score);
	friend CGirl& operator+(CGirl& g, CGirl& g1);
	friend void operator-(CGirl& g, int score);
private:
	int m_xw;
	int m_score;
public:
	string m_name;
	CGirl() :m_name{ "��ʩ" }, m_score{ 30 }, m_xw{ 87 } {  }
	/*CGirl& operator+(int score);*/
	void show();
};

void CGirl::show()
{
	cout << "������" << m_name << "  ������" << m_score << " xw��" << m_xw << endl;
}

//CGirl& CGirl::operator+(int score)	// ��Ա�����汾������
//{
//	this->m_score = this->m_score + score;
//	return *this;
//}

// ����Ѻ�����дΪ operator+ ����ô���ú����Ĵ������дΪ g+30  ����ʽ
// ������ʵ����д���������+�����ߣ�������	operator+(g,30)

// ���ص�������м��������������б��о���Ҫ��������

CGirl& operator+( int score,CGirl& g )
{
	g.m_score = g.m_score + score;
	return g;
}

CGirl& operator+(CGirl& g, int score)
{
	g.m_score = g.m_score + score;
	return g;
}

CGirl& operator+(CGirl& g, CGirl& g1)
{
	g.m_score = g.m_score + g1.m_score;
	return g;
}

void operator-(CGirl& g, int score)
{
	g.m_score = g.m_score - score;
}

void operator+(int a, int b)
{

}
int main(void)
{
	CGirl g;
	//operator+(g,30);s
	//g=g + 20+15;
	//g = operator+(operator+(g, 20), 15);
	g = g+10+20 + g;
	g.show();
	
	g - 30;
	g.show();
}