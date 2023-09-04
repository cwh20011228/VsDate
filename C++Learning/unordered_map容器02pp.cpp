#include <iostream>
#include <unordered_map>
using namespace std;


int main(void)
{
	unordered_map<int, string> m;
	m.insert({ { 3, "西施" }, {8,"西瓜"}, {1,"扎昂三"} });

	auto it1 = m.insert(pair<int, string> {6,"李四"});
	if (it1.second == true) {
		cout << "插入成功" << "\t";
		cout << it1.first->first << " ," << it1.first->second << endl;
	}
	else {
		cout << "插入失败" << endl;
	}

	unordered_map<int, string> m1(m.begin(), m.end());
	for (auto& val : m1) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;

	m.emplace(piecewise_construct, forward_as_tuple(13), forward_as_tuple("王五"));

	auto num=m.erase(1);
	cout << num << endl;

	m.erase(m.begin());

	for (auto& val : m) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;

	return 0;
}