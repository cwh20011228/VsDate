#include <iostream>
using namespace std;

using Fun = void(int,const string&);	// ��ͨ�������͵ı���
Fun show;	// ������ͨ����   �൱��   void show(int,const string&);

int main(void)
{
	show(1, "����һֻɵɵ��");	// ֱ�ӵ�����ͨ����

	void(*fp1)(int, const string&)=show;	 //��������ָ�룬ָ����ͨ����
	void(&fr1)(int, const string&) = show;	// �����������ã�������ͨ����
	fp1(2, "����һֻɵɵ��");	// �ú���ָ�������ͨ����
	fr1(3, "����һֻɵɵ��");	// �ú������õ�����ͨ����

	Fun* fp2 = show;	// ��������ָ�룬ָ����ͨ����
	Fun& fr2 = show;	// �����������ã�������ͨ����
	fp2(4, "����һֻɵɵ��");	// �ú���ָ�������ͨ����
	fr2(5, "����һֻɵɵ��");	// �ú������õ�����ͨ����
}

//������ͨ����
void show(int bh, const string& message)
{
	cout << "�װ���" << bh << " ��," << message << endl;
}
