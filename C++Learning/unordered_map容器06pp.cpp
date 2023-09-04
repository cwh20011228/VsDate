#include <iostream>
#include <unordered_map>
using namespace std;

template <class K,class V>
using umap = std::unordered_map<K, V>;

int main(void)
{
	cout << "��ʼ����unordered_map��" << time(0) << endl;
	umap<int, string> m(10000000);
	for (int ii = 0; ii < 10000000; ii++) {
		//m.insert({ii, "��ʩ"});
		m.emplace(ii, "��ʩ" );
	}
	cout << "����unordered_map��ɣ�" << time(0) << endl;
	return 0;
}