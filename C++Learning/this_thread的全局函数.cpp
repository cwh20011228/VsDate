// �ڶ��̵߳ĳ����У�ÿ���̶߳���һ��id������ʶ���̣߳��������֤����һ����ÿ���˶��У������ظ�
// ��ͬ�ĳ���ÿ�����У��������߳�id�ǲ�һ����
#include <iostream>
#include <Windows.h>
#include <thread>
using namespace std;


void func(int bh, const string& str)
{
	cout << "���߳�:" << this_thread::get_id() << endl;	// this_thread��ʾ���̵߳�id
	for (int ii = 1; ii <= 10; ii++) {
		cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
		//Sleep(1000);	// ����1��
		this_thread::sleep_for(chrono::seconds(1));	//����1��
	}
}

int main(void)
{
	// ����ͨ���������߳�
	thread t1(func, 3, "����һֻɵɵ��");
	thread t2(func, 8, "����һֻСС��");

	cout << "���߳�t1:" << t1.get_id() << endl;
	cout << "���߳�t2:" << t2.get_id() << endl;

	t1.swap(t2);	// ����t1��t2

	cout <<"���߳�:" << this_thread::get_id() << endl;	// ���д���������������У�this_thread��ʾ���߳�
	
	thread t3 = move(t2);	// t2��ת����Դ�󣬾Ͳ��ٴ����߳��ˣ�join()�ᱨ��t3�Ŵ����߳�

	// ���̶߳����get_id()��Ա������ȡ���̵߳�id
	cout << "���߳�t1:" << t1.get_id() << endl;
	cout << "���߳�t2:" << t2.get_id() << endl;

	t1.join();	// �����߳�t1����Դ
	t3.join();	// �����߳�t3����Դ
}