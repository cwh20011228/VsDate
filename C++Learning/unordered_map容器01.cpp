#include <iostream>
#include <unordered_map>
using namespace std;


int main(void)
{
	unordered_map<int, string> um1{ {3,"西施"},{8,"西瓜"},{1,"扎昂三"} };
	cout << "um1[8]="<<um1[8] << endl;

	cout << "um1[2]=" << um1[2] << endl;
	um1[3] = "李四";
	for (auto& val : um1) {
		cout << val.first << ", " << val.second << "   ";
	}

	
	cout << endl;

	cout << um1.at(8) << endl;

}