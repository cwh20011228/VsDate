#include "public1.h"
#include "public2.h"
#include <iostream>
using namespace std;

//TODO: �������ռ���ʹ��ȫ�ֱ�����������ʹ���ⲿȫ�ֱ����;�̬����
//TODO: �����������ռ䣬�Ӵ�����λ�õ��ļ�������Ч��

//namespace aa
//{
//	int ab = 1;		//ȫ�ֱ���
//
//	void func1();		// ȫ�ֺ���������
//
//	class A1
//	{
//	public:
//		void show();	// ��ĳ�Ա����
//	};
//
//	void func1()
//	{
//		cout << "������aa::func1()����" << endl;
//	}
//
//	void A1::show()
//	{
//		cout << "������a1::A1::show()����" << endl;
//	}
//
//}
//
//namespace ma = aa;  // ma�������ռ�aa�ı���

namespace		// ���������ռ䣬������ı��������ڵ�ǰ�ļ�ֱ��ʹ��
{
	int ii = 20;
}


int main(void)
{
	cout << "ii=" << ii << endl;

	//TODO: ��һ�ַ�ʽ��  �����ռ�::����
	//cout << "ab=" << aa::ab << endl;
	//aa::func1();
	//aa::A1 a1;
	//a1.show();

	//TODO: �ڶ��ַ�ʽ��  using �����ռ�::����
	//using aa::ab;
	//using aa::A1;
	//using aa::func1;
	//cout << "ab=" << ab << endl;
	//func1();
	//A1 a1;
	//a1.show();

	//TODO: �����ַ�ʽ�� using ����ָ��  using namespace  �����ռ�
	/*using namespace aa;
	cout << "ab=" << ab << endl;
	func1();
	A1 a1;
	a1.show();
	int ab = 50;
	cout << "aa::ab=" << aa::ab << endl;*/

	using namespace aa;
	using namespace bb;
	cout << "ab=" << aa::ab << endl;
	aa::func1();
	aa::A1 a1;
	a1.show();
	cout << "ab=" << bb::ab << endl;
	return 0;

}