#include <iostream>
#include <vector>
using namespace std;

class AA {
public:
	string m_name;
	AA() { cout << "Ĭ�Ϲ��캯��AA()" << endl; }
	AA(const string& name) :m_name{ name } { cout << "���캯����name=" << m_name << endl; }
	AA(const AA& a) :m_name{ a.m_name } { cout << "�������캯����name=" << m_name << endl; }
	AA& operator=(const AA& a) { m_name = a.m_name; cout << "��ֵ������name=" << m_name << endl; }
	~AA() { cout << "����������name=" << m_name << endl; }

};
int main(void)
{
	
	/*int vv[]= { 1,2,3,4,5,6,7,8,9,10 };*/

	/*for (auto it = vv.begin(); it != vv.end(); ++it) {
		cout << *it << "  ";
	}
	cout << endl;*/
	vector<int> vv = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto val : vv)	//�û��ڷ�Χ��forѭ����������vv,�������е�Ԫ�������ֵ��val
	{
		cout << val<<"  ";
		vv.push_back(10);
	}
	cout << endl;

	vector<AA> v;
	cout << "0000,v.capacity()=" << v.capacity() << endl;
	v.emplace_back("��ʩ");
	cout << "1111,v.capacity()=" << v.capacity() << endl;
	v.emplace_back("����");
	// vector�������������ݣ����ݷ�Ϊ�ĸ����裺
	// 1�������µĿ��Դ������Ԫ�ص��ڴ�ռ�
	// 2�������²����Ԫ�ر����������˹��캯��AA(const string& name)
	// 3������ʩ��ԭ�����ڴ�ռ俽�����������˿������캯��AA(const AA& a)
	// 4���ͷ�ԭ�����ڴ�ռ䣬��������������
	cout << "2222,v.capacity()=" << v.capacity() << endl;
	v.emplace_back("����");
	cout << "3333,v.capacity()=" << v.capacity() << endl;
	for (const auto &a:v)
	{
		cout << a.m_name << "  ";
	}
	cout << endl;
}