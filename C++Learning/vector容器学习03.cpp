#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<vector<int>> vv;		// ������һ��vector������Ԫ�ص�����������vector<int>

	vector<int> v;		// ������һ������v,����Ϊ����vv��Ԫ��

	v = { 1,2,3,4,5 };		// ��ͳһ��ʼ���б������v��ֵ
	vv.push_back(v);		// ��v����׷��׷�ӵ�vv����β��


	v = { 1,2,3,4,5,6,7,8,9,10 };
	vv.push_back(v);

	v = { 21,22,23 };
	vv.push_back(v);

	for (int ii = 0; ii < vv.size(); ii++) {
		for (int jj = 0; jj < vv[ii].size(); jj++) {
			cout << vv[ii][jj] << "  ";
		}
		cout << endl;
	}
	return 0;
}