#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
	unordered_map<int, string> m;

	m.insert({ {1,"西施1"},{2,"西施2"},{3,"西施3"},{4,"西施4"} });
	m.insert({ {5,"西施5"},{6,"西施6"},{7,"西施7"},{8,"西施8"} });
	
	// 遍历全部的桶
	for (int ii = 0; ii < m.bucket_count(); ii++) {
		cout << "桶：" << ii << endl;
		for (auto it = m.begin(ii); it != m.end(ii); it++) {
			cout << it->first << " ," << it->second << "   ";
		}
		cout << endl;
	}


	
	m.insert({ {15,"西施15"},{16,"西施16"},{17,"西施17"},{18,"西施18"} });
	m.insert({ {19,"西施19"},{20,"西施20"},{21,"西施21"},{22,"西施22"} });

	cout << "--------------------------------------------------------------" << endl;
	// 遍历全部的桶
	for (int ii = 0; ii < m.bucket_count(); ii++) {
		cout << "桶：" << ii << endl;
		for (auto it = m.begin(ii); it != m.end(ii);it++) {
			cout << it->first << " ," << it->second << "   ";
		}
		cout << endl;
	}
}