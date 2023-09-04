#include <iostream>
#include <unordered_map>
using namespace std;

template <class K,class V>
using umap = std::unordered_map<K, V>;	// umap��unordered_map�ı���

int main(void)
{
	// ����һ���յ�umap����
	umap<int, string> m;

	// ʹ��ͳһ��ʼ���б�
	umap<int, string> m2{ { 8,"����"}, {3,"��ʩ"}, {1,"����"}, {7,"����"}, {5,"����"} };


	for (auto& val : m2) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "----------------------------------------" << endl;

	// ʹ�ÿ������캯��
	umap<int, string> m3 = m2;
	for (auto& val : m3) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "----------------------------------------" << endl;

	// ʹ�õ�����
	umap<int, string> m4(++m3.begin(), m3.end()--);
	for (auto& val : m4) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
}