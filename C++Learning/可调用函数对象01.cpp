#include <iostream>
using namespace std;

using Fun = void(int, const string&);	// ����ͨ����������һ������

struct AA{
	static void show(int bh, const string& message)
	{
		cout << "�װ���" << bh << "��," << message << endl;
	}
};

int main(void)
{
	AA::show(1, "����һֻɵɵ��");	//ֱ�ӵ���AA�ľ�̬��Ա����

	// c����
	void(*pfun)(int, const string&) = AA::show;		// ��������ָ�룬ָ����ľ�̬��Ա����
	void(&func)(int, const string&) = AA::show;		// �����������ã�������ľ�̬��Ա����

	pfun(2, "����һֻɵɵ��");		// �ú���ָ�������ľ�̬��Ա����
	func(3, "����һֻɵɵ��");		// �ú������õ�����ľ�̬��Ա����

	//C++���
	Fun* pfun1 = AA::show;	// ��������ָ�룬ָ����ľ�̬��Ա����
	Fun& func1 = AA::show;	// �����������ã�������ľ�̬��Ա����
	
	pfun1(2, "����һֻɵɵ��");	// �ú���ָ�������ľ�̬��Ա����
	func1(3, "����һֻɵɵ��");	// �ú������õ�����ľ�̬��Ա����

}