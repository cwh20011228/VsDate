#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	// 创建一个空的map容器
	map<int, string> m1;

	// 使用统一初始化列表
	map<int, string> m2({{ 8,"冰冰" }, { 3,"西施" }, { 1,"蜜蜜" }, { 7,"金莲" }, { 5,"西瓜" }});
	// 对map容器进行正向的遍历一定会得到一个有序的数列
	for (auto& val : m2) {
		cout << val.first << " ," << val.second << "  ";
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// 使用拷贝构造函数
	map<int, string> m3=m2;
	for (auto& val : m3) {
		cout << val.first << " ," << val.second << "  ";
	}
	cout << endl;
	cout << "--------------------------------------------------------" << endl;

	// 用迭代器创建map容器
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