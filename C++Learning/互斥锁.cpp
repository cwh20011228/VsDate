#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;	// �������������󣬱���������Դcout����

//��ͨ����
void func(int bh, const string& str)
{
	for (int ii = 1; ii <= 10; ii++) {
		// ���߳��У�ÿ��ʹ��coutȫ�ֶ���֮ǰ���������
		mtx.lock(); // �������
		cout << "��" << ii << "�α�ף��װ���" << bh << "�ţ�" << str << endl;
		mtx.unlock();	// �����˾ͽ���
		this_thread::sleep_for(chrono::seconds(1));	// ����1��
	}
}
// cout��ȫ�ֶ���ÿ���̶߳�ʹ��������Ļ������ݣ������ͬһʱ���ж���߳�ʹ��cout����ô������е���
//! �û������� ȫ�ֶ���cout ����

int main(void)
{
	//����ͨ���������߳�
	thread t1(func, 1, "����һֻɵɵ��");
	thread t2(func, 2, "����һֻɵɵ��");
	thread t3(func, 3, "����һֻɵɵ��");
	thread t4(func, 4, "����һֻɵɵ��");
	thread t5(func, 5, "����һֻɵɵ��");


	t1.join();	// ����t1����Դ
	t2.join();	// ����t2����Դ
	t3.join();	// ����t3����Դ
	t4.join();	// ����t4����Դ
	t5.join();	// ����t5����Դ

}