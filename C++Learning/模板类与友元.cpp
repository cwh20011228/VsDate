#include <iostream>
using namespace std;

//TODO: ����ģ����Ĳ������Զ�������Ԫ����
template <class T1,class T2>
class AA {
	//friend void show(const AA<char, string>& a);
private:
	T1 m_x;
	T2 m_y;
public:
	AA(const T1 x,const T2 y):m_x{x},m_y{y} { }
	//TODO: ��ģ����Ԫ����Ԫ��������ģ�庯������������ģ�������ɵĺ�����ֻ��������ʵ�֡�
	friend void show(const AA<T1, T2>& a)
	{
		cout << "x=" << a.m_x << "   y=" << a.m_y << endl;
	}
};



int main(void)
{
	AA<int, string> aa(88, "����һֻɵɵ��");
	show(aa);

	AA<char, string> bb(88, "����һֻɵɵ��");
	show(bb);

	return 0;
}