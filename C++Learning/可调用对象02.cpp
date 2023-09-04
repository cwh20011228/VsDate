#include <iostream>
using namespace std;

struct CC {
	void show(int bh, const string& message)
	{
		cout << "�װ���" << bh << "��," << message << endl;
	}
};

int main(void)
{
	CC cc;
	cc.show(1, "����һֻɵɵ��");

	//void(*pfun)(int, const string&)=show;	// ��ͨ��Ա������ָ��
	void(CC::*fp)(int, const string&) = &CC::show;	// ������ĳ�Ա������ָ�룬&CC::show ���Ա�����ĵ�ַ��&����ʡ��
	(cc.*fp)(2, "����һֻɵɵ��");	// ����ĳ�Ա������ָ����ó�Ա����

	// C++11����д���
	using Fun = void(CC::*)(int, const string&);	// ���Ա������ָ������
	Fun fp1 = &CC::show;	// ��ĳ�Ա����ָ��ָ����ĳ�Ա�����ĵ�ַ
	(cc.*fp1)(2, "����һֻɵɵ��");	//����ĳ�Ա������ָ����ó�Ա����

	/*auto p = &CC::show;
	(cc.* p)(1, "����һֻɵɵ��");*/

}

