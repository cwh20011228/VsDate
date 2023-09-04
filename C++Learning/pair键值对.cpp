#include <iostream>
using namespace std;

struct st_girl {
	string name;
	int age;
	double height;
};

template <class T1, class T2>

struct Pair

{

	T1 first;   // ��һ����Ա��һ���ʾkey��

	T2 second; // �ڶ�����Ա��һ���ʾvalue��

	Pair()    // Ĭ�Ϲ��캯����
	{
		cout << "������Ĭ�Ϲ��캯��" << endl;
	}
	Pair(const T1& val1, const T2& val2):first{val1},second{val2}  // �����������Ĺ��캯����
	{
		cout << "�����˹��캯��Pair(const T1& val1, const T2& val2)" << endl;
	}
	Pair(const pair<T1, T2>& p) :first{ p.first }, second{ p.second }     // �������캯����
	{
		cout << "�����˿������캯��" << endl;
	}

};

template <class T1, class T2>

Pair<T1, T2> make_Pair(const T1& first, const T2& second)

{
	Pair<T1, T2> t(first,second);
	return t;
	//return Pair<T1, T2>(first, second);

}

int main(void)
{
	//pair<int, string> p0;	// ����һ���յļ�ֵ��
	//cout << "p0.first=" << p0.first << " ,p0.second=" << p0.second << endl;
	//cout << "---------------------------------------------" << endl;

	//pair<int, string> p1{ 1,"��ʩ" };	//���������Ĺ��캯��
	//cout << "p1.first=" << p1.first << " ,p1.second=" << p1.second << endl;
	//cout << "---------------------------------------------" << endl;


	//pair<int, string> p2{ p1 };	//�������캯��
	//cout << "p2.first=" << p2.first << " ,p2.second=" << p2.second << endl;
	//cout << "---------------------------------------------" << endl;

	auto p3 = Pair<int, string>{ 3,"��ʩ" };	//��������
	cout << "p3.first=" << p3.first << " ,p3.second=" << p3.second << endl;
	cout << "---------------------------------------------" << endl;


	auto p5 = make_Pair<int,string>(5, "��ʩ");	//	make_pair���صĶ���
	cout << "p5.first=" << p5.first << " ,p5.second=" << p5.second << endl;
	cout << "---------------------------------------------" << endl;

	//auto p6 = make_pair( 6,"��ʩ" );	//���ã���make_pair()�����Զ��Ƶ����ٵ��ÿ�������(p6=make_pair()���صļ�ֵ��)
	//cout << "p6.first=" << p6.first << " ,p6.second=" << p6.second << endl;
	//cout << "---------------------------------------------" << endl;

	//pair<int, string> p7 = make_pair(7,"��ʩ");	//���ã�������make_pair()�����Զ��Ƶ��������˿������죬����ʽת��
	//cout << "p7.first=" << p7.first << " ,p7.second=" << p7.second << endl;
	//cout << "---------------------------------------------" << endl;

	//p5.swap(p7);
	//cout << "p5.first=" << p5.first << " ,p5.second=" << p5.second << endl;
	//cout << "p7.first=" << p7.first << " ,p7.second=" << p7.second << endl;
	//cout << "---------------------------------------------" << endl;


	//// ��pair��Žṹ������
	//pair<int, st_girl> p{ 3,{"��ʩ",23,48.6}};
	//cout << "p.first=" << p.first << endl;
	//cout << "p.second.name=" << p.second.name << endl;
	//cout << "p.second.age=" << p.second.age << endl;
	//cout << "p.second.height=" << p.second.height << endl;

}