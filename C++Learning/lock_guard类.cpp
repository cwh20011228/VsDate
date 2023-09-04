#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;	// ����������������ȫ�ֱ���aa

int aa = 0;	// ����ȫ�ֱ���

// ��ͨ��������ȫ�ֱ���aa��1000000��
void func()
{
	for (int ii = 0; ii < 1000000; ii++) {
		lock_guard<mutex> mlock(mtx);
		aa++;
	}
}

int main(void)
{
	//func();
	//func();

	thread t1(func);	// �����߳�t1,��ȫ�ֱ���aa�ӵ�1000000��
	thread t2(func);	// �����߳�t2,��ȫ�ֱ���aa�ӵ�1000000��

	t1.join();	// ����t1����Դ
	t2.join();	// ����t2����Դ

	cout << "aa= " << aa << endl;
}