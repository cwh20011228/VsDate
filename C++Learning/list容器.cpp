#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void)
{
	list<int> l1;	//创建一个空的list容器
	cout << "l1.size()=" << l1.size() << endl;
	cout << "-------------------------" << endl;

	list<int> l2{ 1,2,3,4,5,6,7,8,9,10 };		//使用统一初始化列表
	//list<int> l2({ 1,2,3,4,5,6,7,8,9,10 });
	//list<int> l2 = { 1,2,3,4,5,6,7,8,9,10 };
	/*for (auto it = l2.begin(); it != l2.end(); ++it)*/
	for(auto val:l2)
	{
		cout << val << "  ";
	}
	cout <<endl<< "-------------------------" << endl;


	list<int> l3{ l2 };		//使用拷贝构造函数
	for (auto val : l3) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;


	list<int> l4(l3.begin(),l3.end());		// 用迭代器创建List容器
	for (auto val : l4) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;

	vector<int> v1{ 1,2,3,4,5,6,7,8,9,10 };		// 创建vector容器
	list<int> l5(v1.begin()+2, v1.end()-3);		// 用vector容器的迭代器
	for (auto val : l5) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;

	int a1[]= { 1,2,3,4,5,6,7,8,9,10 };
	list<int> l6(a1 + 2, a1 + 10 - 3);	//用数组的指针作为迭代器创建list容器,
	//数组的指针是天然的随机访问迭代器，支持迭代器的操作，但不支持迭代器的那些函数begin,end ...
	for (auto val : l6) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;

	char str[] = "hello world";
	string s1(str + 1, str + 7);	// 字符数组的指针，即随机访问迭代器
	for (auto val : s1) {
		cout << val << "  ";
	}
	cout << endl <<s1<<endl<< "-------------------------" << endl;


	vector<int> v2(l3.begin(), l3.end());	//用list容器的迭代器创建vector容器
	for (auto val : v2)
	{
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;
}