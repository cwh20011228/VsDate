#include <iostream>
using namespace std;
//TODO: ģ�����еĳ�Աģ�壬����Ĵ������д���������
template <class T1,class T2>
class AA {
public:
	T1 m_x;
	T2 m_y;

	AA(const T1 x,const T2 y):m_x{x},m_y{y} {  }
	void show() { cout << "m_x=" << m_x << "   m_y=" << m_y << endl; }

	template <class T>
	class BB {
	public:
		T m_a;
		T1 m_b;
		BB() { }
		void show(); 
	};

	BB<string> m_bb;

	template <typename T>
	void show(T tt);
	/*{
		cout << "tt=" << tt << endl;
		cout << "m_x=" << m_x << "   m_y=" << m_y << endl;
		m_bb.show();
	}*/
};

template <class T1,class T2>
template <class T>
void AA<T1, T2>::BB<T>::show()
{
	 cout << "m_a=" << m_a << "   m_b=" << m_b << endl; 
}

template <class T1, class T2>
template <typename T>
void AA<T1,T2>::show(T tt)
{
	cout << "tt=" << tt << endl;
	cout << "m_x=" << m_x << "   m_y=" << m_y << endl;
	m_bb.show();
}

int main(void)
{
	AA<int, string> aa(88, "����һֻɵɵ��");
	aa.show();
	aa.m_bb.m_a = "����һֻСС��";
	aa.m_bb.m_b = 77;
	aa.m_bb.show();
	aa.show("����һֻʲô��");

	return 0;
}