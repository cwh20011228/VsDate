//TODO: ģ����̳�ģ����������Ļ��ࣨ���಻����ģ���ࣩ

#include <iostream>
using namespace std;

class AA {
public:
	AA() { cout << "������AA�Ĺ��캯��AA().\n"; }
	AA(int a) { cout << "������AA�Ĺ��캯��AA(int a).\n"; }
};

class BB {
public:
	BB() { cout << "������BB�Ĺ��캯��BB().\n"; }
	BB(int a) { cout << "������BB�Ĺ��캯��BB(int a).\n"; }
};


class CC {
public:
	CC() { cout << "������CC�Ĺ��캯��CC().\n"; }
	CC(int a) { cout << "������CC�Ĺ��캯��CC(int a).\n"; }
};


template <class T>
class DD {
public:
	DD() { cout << "������DD�Ĺ��캯��DD().\n"; }
	DD(int a) { cout << "������DD�Ĺ��캯��DD(int a).\n"; }
};

template <class T>
class EE:public T {	
public:	//! �����ǲ�ȷ���ģ�������Ϊ����������
	EE():T() { cout << "������EE�Ĺ��캯��EE().\n"; }
	EE(int a):T(a) { cout << "������EE�Ĺ��캯��EE(int a).\n"; }
};

int main(void)
{
	EE<AA> ea1;
	EE<BB> eb1;
	EE<CC> ec1;
	EE<DD<int>> ed1;	// DD��ģ���࣬Ҳ������Ϊ���࣬��������ȷָ��ģ����DD����������

	return 0;
}