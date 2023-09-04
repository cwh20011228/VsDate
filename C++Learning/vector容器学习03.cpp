#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<vector<int>> vv;		// 创建了一个vector容器，元素的数据类型是vector<int>

	vector<int> v;		// 创建了一个容器v,它作为容器vv的元素

	v = { 1,2,3,4,5 };		// 用统一初始化列表给容器v赋值
	vv.push_back(v);		// 将v容器追加追加到vv容器尾部


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