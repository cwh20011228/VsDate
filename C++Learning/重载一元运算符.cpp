#include <iostream>
using namespace std;

// 3）! 逻辑非     4）& 取地址
// 5）~二进制反码  6） * 解引用   7） + 一元加(正号)    8） - 一元求反（负号）

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

CGirl::CGirl() :m_name{ "西施" }, m_ranking{ 5 }
{

}

void CGirl::show() const
{
	cout << "姓名：" << m_name << "  排名：" << m_ranking << endl;
}

//CGirl& CGirl::operator++()
//{
//	m_ranking = m_ranking + 1;
//	return *this;
//}

// 成员中的临时对象不能引用

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


// 非成员函数的重载
CGirl& operator++(CGirl& gg)	// ++i
{
	gg.m_ranking = gg.m_ranking + 1;
	return gg;
}

CGirl operator++(CGirl& gg, int)	// i++
{
	CGirl temp = gg;	//临时对象
	gg.m_ranking = gg.m_ranking + 1;
	return temp;	// 返回临时对象
}

int main(void)
{
	CGirl g1,g2;
	CGirl g3=--(--g1);
	cout << "g3.m_ranking=" << g3.m_ranking << "  g1.m_ranking=" << g1.m_ranking << endl;
	CGirl g4=(g2--)--;
	cout << "g4.m_ranking=" << g4.m_ranking << "  g2.m_ranking=" << g2.m_ranking << endl;

	// 前置的++和--可以嵌套，后置的++和--不能嵌套
	int ii = 5;
	int jj = 5;
	int xx = --(--(--ii));
	int yy = jj--;
	cout << "xx=" << xx << "  ii=" << ii << endl;
	cout << "yy=" << yy << "  jj=" << jj << endl;

}