#include <iostream>
using namespace std;

//! �����ṩһ�����廯�ĺ������壬���������ҵ��뺯������ƥ��ľ��廯����ʱ����ʹ�øö��壬����Ѱ��ģ��
//! ����ģ��ͨ�ð汾֮���һ������汾
//! �����Ǻ���ģ�廹�Ǿ��廯���������ǵ������Ͷ�����Էֿ�
//! ����һ����ͨ����������������ͨ����������ģ�壬���廯�ĺ���ģ�壬�Լ����ǵ����ذ汾

template <typename T>
void Swap(T& a, T& b);	// ����ģ�������
//{
//	T temp = a;
//	a = b;
//	b = temp;
//	cout << "������Swap(T& a,T& b)" << endl;
//}

class CGirl {
public:
	int m_bh;
	string m_name;
	int m_ranking;
};

// ΪSwap����ģ��дһ������ĺ�����ר���ڳ�Ů�������ͣ������ǽ���������Ů�����е�������Աm_ranking
//! template<> ���廯��������;
//! ���廯������ ����ֵ�����������β��б��뺯��ģ����ͬ
//! �Ծ��廯������˵�����ܺ������������Ǻ�����Ķ��壬���Ǿ��廯���������ͣ�û��ͨ�õ���������

template<> void Swap<CGirl>(CGirl& g1, CGirl& g2);		//	���廯����������
//template<> void Swap(CGirl& g1, CGirl& g2)	// ����������Ů���������
//{
//	int temp = g1.m_ranking;
//	g1.m_ranking = g2.m_ranking;
//	g2.m_ranking = temp;
//	cout << "������Swap(CGirl& g1, CGirl& g2)" << endl;
//}

int main(void)
{
	int a = 10, b = 20;
	Swap(a, b);
	cout << "a=" << a << "     b=" << b << endl;

	CGirl g1, g2;
	
	g1.m_ranking = 1;
	g2.m_ranking = 2;
	Swap(g1, g2);
	cout << "g1.m_ranking=" << g1.m_ranking << "    g2.m_ranking=" << g2.m_ranking << endl;
	//!  ����������ʵ�����ͣ����������廯����ƥ���ϣ�������ʹ�þ��廯����
	
	return 0;
}


template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
	cout << "������Swap(T& a,T& b)" << endl;
}

template<> void Swap<CGirl>(CGirl& g1, CGirl& g2)
//template<> void Swap(CGirl& g1, CGirl& g2)	// ����������Ů���������
{
	int temp = g1.m_ranking;
	g1.m_ranking = g2.m_ranking;
	g2.m_ranking = temp;
	cout << "������Swap(CGirl& g1, CGirl& g2)" << endl;
}