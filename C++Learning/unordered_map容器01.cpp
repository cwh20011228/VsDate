#include <iostream>
#include <unordered_map>
using namespace std;


int main(void)
{
	unordered_map<int, string> um1{ {3,"��ʩ"},{8,"����"},{1,"������"} };
	cout << "um1[8]="<<um1[8] << endl;

	cout << "um1[2]=" << um1[2] << endl;
	um1[3] = "����";
	for (auto& val : um1) {
		cout << val.first << ", " << val.second << "   ";
	}

	
	cout << endl;

	cout << um1.at(8) << endl;

}