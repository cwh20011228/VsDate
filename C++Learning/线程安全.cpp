#include <iostream>
#include <thread>
using namespace std;

//��ͨ����
void func(int bh, const string& str)
{
	for (int ii = 1; ii <= 3; ii++) {
		cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
		this_thread::sleep_for(chrono::seconds(1));	// ����1��
	}
}

// �º���
class mythread1 {
public:
	void operator()(int bh, const string& str)
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// ����1��
		}
	}
};

// ��ľ�̬��Ա����
class mythread2 {
public:
	static void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// ����1��
		}
	}
};

// ��ķǾ�̬��Ա����
class mythread3 {
public:
	void func(int bh, const string& str)
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// ����1��
		}
	}
};

int main(void)
{
	// ����ͨ���������߳�
	thread t1(func, 3, "����һֻɵɵ��");
	thread t2(func, 8, "����һֻСС��");

	//��Lambda���������߳�
	auto f = [](int bh, const string& str)->void
	{
		for (int ii = 1; ii <= 3; ii++) {
			cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
			this_thread::sleep_for(chrono::seconds(1));	// ����1��
		}
	};
	thread t3(f, 3, "����һֻɵɵ��");

	// �÷º��������߳�
	thread t4(mythread1(), 3, "����һֻɵɵ��");

	// ����ľ�̬��Ա���������߳�
	thread t5(mythread2::func, 3, "����һֻɵɵ��");
	
	// ����ķǾ�̬��Ա���������߳�
	mythread3 thd;
	thread t6(&mythread3::func, &thd, 3, "����һֻɵɵ��");
	// ��һ�������ǳ�Ա�����ĵ�ַ���ڶ��������Ƕ���ĵ�ַ����thisָ��

	 // ���̣߳�������
	cout << "����ʼ" << endl;
	for (int ii = 0; ii < 3; ii++) {
		cout << "ִ��������..." << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "�������" << endl;


	t1.join();	// ����t1����Դ
	t2.join();	// ����t2����Դ
	t3.join();	// ����t3����Դ
	t4.join();	// ����t4����Դ
	t5.join();	// ����t5����Դ
	t6.join();	// ����t6����Դ
}