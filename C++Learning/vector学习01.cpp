#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v1;		// 创建了一个空的vector容器v1
	v1 = { 1,2,3,4,5 };	// 使用统一初始化列表赋值
	for (int ii = 0; ii < v1.size(); ii++) {
		cout << v1[ii] << "  ";
	}
	cout << endl;
	cout << "----------------------------" << endl;

	vector<int> v2;
	v2 = v1;	// 把v1容器赋值给v2容器
	for (int ii = 0; ii < v2.size(); ii++) {
		cout << v2[ii] << "  ";
	}
	cout << endl;
	cout << "----------------------------" << endl;


	vector<int> v3;
	v3.assign({ 1,2,3,4,5 });	// 用assign()函数给当前容器赋值，参数是统一初始化列表
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