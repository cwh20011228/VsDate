#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;	// ����һ���յ�vector����
	cout << "v.capacity()=" << v.capacity() << "    v.size()=" << v.size() << endl;
	cout << "--------------------------" << endl;


	vector<int> v1(8);	// ����һ������Ϊ8�ֽڵ�vector����
	cout << "v1.capacity()=" << v1.capacity() << "    v1.size()=" << v1.size() << endl;
	cout << "--------------------------" << endl;

	// ʹ��ͳһ��ʼ���б�������
	vector<int> v4 = {1,5,2,4,3};
	for (int ii = 0; ii < v4.size(); ii++) {
		cout << v4[ii] << "  ";
	}
	cout << endl;
	cout << "--------------------------" << endl;


	v4.data()[0] = 8;	// �����ʾ��
	v4.data()[1] = 7;	// �����ʾ��
	*(v4.data() + 2) = 5;	// ָ���ʾ��
	*(v4.data() + 3) = 4;	

	for (int ii = 0; ii < v4.size(); ii++) {
		cout << v4[ii] << "  ";
	}
	cout << endl;
	cout << "--------------------------" << endl;

}