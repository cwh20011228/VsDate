#include <iostream>
using namespace std;

class CGirl {
	friend bool operator==(const CGirl& g1, const CGirl& g2);
	friend bool operator>(const CGirl& g1,const CGirl& g2);
	friend bool operator<(const CGirl& g1, const CGirl& g2);
private:
	string m_name;
	int m_yz;	//颜值
	int m_sc;	// 身材
	int m_acting;	//演技
public:
	/*bool operator==(const CGirl& g);
	bool operator>(const CGirl& g);
	bool operator<(const CGirl& g);*/
	CGirl(string name, int yz, int sc, int acting) :m_name{ name }, m_yz{ yz }, m_sc{ sc }, m_acting{ acting } { }
};
// 运算符重载的返回值要与运算符本身的含义一致


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

//TODO: 非成员函数版本的重载
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
	CGirl g1{ "西施",1,2,3 }, g2{ "冰冰",3,2,1 };
	if (g1 == g2)
		cout << "西施和冰冰商业价值一样。" << endl;
	else if (g1 > g2)
		cout << "西施商业价值比冰冰大。" << endl;
	else if (g1 < g2)
		cout << "冰冰商业价值比西施大。" << endl;
}