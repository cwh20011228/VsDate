#include <iostream>
using namespace std;

int main(void)
{
	int ii = 3;
	double dd = 3.8;
	auto f = [&](const int& no) {
		ii = ii + 2;
		cout << "ii=" << ii << endl;
		//cout << "dd=" << dd << endl;
		cout << "�װ���" << no << "�ţ�����һֻСС��" << endl;
	};

	//! lambda �����ĺ������ڣ�����ֱ��ʹ�ø��������еľֲ�����(��������д�ڲ����б���)
	//! ���Ҫ�������������ڲ����б��а�Ҫ�벶��ı�����д�������м��ö��Ÿ���
	f(8);
	return 0;
}