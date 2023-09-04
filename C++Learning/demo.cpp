#include <iostream>
using namespace std;

int main(void)
{
	string s1{ "111111111111111111" };
	string s2{ "222222222222222222" };

	cout << "s1的内容：" << s1 << endl;
	cout << "s2的内容：" << s2 << endl;
	cout << "s1动态数组的地址：" << reinterpret_cast<void*>(const_cast<char*>(s1.data())) << endl;
	cout << "s2动态数组的地址：" << reinterpret_cast<void*>(const_cast<char*>(s2.data())) << endl;
	cout << "------------------------------------------" << endl;

	s1.swap(s2);
	cout << "s1的内容：" << s1 << endl;
	cout << "s2的内容：" << s2 << endl;
	cout << "s1动态数组的地址：" << reinterpret_cast<void*>(const_cast<char*>(s1.data())) << endl;
	cout << "s2动态数组的地址：" << reinterpret_cast<void*>(const_cast<char*>(s2.data())) << endl;

	cout << "------------------------------------------" << endl;

	string s3 = s1.substr(0, 3);
	cout << "s3=" << s3 << endl;
}