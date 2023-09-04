#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vv = { 1,2,3,4,5 };
	vector<int>::iterator it1 = vv.begin();		// 容器的开始

	*it1 = 8;	// 修改vector容器中的第0个元素
	it1++;
	*it1 = 7;	// 修改vector容器中的第1个元素

	for (auto it2 = vv.cbegin(); it2 != vv.end(); it2++)
	{
		cout << *it2 << endl;
	}
}