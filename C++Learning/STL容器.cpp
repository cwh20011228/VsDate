#include <iostream>
#include <array>
using namespace std;

//void func(int arr[][5], int len)
//void func(int (*arr)[6],int len)
//{
//	for (int ii = 0; ii < 10; ii++) {
//		for (int jj = 0; jj < 6; jj++) {
//			cout << arr[ii][jj] << " ";
//		}
//		cout << endl;
//	}
//}

//void func(const array<array<int, 6>, 10>& arr) 
//{
//	for (int ii = 0; ii < arr.size(); ii++) {
//		for (int jj = 0; jj < arr[ii].size(); jj++) {
//			cout << arr[ii][jj] << " ";
//		}
//		cout << endl;
//	}
//}


template <typename T>
void func(const T& arr)
{
	for (int ii = 0; ii < arr.size(); ii++) {
		for (int jj = 0; jj < arr[ii].size(); jj++) {
			cout << arr[ii][jj] << " ";
		}
		cout << endl;
	}
}


int main(void)
{
	//int aa[11] = { 1,2,3,4,5,6,7,8,9,10 };
	//array<int,10>aa= { 1,2,3,4,5,6,7,8,9,10 };	// һά����

	//for (int ii = 0; ii < 10; ii++) {	// ��ͳ�ķ���
	//	cout << aa[ii] << " ";
	//}
	//cout << endl;

	//for (auto it = aa.begin(); it != aa.end(); it++) {	// ʹ�õ�����
	//	cout << *it << " ";
	//}
	//cout << endl;

	//for (int ii = 0; ii < aa.size(); ii++) {	// ����array��size�ķ���
	//	cout << aa[ii] << " ";
	//}
	//cout << endl;

	//for (auto val : aa) {	//���ڷ�Χ��forѭ��
	//	cout << val << " ";
	//}
	//cout << endl;

	/*int bb[10][6];
	for (int ii = 0; ii < 10; ii++) {
		for (int jj = 0; jj < 6; jj++) {
			bb[ii][jj] = jj * 10 + ii;
		}
	}

	func(bb, 10);*/

	array<array<int, 6>, 10> bb; // ��ά���飬�൱�� int bb[10][5]
	for (int ii = 0; ii < bb.size(); ii++) {
		for (int jj = 0; jj < bb[ii].size(); jj++) {
			bb[ii][jj] = jj * 10 + ii;
		}
	}

	func(bb);
	return 0;
}