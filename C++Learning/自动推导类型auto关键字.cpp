#include <iostream>
using namespace std;

double func(int a, double b, const char* c, float d, short e, long f)
{
	cout << "a= " << a << "  b=" << b << "  c=" << c << "  d=" << d << "  e=" << e << "   f=" << f << endl;
	return 5.2;
}

int main(void)
{
	double (*funcptr)(int, double, const char* , float , short , long ); //! ��������ָ��funcptr
	funcptr = func;
	funcptr(2, 3.3, "���", 3.6, 2, 8);

	auto funcptr1 = func;	//! �������Ƶ���funcptr1Ϊ ����ָ��double (*funcptr1)(int, double, const char* , float , short , long )
	funcptr1(2, 3.3, "���", 3.6, 2, 8);

	return 0;
}

//! auto�ؼ��ֵ���;��
//! (1) �����߳����ӵı���������eg:��������ָ�룩
//! (2) ��ģ���У�������������ģ������ı���
//! (3) ����ģ������ģ������ķ���ֵ
//! (4) ����lambda���ʽ