#include <iostream>
#include <map>
using namespace std;

class CGirl {
public:
	string m_name;
	int m_age;

	CGirl(const string name, const int age) :m_name{ name }, m_age{ age }
	{
		cout << "���������Ĺ��캯��" << endl;
	}

	CGirl(const CGirl& g) :m_name{ g.m_name }, m_age{ g.m_age }
	{
		cout << "�������캯��,X" << endl;
	}
};

int main(void)
{
	map<int, CGirl> mm;
	 //mm.insert(pair<int, CGirl>(8, CGirl("����", 18)));  // һ�ι��캯�������ο������캯��
	//mm.insert(make_pair<int, CGirl>(8, CGirl("����", 18)));	// һ�ι��캯�������ο������캯��
	 mm.emplace(pair<int, CGirl>(8, CGirl("����", 18)));	// һ�ι��캯�������ο������캯��
	//mm.emplace(make_pair<int, CGirl>(8, CGirl("����", 18))); // һ�ι��캯�������ο������캯��
	//mm.emplace(8, CGirl("����", 18));	// һ�ι��캯����һ�ο������캯��
	//mm.emplace(8, "����", 18);		// ����
	//mm.emplace(piecewise_construct, forward_as_tuple(8), forward_as_tuple("����", 18)); // ������һ�ι��캯��
	// ��һ��������ʾ�ֶι��죬�ڶ���������ʾ��8����key��������������ʾ��"����"��18����value(��Ů��)
	
	for (auto& val : mm) {
		cout << val.first << " ," << val.second.m_name << " ," << val.second.m_age << "   ";
	}
	cout << endl;
}