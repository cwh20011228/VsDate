#include <iostream>
using namespace std;

//Todo: 重载左移运算只能能使用非成员运算版本函数

class CGirl {
	friend ostream& operator<<(ostream& cout,const CGirl& g);
private:
	string m_name;
	int m_xw;
	int m_score;
public:
	CGirl():m_name{"西施"},m_xw{87},m_score{30} { }
	void show();
	//ostream& operator<<(ostream& cout);
};

void CGirl::show()
{
	cout << "姓名：" << m_name << "XW= " << m_xw << "分数：" << m_score << endl;
}

// todo:成员版本的重载
//ostream& CGirl::operator<<(ostream& cout)
//{
//	cout << "姓名：" << this->m_name << "XW= " << this->m_xw << "分数：" << this->m_score;
//	return cout;
//}

ostream& operator<<(ostream& cout, const CGirl& g)
{
	cout<< "姓名：" << g.m_name << "XW= " << g.m_xw << "分数：" << g.m_score << endl;
	return cout;
}

int main()
{
	CGirl g;
	cout << g << endl;

}