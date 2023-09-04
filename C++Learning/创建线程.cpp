#include <iostream>
#include <thread>
#include <Windows.h>
using namespace std;

// ��ͨ����
void func(int bh, const string& str)
{
	for (int ii = 1; ii <= 10; ii++) {
		cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
		Sleep(1000);	// ����1��
	}
}

class mythread1 {
public:
	void operator()(int bh, const string& str)
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			Sleep(1000);	// ����1��
		}
	}
};


class mythread2 {
public:
	static void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			Sleep(1000);	// ����1��
		}
	}
};

class mythread3 {
public:
	void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			Sleep(1000);	// ����1��
		}
	}
};

//! main�����еĴ�������������̻߳�������
//! ����t1�����̡߳����߳�ֻ��һ�������߳̿����кܶ࣬��������Ӳ����Դ�йأ���ͨ�ĵ��Կ��Դ������ٸ����̣߳��õķ��������Դ�����ǧ�����̣߳�

int main(void)
{	
//TODO: ����һ��ִ��func()�����е�����һ��ִ��main�����е���������������ͬʱִ�е�
	
	thread t1(func, 3, "����һֻɵɵ��");
	thread t2(func, 8, "����һֻСС��");

	t1.detach(); t2.detach();	// �����߳�t1��t2�����ȥ
	// ��Lambda���������߳�
	auto f = [](int bh, const string& str)->void
	{
		for (int ii = 1; ii <= 10; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			Sleep(1000);	// ����1��
		}
	};
	//thread t3(f, 3, "����һֻɵɵ��");

	// �÷º��������߳�
	//thread t4(mythread1(), 3, "����һֻɵɵ��");	// ��һ�������÷º�������������

	// ����ľ�̬��Ա�����߳�
	//thread t5(mythread2::func, 3, "����һֻɵɵ��");	// ��ľ�̬��Ա��������ͨ������������һ����

	// �������ͨ���������߳�
	//mythread3 myth;	// �����ȴ�����Ķ��󣬱��뱣֤������������ڱ����߳�Ҫ��
	//thread t6(&mythread3::func,&myth, 3, "����һֻɵɵ��");	
	// ��һ���������Ա�����ĵ�ַ���ڶ������������ĵ�ַ����thisָ��

	//cout << "����ʼ" << endl;
	//for (int ii = 0; ii < 12; ii++) {
	//	cout << "ִ��������..." << endl;
	//	Sleep(1000);
	//}
	//cout << "�������" << endl;
	////return 0;

	//t1.join();	// �����߳�t1����Դ
	//t2.join();	// �����߳�t2����Դ
	//t3.join();	//�����߳�t3����Դ
	//t4.join();		//�����߳�t4����Դ
	//t5.join();		//�����߳�t5����Դ
	//t6.join();	

	// ���߳����˳�ǰ���������̵߳���Դ
	Sleep(12000);
}