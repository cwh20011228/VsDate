#include <iostream>
using namespace std;

// �����е��麯��һ������ʵ��ȱʡ�ģ�ͨ�õĹ��ܡ�
// �������Ҫȱʡ�ģ�ͨ�õĹ��ܣ��Ͱѻ����е��麯������Ϊ���麯��

class AA {
public:
	AA() { cout << "�����˻����Ĭ�Ϲ��캯��AA()" << endl; }
	virtual void func() = 0 { cout << "�����˻���ĺ���func()" << endl; }
	virtual ~AA() = 0{ cout << "�����˻������������~AA()" << endl; }
};

// �����еĴ���������������Ҫ�ô���ʵ��
// ԭ�򣺵��������������ʱ���������������������destructor,���Զ����û������������
class BB :public AA {
public:
	BB() { cout << "�������������Ĭ�Ϲ��캯��BB()" << endl; }
	void func() { cout << "������������ĺ���func()" << endl; }
	~BB() { cout << "���������������������~BB()" << endl; }
};

int main(void)
{
	BB b;
	AA* p = &b;
	p->func();



	return 0;
}
//class Hero {
//public:
//	int viablity;
//	int attack;
//	virtual void skill1() = 0;
//	virtual void skill2() = 0;
//	virtual void skill3() = 0;
//};
//
//class XS :public Hero {
//public:
//	void skill1() { cout << "��ʩ�ͷ���һ����" << endl; }
//	void skill2() { cout << "��ʩ�ͷ��˶�����" << endl; }
//	void skill3() { cout << "��ʩ�ͷ��˴���" << endl; }
//};
//
//
//int main(void)
//{
//	XS xs;
//	xs.skill1();
//	xs.skill2();
//	xs.skill3();
//	return 0;
//}

