#include <iostream>
using namespace std;

//todo: 重载下标运算符[],必须是成员函数的形式重载
class CGirl {
private:
	string m_boys[3];
public:
	string m_name;
	CGirl();
	void show();
	string& operator[](int ii);
	string& boys(int ii);
	const string& operator[](int ii) const;
};

CGirl::CGirl()
{
	m_boys[0] = "子都";
	m_boys[1] = "潘安";
	m_boys[2] = "宋玉";
}

void CGirl::show()
{
	cout << "m_boy[0]" << m_boys[0] << ",  m_boy[1]" << m_boys[1] << ",  m_boy[2]" << m_boys[2] << endl;
}

string& CGirl::operator[](int ii)
{
	return m_boys[ii];
}

const string& CGirl::operator[](int ii) const
{
	return m_boys[ii];
}

string& CGirl::boys(int ii)
{
	return m_boys[ii];
}

int main()
{
	CGirl g1;
	g1[1] = "dcse";
	cout << "g[1]= " << g1[1] << endl;
	g1.show();

	const CGirl g2 = g1;
	cout << "g2[1]= " << g2[2] << endl;
}
