#include <iostream>
using namespace std;

//template <typename T1,typename T2>
//void func(T1 x, T2 y)
//{
//	auto temp = x + y;
//	cout << "tmp=" << temp << endl;
//}

int func()
{
	cout << "������func()����" << endl;
	return 3;
}

typedef int (*FP)();
FP ptr = func;

int main(void)
{
//	short a = 3;
//	char b = 2;
//	//auto temp = a + b;
//	func(a, b);

	//! decltype(expression) var;
// 1�����expression��һ��û���������������ı�ʶ������var��������ñ�ʶ����������ͬ������const���޶���������ı�ʶ���� �������ͱ�������������ĳ�Ա����
// 2�����expression��һ���������ã���var�������뺯���ķ���ֵ������ͬ���������ܷ���void�������Է���void * ����
// 3�����expression��һ����ֵ����ȡ��ַ��(Ҫ�ų���һ�����)�������������������ı�ʶ������ôvar��������expression�����á�
// 4���������������������㣬��var��������expression��������ͬ��

	short a = 5;
	short b = 10;
	decltype(a) da=b;

	decltype(func()) fa; 

	decltype(++a) dda=b;
	decltype((a)) daf=b;

	decltype((func)) ffa=func;  // ���ص���func������
	ffa();

	decltype(5) t;


	decltype(func()) g1;	// ����һ��int����
	auto g2 = func();	// ����һ��int���� �� auto dd = ���ʽ�� ��ִ�б��ʽ��ִ�к���func()

	typedef decltype(func()) myint;
	
	ptr();
	return 0;
}


//! ��C++11�У�decltype �����������ڲ�ѯ���ʽ����������
//! �﷨�� decltype(expression) var;
//! decltype�������ʽ���õ��������ͣ��������ִ�б��ʽ����������Ҳ��һ�ֱ��ʽ����˲��ص���ʹ��decltype ʱִ���˺���
//! decltype(���ʽ) �Ľ��Ҫô�ͱ��ʽ������һ����Ҫô�Ǳ��ʽ���͵�����
//! decltype��auto�������Ƶ����ʽ���������ͣ�decltype����ִ�б��ʽ��auto��ִ�б��ʽ