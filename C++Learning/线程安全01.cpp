#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// �������������󣬱���������Դaa
mutex mtx;

int aa = 0;	// ����ȫ�ֱ���

// ��ͨ��������ȫ�ֱ���aa��1000000��
void func()
{
	for (int ii = 0; ii < 1000000; ii++) {
		cout << "�߳�" << this_thread::get_id() << "�������" << endl;
		mtx.lock();	// ʹ��֮ǰ������
		cout << "�߳�" << this_thread::get_id() << "�����ɹ�" << endl;
		aa++;
		this_thread::sleep_for(chrono::seconds(5));	// ����5��
		mtx.unlock();	// ʹ��֮�󣬽���
		cout << "�߳�" << this_thread::get_id() << "�ͷ�����" << endl;
		this_thread::sleep_for(chrono::seconds(1));	// ����1��֮���ٻص�forѭ������ȥ�������
	}
}

// �����߳���������ֻ��һ���ɹ�����һ���ڵȴ���5��֮���ͷ������ȴ��е��߳��������ɹ������������߳�֮���л�
int main(void)
{
	//func();
	//func();
	timed_mutex tm;
	tm.try_lock_for(chrono::seconds(10));

	thread t1(func);	// �����߳�t1,��ȫ�ֱ���aa�ӵ�1000000��
	thread t2(func);	// �����߳�t2,��ȫ�ֱ���aa�ӵ�1000000��

	t1.join();	// ����t1����Դ
	t2.join();	// ����t2����Դ

	cout <<"aa= " << aa << endl;
}