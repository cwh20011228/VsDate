#include <iostream>
#include <chrono>
using namespace std;

int main(void)
{
	// ��̬��Ա���� chrono::steady_clock::now()��ȡ��ʼ��ʱ���
	//chrono::steady_clock::time_point start = chrono::steady_clock::now();
	auto start = chrono::steady_clock::now();

	// ִ��һЩ���룬��������һЩʱ��
	cout << "��ʱ��ʼ....." << endl;
	for (int ii = 0; ii < 1000000; ii++) {
		//cout << "����һֻɵɵ��" << endl;
	}
	cout << "��ʱ����...." << endl;

	// ��̬��Ա���� chrono::steady_clock::now()��ȡ������ʱ���
	//chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();

	// �������ĵ�ʱ��
	auto dt = end - start;
	cout << "��ʱ��" << dt.count() << "���루" << (double)dt.count() / (1000 * 1000 * 1000) << "�룩" << endl;
}