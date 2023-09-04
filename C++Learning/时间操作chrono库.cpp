#include <iostream>
#include <chrono>
using namespace std;

int main(void)
{
	//chrono::hours t1(1);	// 1Сʱ
	//chrono::minutes t2(60);	// 60����
	//chrono::seconds t3(60 * 60);	// 60*60��
	//chrono::microseconds t4(60 * 60 * 1000);	// 60*60*1000����
	//// durationʱ�䳤���������˸��������������+��-��*��/����֧��ʱ������㣬1Сʱ=60����
	//chrono::microseconds t5(60 * 60 * 1000 * 1000);	// ΢�룬���棺�������
	//chrono::nanoseconds t6(60 * 60 * 1000 * 1000 * 1000);	// ���룬���棺�������
	//
	//if (t1 == t2) cout << "t1==t2" << endl;
	//if (t1 == t3) cout << "t1==t3" << endl;
	//if (t1 == t4) cout << "t1==t4" << endl;

	//// ��ȡʱ�����ڵ�ֵ�����ص���int����
	//cout << "t1=" << t1.count() << endl;
	//cout << "t2=" << t2.count() << endl;
	//cout << "t3=" << t3.count() << endl;
	//cout << "t4=" << t4.count() << endl;

	chrono::seconds t7(1);	// 1��
	chrono::milliseconds t8(1000);	// 1000����
	chrono::microseconds t9(1000 * 1000);	// 1000*1000΢��
	chrono::nanoseconds t10(1000 * 1000 * 1000);	//1000*1000*1000����

	if (t7 == t8) cout << "t7==t8" << endl;
	if (t7 == t9) cout << "t7==t9" << endl;
	if (t7 == t10) cout << "t7==t10" << endl;

	// ��ȡʱ�����ڵ�ֵ
	cout << "t7=" << t7.count() << endl;
	cout << "t8=" << t8.count() << endl;
	cout << "t9=" << t9.count() << endl;
	cout << "t10=" << t10.count() << endl;
}