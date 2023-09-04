#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<string, string> m{ { "08","冰冰"}, {"03","西施"}, {"01","蜜蜜"}, {"07","金莲"}, {"05","西瓜"} };
	for (auto& val : m) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "-------------------------------------------------" << endl;

	auto it1 = m.find("05");
	if (it1 != m.end()) {
		cout << "查找成功" << endl;
		cout << it1->first << " ," << it1->second << endl;
	}
	else {
		cout << "查找失败" << endl;
	}
	cout << "-------------------------------------------------" << endl;

	auto it2 = m.lower_bound("05");
	if (it2 != m.end()) {
		cout << "查找成功" << endl;
		cout << it2->first << " ," << it2->second << endl;
	}
	else {
		cout << "查找失败" << endl;
	}
	cout << "-------------------------------------------------" << endl;

	auto it3 = m.upper_bound("05");
	if (it3 != m.end()) {
		cout << "查找成功" << endl;
		cout << it3->first << " ," << it3->second << endl;
	}
	else {
		cout << "查找失败" << endl;
	}
	cout << "-------------------------------------------------" << endl;


	auto num = m.count("05");
	cout << num << endl;
}