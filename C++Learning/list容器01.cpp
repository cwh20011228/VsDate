#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main(void)
{
	list<int> la{ 8,2,6,4,5 };

	for (auto val : la) {
		cout << val << " ";
	}
	cout << endl;

	la.reverse();	// 反转链表
	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;


	la.sort();	// 链表升序排序
	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;

	list<int> lb{ 3,7,9,10,1 };
	lb.sort(); // 链表升序排序

	la.merge(lb);	//归并链表

	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;
}