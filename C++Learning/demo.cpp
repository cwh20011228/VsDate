#include <iostream>
using namespace std;

int main(void)
{
	string s1{ "111111111111111111" };
	string s2{ "222222222222222222" };

	cout << "s1�����ݣ�" << s1 << endl;
	cout << "s2�����ݣ�" << s2 << endl;
	cout << "s1��̬����ĵ�ַ��" << reinterpret_cast<void*>(const_cast<char*>(s1.data())) << endl;
	cout << "s2��̬����ĵ�ַ��" << reinterpret_cast<void*>(const_cast<char*>(s2.data())) << endl;
	cout << "------------------------------------------" << endl;

	s1.swap(s2);
	cout << "s1�����ݣ�" << s1 << endl;
	cout << "s2�����ݣ�" << s2 << endl;
	cout << "s1��̬����ĵ�ַ��" << reinterpret_cast<void*>(const_cast<char*>(s1.data())) << endl;
	cout << "s2��̬����ĵ�ַ��" << reinterpret_cast<void*>(const_cast<char*>(s2.data())) << endl;

	cout << "------------------------------------------" << endl;

	string s3 = s1.substr(0, 3);
	cout << "s3=" << s3 << endl;
}