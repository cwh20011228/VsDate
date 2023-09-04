#include <iostream>
using namespace std;

//TODO: Լ��ģ����Ԫ��ģ��ʵ����ʱ��ÿ��ʵ���������Ӧһ����Ԫ����(���Ծ��廯��֧�ֶ��ģ����)
template <typename T>
void show(T& a);		//! ��1����ģ����Ķ���ǰ�棬������Ԫ����ģ��

template <class T1,class T2>
class AA {
	friend void show<>(AA<T1, T2>& a);	
	//! (2) ����ģ���У��ٴ�������Ԫ����ģ�壬����ģ��֪��ʵ��������Ԫ����ģ��
private:
	T1 m_x;
	T2 m_y;
public:
	AA(const T1 x,const T2 y):m_x{x},m_y{y} { }

};

template <class T1, class T2>
class BB {
	friend void show<>(BB<T1, T2>& a);
	//! (2) ����ģ���У��ٴ�������Ԫ����ģ�壬����ģ��֪��ʵ��������Ԫ����ģ��
private:
	T1 m_x;
	T2 m_y;
public:
	BB(const T1 x, const T2 y) :m_x{ x }, m_y{ y } { }

};


template <typename T>
void show(T& a)			//! ��2����Ԫ����ģ��Ķ���,�������ڶ��ģ����
{
	cout << "x=" << a.m_x << "   y=" << a.m_y << endl;
}


template <> 
void show(AA<int, string>& a)
{
	cout << "����ģ��ľ��廯 x=" << a.m_x << "   y=" << a.m_y << endl;
}

template <>
void show(BB<int, string>& a)
{
	cout << "����ģ��ľ��廯 x=" << a.m_x << "   y=" << a.m_y << endl;
}

int main(void)
{
	AA<int, string> a(88, "����һֻɵɵ��");
	show(a);

	AA<char, string> b(88, "����һֻɵɵ��");
	show(b);


	BB<int, string> bb(77, "����һֻɵɵ��");
	show(bb);

	BB<char, string> bbb(77, "����һֻɵɵ��");
	show(bbb);
	return 0;
}