#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<int, string> m;
	// ʹ��ͳһ��ʼ���б��������в�����Ԫ��
	m.insert({ {8,"����"},{3,"��ʩ"} });
	m.insert({ pair<int, string>{1, "����"}, make_pair<int, string>(7, "����"), { 5,"����" } });
	m.insert({ {18,"����"},{3,"��ʩ1"} });		//����{3,"��ʩ1"}ʧ�ܣ���Ϊmap��װ���Ǻ������keyΪ3�Ѿ������ˣ����Բ���ʧ��

	// �������в���һ��Ԫ�أ�����ֵpair��firstΪ����Ԫ�صĵ�������secondΪ������
	// pair<iterator,bool> insert(const pair<K,V> value);
	auto ret = m.insert(pair<int, string> {18, "����"});
	if (ret.second == true) {
		cout << "����ɹ�"<<"\t";
		cout << ret.first->first << " ," << ret.first->second << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}

	// �õ���������һ�������Ԫ��
	// void insert(iterator first,iterator last)
	map<int, string> v{ {2,"����"},{20,"����"},{19,"����"} };
	m.insert(v.begin(), v.end());


	// �������¼�ֵ�������������Ϊ����ֱ�Ӵ��룬map������ֱ�ӹ���Ԫ��
	// ����ֵpair  first���Ѳ���Ԫ�صĵ�����  second �ǲ�����
	// pair<iterator,bool> emplace(...)
	//auto ret1 = m.emplace(pair<int, string>{23, "����"});
	auto ret1 = m.emplace(23, "����");
	if (ret1.second == true) {
		cout << "����ɹ�" << "\t" << ret1.first->first << "  ," << ret1.first->second << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}

	m.emplace_hint(m.begin(), piecewise_construct, forward_as_tuple(53), forward_as_tuple("������"));

	for (auto& val : m) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
	return 0;
}