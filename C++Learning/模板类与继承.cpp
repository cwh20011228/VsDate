//! ģ����̳���ͨ��	(����)
//! ��ͨ��̳�ģ�����ʾ���汾����ģ�����ͨ�����Ͳ���ָ���ˣ�
//! ��ͨ��̳�ģ����	(����)
//! ģ����̳�ģ����
//! ģ����̳�ģ����������Ļ���(������ģ����)


#include <iostream>
using namespace std;

//!? ģ����̳���ͨ�ࣨ��������Ĺ��캯���г�ʼ���б�����ʾ���û��๹�캯����
//TODO: ��ͨ��AA
class AA {
public:
	int m_a;
	//AA() { }
	AA(int a) :m_a{ a } { cout << "������AA�Ĺ��캯��.\n"; }
	void func1() { cout<<"������func1()����:m_a= "<<m_a << endl; }
};


//TODO: ģ����BB
template <class T1,class T2>
class BB :public AA{
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x,const T2 y,int a):m_x{x},m_y{y},AA(a) { cout << "������BB�Ĺ��캯��.\n"; }
	void func2() { cout << "������func2()����: m_x= " << m_x<<", m_y="<<m_y << endl; }
};


int main(void)
{
	BB<int, string> bb{8,"����һֻɵɵ��",3};
	bb.func2();
	bb.func1();

	return 0;
}