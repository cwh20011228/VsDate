
// 一个参数的构造函数只能用于从某种类型到类的转换，如果要进行相反的转换（从类到某种类型），可采用特殊的转换函数
// operator 数据类型();
// 只能是成员函数，不能返回数据类型，不能有参数

#include <iostream>
using namespace std;

class CGirl {
public:
	int m_bh;
	string m_name;
	double m_weight;
	
	CGirl():m_bh{8},m_name{"西施"},m_weight{50.7} { }
	explicit operator int()
	{
		return m_bh;
	}

	explicit operator double()
	{
		return m_weight;
	}

	operator string()
	{
		return m_name;
	}

	int to_int()
	{
		return m_bh;
	}
};

int main(void)
{
	CGirl g;
	// 隐式转换，编译器根据等式左边变量的数据类型，决定调用哪个转换函数
	/*int a = g;*/
	/*string c = g;
	double d = g;*/
	// 显示转换
	/*int a = (int)g;
	string c = (string)g;
	double d = (double)g;*/
	int a = int(g);
	string c = string(g);
	double d = double(g);
	cout << a <<"  "<<c << "  "<<d << endl;
	short e =(int)g;

	int f = g.to_int();
	return 0;
}