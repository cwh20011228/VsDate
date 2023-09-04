#include <iostream>
#include <unordered_map>
using namespace std;

template <class K,class V>
using umap = std::unordered_map<K, V>;	// umap是unordered_map的别名

int main(void)
{
	// 创建一个空的umap容器
	umap<int, string> m;

	// 使用统一初始化列表
	umap<int, string> m2{ { 8,"冰冰"}, {3,"西施"}, {1,"蜜蜜"}, {7,"金莲"}, {5,"西瓜"} };


	for (auto& val : m2) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "----------------------------------------" << endl;

	// 使用拷贝构造函数
	umap<int, string> m3 = m2;
	for (auto& val : m3) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "----------------------------------------" << endl;

	// 使用迭代器
	umap<int, string> m4(++m3.begin(), m3.end()--);
	for (auto& val : m4) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
}