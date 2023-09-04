#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class AA {
private:
	//mutex m_mutex;
	recursive_mutex m_mutex;	// �ݹ黥����
public:
	void func1() {
		m_mutex.lock();	// �������
		cout << "������funcn1()" << endl;
		m_mutex.unlock();	// ����
	}

	void func2() {
		m_mutex.lock();	// �������
		cout << "������funcn2()" << endl;
		func1();
		m_mutex.unlock();	// ����
	}
};

int main(void)
{
	AA aa;
	//aa.func1();
	aa.func2();	// ��������������ͨ�Ļ����������ڽ���֮����ܼ���
	// func2() �����󣬻�������������״̬����ȥ����func1()��func1()��߲��������뵽���������ͳ�����������
}