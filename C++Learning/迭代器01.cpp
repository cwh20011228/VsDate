#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vv = { 1,2,3,4,5 };
	vector<int>::iterator it1 = vv.begin();		// �����Ŀ�ʼ

	*it1 = 8;	// �޸�vector�����еĵ�0��Ԫ��
	it1++;
	*it1 = 7;	// �޸�vector�����еĵ�1��Ԫ��

	for (auto it2 = vv.cbegin(); it2 != vv.end(); it2++)
	{
		cout << *it2 << endl;
	}
}