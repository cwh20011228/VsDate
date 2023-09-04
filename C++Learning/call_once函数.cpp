#include <iostream>
#include <mutex>	// std::call_once()��std::once_flag������Ҫ������ͷ�ļ�
#include <thread>
using namespace std;

once_flag onceflag;	// ����һ��once_flag��ȫ�ֱ�����������ȡֵΪ0��1����

// ���߳��У�����ֻ����һ�Σ�����ֻ�����̵߳��������е��ã�
void once_func(const int bh, const string& str)
{
	cout << "once_func()  bh=" << bh << ",str=" << str << endl;
}

// �ڶ��̵߳ĳ����У�����߳̿�����ͬһ���߳��������������Ļ���ÿ���̶߳���ִ�����д��룬����once_func()����
void func(int bh, const string& str)
{
	call_once(onceflag,once_func,0, "��λ������ү����Ҫ��ʼ�����");

	for (int ii = 1; ii <= 3; ii++) {
		cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
		this_thread::sleep_for(chrono::seconds(1));	// ����1��
	}
}



int main(void)
{
	//����ͨ���������߳�
	thread t1(func, 3, "����һֻɵɵ��");
	thread t2(func, 8, "����һֻСС��");

	t1.detach();	// �������߳�t1
	t2.detach();	// �������߳�t1

	this_thread::sleep_for(chrono::seconds(10));	// ���߳�����10��

}