//TODO: ��ͨ��̳�ģ�����ʵ���汾

#include  <iostream>
using namespace std;

//TODO: ģ����BB
template <class T1, class T2>
class BB {
public:
	T1 m_x;
	T2 m_y;
	BB(const T1 x, const T2 y) :m_x{ x }, m_y{ y } { cout << "������BB�Ĺ��캯��.\n"; }
	void func2() { cout << "������func2()����: m_x= " << m_x << ", m_y=" << m_y << endl; }

};


//TODO: ��ͨ��AA
class AA:public BB<int,string> {
public:
	int m_a;
	AA(int a,const int x,const string y):m_a{a},BB(x,y) { cout << "������AA�Ĺ��캯��.\n"; }
	void func1() { cout << "������func1()����:m_a= " << m_a << endl;  }
};




int main(void)
{
	AA aa(3, 8, "����һֻɵɵ��");
	aa.func1();
	aa.func2();

	return 0;
}