#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
	/*list<int> la = { 8,2,6,4,5 };
	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;

	list<int> lb{ 3,7,9,10,1 };
	for (auto& val : lb) {
		cout << val << " ";
	}
	cout << endl;

	auto first = lb.begin();
	first++;
	auto last = lb.end();
	last--;

	la.splice(la.begin(),lb,first,last);

	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;*/

	list<int> la{ 8,2,6,6,6,6,6,6,6,3,6,5 };
	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;

	la.unique();
	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;


}