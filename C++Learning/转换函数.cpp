
// һ�������Ĺ��캯��ֻ�����ڴ�ĳ�����͵����ת�������Ҫ�����෴��ת�������ൽĳ�����ͣ����ɲ��������ת������
// operator ��������();
// ֻ���ǳ�Ա���������ܷ����������ͣ������в���

#include <iostream>
using namespace std;

class CGirl {
public:
	int m_bh;
	string m_name;
	double m_weight;
	
	CGirl():m_bh{8},m_name{"��ʩ"},m_weight{50.7} { }
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
	// ��ʽת�������������ݵ�ʽ��߱������������ͣ����������ĸ�ת������
	/*int a = g;*/
	/*string c = g;
	double d = g;*/
	// ��ʾת��
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