//! ģ������廯���ػ����������������֣���ȫ���廯�Ͳ��־��廯
//! ���廯�̶ȸߵ������ھ��廯�̶ȵ͵��࣬���廯����������û�о��廯����

#include <iostream>
using namespace std;

template <class T1,class T2>
class AA {
public:
	T1 m_x;
	T2 m_y;
	AA(const T1 x, const T2 y) :m_x{ x }, m_y{ y }
	{
		cout << "��ģ�壺���캯����\n";
	}

	void show() const;
};

template <class T1,class T2>
void AA<T1, T2>::show() const 
{
	cout << "��ģ�壺x= " << m_x << "  ,y= " << m_y << endl;
}


//TODO: ��ģ����ȫ���廯

template<>
class AA<int, string> {
public:
	int m_x;
	string m_y;

	AA(const int x, const string y) :m_x{ x }, m_y{ y }
	{
		cout << "��ȫ���廯�����캯��.\n";
	}

	void show() const;
};


void AA<int, string>::show() const
{
	cout << "��ȫ���廯��ģ�壺x= " << m_x << "  ,y= " << m_y << endl;
}


//TODO: ��ģ�岿����ʾ���廯

template<class T1>
class AA<T1, string> {
public:
	T1 m_x;
	string m_y;

	AA(const T1 x, const string y) :m_x{ x }, m_y{ y }
	{
		cout << "���־��廯�����캯��.\n";
	}

	void show() const;
};

template<class T>
void AA<T, string>::show() const
{
	cout << "���־��廯��ģ�壺x= " << m_x << "  ,y= " << m_y << endl;
}


int main(void)
{
	AA<int, string> aa{ 8,"����һֻɵɵ��" };
	aa.show();

	return 0;
}