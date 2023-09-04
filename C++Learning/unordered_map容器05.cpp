#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
	unordered_map<int, string> m;

	m.insert({ {1,"��ʩ1"},{2,"��ʩ2"},{3,"��ʩ3"},{4,"��ʩ4"} });
	m.insert({ {5,"��ʩ5"},{6,"��ʩ6"},{7,"��ʩ7"},{8,"��ʩ8"} });
	
	// ����ȫ����Ͱ
	for (int ii = 0; ii < m.bucket_count(); ii++) {
		cout << "Ͱ��" << ii << endl;
		for (auto it = m.begin(ii); it != m.end(ii); it++) {
			cout << it->first << " ," << it->second << "   ";
		}
		cout << endl;
	}


	
	m.insert({ {15,"��ʩ15"},{16,"��ʩ16"},{17,"��ʩ17"},{18,"��ʩ18"} });
	m.insert({ {19,"��ʩ19"},{20,"��ʩ20"},{21,"��ʩ21"},{22,"��ʩ22"} });

	cout << "--------------------------------------------------------------" << endl;
	// ����ȫ����Ͱ
	for (int ii = 0; ii < m.bucket_count(); ii++) {
		cout << "Ͱ��" << ii << endl;
		for (auto it = m.begin(ii); it != m.end(ii);it++) {
			cout << it->first << " ," << it->second << "   ";
		}
		cout << endl;
	}
}