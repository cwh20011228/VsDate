#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
	unordered_map<int, string> m;
	m.max_load_factor(2);	//设置最大装填因子
	cout << "最大装载因子：" << m.max_load_factor() << endl << endl;;

	m.insert({{1,"西施1"},{2,"西施2"},{3,"西施3"},{4,"西施4"}});
	cout << "当前桶数：" << m.bucket_count() << endl;
	cout << "当前装填因子：" << m.load_factor() << endl;

	cout << "-----------------------------------------------" << endl;

	m.insert({ {5,"西施5"},{6,"西施6"},{7,"西施7"},{8,"西施8"} });
	cout << "当前桶数：" << m.bucket_count() << endl;
	cout << "当前装填因子：" << m.load_factor() << endl;

	cout << "-----------------------------------------------" << endl;

	m.insert({ {15,"西施15"},{16,"西施16"},{17,"西施17"},{18,"西施18"} });
	m.insert({ {19,"西施19"},{20,"西施20"},{21,"西施21"},{22,"西施22"} });
	m.insert({ 9,"西施9" });
	cout << "当前桶数：" << m.bucket_count() << endl;
	cout << "当前装填因子：" << m.load_factor() << endl;


	return 0;
}