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

	la.reverse();	// ��ת����
	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;


	la.sort();	// ������������
	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;

	list<int> lb{ 3,7,9,10,1 };
	lb.sort(); // ������������

	la.merge(lb);	//�鲢����

	for (auto& val : la) {
		cout << val << " ";
	}
	cout << endl;
}