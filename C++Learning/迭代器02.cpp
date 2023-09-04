#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	/*vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v2;
	v2.assign(v1.cbegin() + 2, v1.cend() - 3);

	for (auto it = v2.crbegin(); it != v2.crend(); it++)
	{
		cout << *it << "  ";
	}*/

	/*vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto iter = v.insert(v.begin() + 5, 13);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}*/

	/*vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v1={10,11,12,13,14,15,16,17,18,19,20};
	auto iter=v1.insert(v1.begin()+3, v.begin()+2,v.end()-3);
	cout << "新插入的第一个元素是：" << *iter << endl;

	for (auto it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << "  ";
	}*/

	/*vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto v1 = v.erase(v.begin() + 3);

	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << "  ";
	}*/

	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };


	for (auto it = v.begin(); it != v.end();) {
		cout << *it << "  ";
		it=v.erase(it);
	}

}