#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<string, string> m{ { "08","����"}, {"03","��ʩ"}, {"01","����"}, {"07","����"}, {"05","����"}};
	cout << "m[08]=" << m["08"] << endl;	// ��ʾkeyΪ8��Ԫ�ص�value
	cout << "m[09]=" << m["09"] << endl;	// ��ʾkeyΪ9��Ԫ�ص�value��KeyΪ9��Ԫ�ز����ڣ�������µļ�ֵ��,key="09",valueΪ��

	m["07"] = "����";	// ��keyΪ7��Ԫ�ص�value�޸�Ϊ����
	m["12"] = "С��";	// ����µļ�ֵ��

	for (auto& val : m) {
		cout << val.first << " ," << val.second << "   ";
	}
	cout << endl;
}