#include <iostream>
using namespace std;
// TODO: ��Լ��ģ����Ԫ��ģ����ʵ����ʱ�����ʵ������n���࣬Ҳ��ʵ����n����Ԫ������ÿ��ʵ�������඼ӵ��n����Ԫ����
template <class T1,class T2>
class AA {
	template <typename T> friend void show(T& a);
private:
	T1 m_x;
	T2 m_y;
public:
	AA(const T1 x,const T2 y):m_x{x},m_y{y}  { }
 };

template <typename T> void show(T& a)
{
	cout << "x=" << a.m_x << "   y=" << a.m_y << endl;
}

template<>
void show(AA<int, string>& a)
{
	cout << "���廯 x=" << a.m_x << "   y=" << a.m_y << endl;
}


int main(void)
{
	AA<int, string> a(88, "����һֻɵɵ��");
	show(a);

	AA<char, string> a1(88, "����һֻɵɵ��");
	show(a1);


	return 0;
}