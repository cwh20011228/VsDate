#include <iostream>
using namespace std;

// C++�У��ַ��������������������������Ͷ������֣��Ǽ��ݵģ������Զ�ת��
// ����һ�������Ĺ��캯�������Զ�ת���������Զ����еģ�����Ҫ��ʾ��ת��
// ��������Ĺ��캯��������һ�������⣬���������������ȱʡֵ����ôҲ������Ϊת������
// ����һ�������Ĺ��캯����ʱ�򣬿���ʹ��explicit�ؼ������ر��Զ�ת��������

class mystring {
private:
	string m_ptr;
public:
	mystring(const string& ss):m_ptr{ss}{ }
	
};

class CGirl {
public:
	int m_bh;
	string m_name;
	double m_weight;

	CGirl();
	void show() const;
	explicit CGirl(int bh);
	explicit CGirl(double weight);
	/*CGirl(int bh, double weight=25.3);*/
};

CGirl::CGirl() 
{
	m_bh = 0;
	m_name.clear();
	m_weight = 0;
	cout << "������CGirl()" << endl;
}

void CGirl::show() const
{
	cout << "bh= " << m_bh << "  name= " << m_name << "  weight=" << m_weight << endl;
}

CGirl::CGirl(int bh)
{
	m_bh = bh;
	m_name.clear();
	m_weight = 0;
	cout << "������CGirl(int bh)" << endl;
}

CGirl::CGirl(double weight)
{
	m_bh = 0;
	m_name.clear();
	m_weight = weight;
	cout << "������CGirl(double weigh)" << endl;
}

//CGirl::CGirl(int bh, double weight )
//{
//	m_bh = bh;
//	m_name.clear();
//	m_weight = weight;
//	cout << "������CGirl(int bh, double weight)" << endl;
//}


void func(CGirl g)
{
	g.show();
}

//CGirl func1(CGirl g)
//{
//	return g.m_bh;
//}

int main(void)
{
	/*string s1 = "����һֻɵɵ��";
	const mystring s2 = s1;*/

	CGirl g1{ 25 };	//�����д��
	CGirl g2 = CGirl{ 26 }; // ��ʾת��
	//CGirl g3 = 'a';	// ��ʽת��
	/*g3.show();*/
	//CGirl g4;	// ��������
	//g4 = 28;	// ��CGirl(8) ������ʱ�����ٸ�ֵ��g4

	/*CGirl g5 = 5;
	g5.show();*/
	//g1.show();
	/*g2.show();*/
	
	//g4.show();

	/*func(3.8);*/
	/*func1(g3);*/

	CGirl g3 =(CGirl)'a';

	return 0;
}


