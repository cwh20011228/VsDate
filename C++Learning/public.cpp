#include "public.h"

void Swap(int a, int b)
{
	cout << "ʹ������ͨ����" << endl;
}


template<>
void Swap(int a, int b)
{
	cout << "ʹ���˾��廯�ĺ���ģ��" << endl;
}


