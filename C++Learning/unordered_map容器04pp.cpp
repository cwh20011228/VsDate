#include <iostream>
#include <unordered_map>
using namespace std;

int main(void)
{
	unordered_map<int, string> m;
	m.max_load_factor(2);	//�������װ������
	cout << "���װ�����ӣ�" << m.max_load_factor() << endl << endl;;

	m.insert({{1,"��ʩ1"},{2,"��ʩ2"},{3,"��ʩ3"},{4,"��ʩ4"}});
	cout << "��ǰͰ����" << m.bucket_count() << endl;
	cout << "��ǰװ�����ӣ�" << m.load_factor() << endl;

	cout << "-----------------------------------------------" << endl;

	m.insert({ {5,"��ʩ5"},{6,"��ʩ6"},{7,"��ʩ7"},{8,"��ʩ8"} });
	cout << "��ǰͰ����" << m.bucket_count() << endl;
	cout << "��ǰװ�����ӣ�" << m.load_factor() << endl;

	cout << "-----------------------------------------------" << endl;

	m.insert({ {15,"��ʩ15"},{16,"��ʩ16"},{17,"��ʩ17"},{18,"��ʩ18"} });
	m.insert({ {19,"��ʩ19"},{20,"��ʩ20"},{21,"��ʩ21"},{22,"��ʩ22"} });
	m.insert({ 9,"��ʩ9" });
	cout << "��ǰͰ����" << m.bucket_count() << endl;
	cout << "��ǰװ�����ӣ�" << m.load_factor() << endl;


	return 0;
}