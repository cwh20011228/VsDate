#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

int main(void)
{
	//atomic<int> a = 3;	// atomic(T val) noexcept; ת������
	//cout << "a=" << a.load() << endl;	// ��ȡԭ�ӱ�����ֵ
	//a.store(8);	//��8���뵽ԭ�ӱ���
	//cout << "a=" << a.load() << endl;	// ��ȡԭ�ӱ�����ֵ
	//int old;
	//old=a.fetch_add(1);	// ��ԭ�ӱ�����ֵ��1������ԭֵ
	//cout << "a=" << a.load() <<  "   old=" << old << endl;	// a=9  old =8

	//old = a.fetch_sub(3);	// ��ԭ�ӱ�����ֵ��3������ԭֵ
	//cout << "a=" << a.load() << "   old=" << old << endl;	// a=6  old =9

	//old=a.exchange(3);	// ��3���뵽ԭ�ӱ���������ԭֵ
	//cout << "a=" << a.load() << "   old=" << old << endl;

	atomic<int> ii = 3;		// ԭ�ӱ���
	int expect = 4;		//	�ڴ�ֵ
	int val = 5;	// �������ԭ�ӱ�����ֵ

	// �Ƚ�ԭ�ӱ�����ֵ��Ԥ��ֵexcept�����������ֵ��ȣ���val���뵽ԭ�ӱ����У���������true;
	//���������ֵ����ȣ���ԭ�ӱ�����ֵ����Ԥ��ֵ����������false��CASָ��
	bool bret = ii.compare_exchange_strong(expect, val);
	cout << "ii=" << ii << "   expect=" << expect << endl;	// ii=5  expect=3
	cout << bret << endl;



}