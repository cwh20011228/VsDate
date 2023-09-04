#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<string, string> m{ { "08","����"}, {"03","��ʩ"}, {"01","����"}, {"07","����"}, {"05","����"} };
	for (auto& val : m) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	cout << "-------------------------------------------------" << endl;

	auto it1 = m.find("05");
	if (it1 != m.end()) {
		cout << "���ҳɹ�" << endl;
		cout << it1->first << " ," << it1->second << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	cout << "-------------------------------------------------" << endl;

	auto it2 = m.lower_bound("05");
	if (it2 != m.end()) {
		cout << "���ҳɹ�" << endl;
		cout << it2->first << " ," << it2->second << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	cout << "-------------------------------------------------" << endl;

	auto it3 = m.upper_bound("05");
	if (it3 != m.end()) {
		cout << "���ҳɹ�" << endl;
		cout << it3->first << " ," << it3->second << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
	cout << "-------------------------------------------------" << endl;


	auto num = m.count("05");
	cout << num << endl;
}