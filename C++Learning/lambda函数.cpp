#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��׺���
void zssshow(const int& no)
{
	cout << "�װ���" << no << "�ţ�����һֻɵɵ��" << endl;
}

// ��׷º���
class czs {
public:
	void operator()(const int& no)
	{
		cout << "�װ���" << no << "�ţ�����һֻɵɵ��" << endl;
	}
};

int main(void)
{
	vector<int> vv = { 5,8,3 };	// ��ų�Ů��ŵ�����

	// ��������������ͨ����
	for_each(vv.begin(), vv.end(), zssshow);

	// �����������Ƿº���
	for_each(vv.begin(), vv.end(), czs());

	auto f = [](const int& no)->double {
		cout << "�װ���" << no << "�ţ�����һֻɵɵ��" << endl;
		return 1.3;
	};
	// ������������Lambda���ʽ
	for_each(vv.begin(), vv.end(),f);
	// ����lambda���ʽ����Ҫ��ǰ׼���ú�����º������õ���ʱ����ʱдһ�δ���
	f(333);		// ��ʹ����ͨ����һ����ʹ��Lambda����
}