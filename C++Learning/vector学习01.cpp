#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v1;		// ������һ���յ�vector����v1
	v1 = { 1,2,3,4,5 };	// ʹ��ͳһ��ʼ���б�ֵ
	for (int ii = 0; ii < v1.size(); ii++) {
		cout << v1[ii] << "  ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	vector<int> v2;
	v2 = v1;	// ��v1������ֵ��v2����
	for (int ii = 0; ii < v2.size(); ii++) {
		cout << v2[ii] << "  ";
	}
	cout << endl;
	cout << "----------------------------" << endl;


	vector<int> v3;
	v3.assign({ 1,2,3,4,5 });	// ��assign()��������ǰ������ֵ��������ͳһ��ʼ���б�
	for (int ii = 0; ii < v3.size(); ii++) {
		cout << v3[ii] << "  ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	vector<int> v4({2,3,4,5,6});
	v4.swap(v3);
	for (int ii = 0; ii < v4.size(); ii++) {
		cout << v4[ii] << "  ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	return 0;
}