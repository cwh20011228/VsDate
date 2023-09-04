#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	// ����һ���յ�map����
	map<int, string> m1;

	// ʹ��ͳһ��ʼ���б�
	map<int, string> m2({{ 8,"����" }, { 3,"��ʩ" }, { 1,"����" }, { 7,"����" }, { 5,"����" }});
	// ��map������������ı���һ����õ�һ�����������
	for (auto& val : m2) {
		cout << val.first << " ," << val.second << "  ";
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// ʹ�ÿ������캯��
	map<int, string> m3=m2;
	for (auto& val : m3) {
		cout << val.first << " ," << val.second << "  ";
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// �õ���������map����
	auto first = m3.begin();	
	first++;
	auto last = m3.end();
	last--;
	
	map<int, string> m4(first, last);
	for (auto& val : m4) {
		cout << val.first << " ," << val.second << "  ";
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;






}