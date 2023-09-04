#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;	// 创建一个空的vector容器
	cout << "v.capacity()=" << v.capacity() << "    v.size()=" << v.size() << endl;
	cout << "--------------------------" << endl;


	vector<int> v1(8);	// 创建一个容量为8字节的vector容器
	cout << "v1.capacity()=" << v1.capacity() << "    v1.size()=" << v1.size() << endl;
	cout << "--------------------------" << endl;

	// 使用统一初始化列表创建容器
	vector<int> v4 = {1,5,2,4,3};
	for (int ii = 0; ii < v4.size(); ii++) {
		cout << v4[ii] << "  ";
	}
	cout << endl;
	cout << "--------------------------" << endl;


	v4.data()[0] = 8;	// 数组表示法
	v4.data()[1] = 7;	// 数组表示法
	*(v4.data() + 2) = 5;	// 指针表示法
	*(v4.data() + 3) = 4;	

	for (int ii = 0; ii < v4.size(); ii++) {
		cout << v4[ii] << "  ";
	}
	cout << endl;
	cout << "--------------------------" << endl;

}