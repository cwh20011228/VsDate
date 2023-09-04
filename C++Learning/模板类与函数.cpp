#include <iostream>
using namespace std;

//! ģ����������ں����ͷ���ֵ����������ʽ��
//! ��1����ͨ�����������ͷ���ֵ��ģ�����ʵ�����汾
//! ��2������ģ�壬�����ͷ���ֵ��ĳ�ֵ�ģ����
//! ��3������ģ�壬�����ͷ���ֵ���������ͣ�֧����ͨ���ģ������������ͣ�

template <class T1,class T2>
class AA {
public:
	T1 m_x;
	T2 m_y;
	AA(const T1 x,const T2 y):m_x{x},m_y{y} { }
	void show() const { cout << "show()  x=" << m_x << "  y=" << m_y << endl; }
};

class BB {
public:
	void show() { cout << "������BB()��show()����" << endl; }
};

// ��ͨ�����������ͷ���ֵ��ģ����AA��ʵ�����汾
AA<int,string> func(AA<int,string>& aa)
{
	aa.show();
	cout << "������func(AA<int,string>& aa)����" << endl;
	return aa;
}

// (1)����ģ�壬�����ͷ���ֵ��ģ����AA
template <typename T1,typename T2>
AA<T1, T2> func(AA<T1, T2>& aa)
{
	aa.show();
	cout << "������func(AA<T1, T2>& aa)����" << endl;
	return aa;
}


// (2)����ģ�壬�����ͷ���ֵ��ģ����AA��
template <typename T>
T func(T& aa)
{
	aa.show();
	cout << "������func(T& aa)����" << endl;
	return aa;
}

//TODO: ��1�������ȼ���(2)�ߣ����ǣ�1��ֻ֧��AA��һģ�壬��2��֧������ģ���࣬��ͨ��Ҳ֧��

int  main(void)
{
	AA<int, string> a('x', "����һֻɵɵ��");
	func(a);

	BB b;
	func(b);
	return 0;
}


