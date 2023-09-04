#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<int, string> m;
	// 使用统一初始化列表在容器中插入多个元素
	m.insert({ {8,"冰冰"},{3,"西施"} });
	m.insert({ pair<int, string>{1, "蜜蜜"}, make_pair<int, string>(7, "金莲"), { 5,"西瓜" } });
	m.insert({ {18,"冰冰"},{3,"西施1"} });		//插入{3,"西施1"}失败，因为map封装的是红黑树，key为3已经存在了，所以插入失败

	// 在容器中插入一个元素，返回值pair。first为插入元素的迭代器，second为插入结果
	// pair<iterator,bool> insert(const pair<K,V> value);
	auto ret = m.insert(pair<int, string> {18, "花花"});
	if (ret.second == true) {
		cout << "插入成功"<<"\t";
		cout << ret.first->first << " ," << ret.first->second << endl;
	}
	else {
		cout << "插入失败" << endl;
	}

	// 用迭代器插入一个区间的元素
	// void insert(iterator first,iterator last)
	map<int, string> v{ {2,"张三"},{20,"李四"},{19,"王五"} };
	m.insert(v.begin(), v.end());


	// 将创建新键值对所需的数据作为参数直接传入，map容器将直接构造元素
	// 返回值pair  first是已插入元素的迭代器  second 是插入结果
	// pair<iterator,bool> emplace(...)
	//auto ret1 = m.emplace(pair<int, string>{23, "花花"});
	auto ret1 = m.emplace(23, "花花");
	if (ret1.second == true) {
		cout << "插入成功" << "\t" << ret1.first->first << "  ," << ret1.first->second << endl;
	}
	else {
		cout << "插入失败" << endl;
	}

	m.emplace_hint(m.begin(), piecewise_construct, forward_as_tuple(53), forward_as_tuple("张三三"));

	for (auto& val : m) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	return 0;
}