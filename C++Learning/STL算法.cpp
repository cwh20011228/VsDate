#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// ��ͳ��˼���� ������ĵ�ַ�����ã�ֻ������ĳ�����͵�����
// ģ���˼���� ������������������֧�ֶ���������ֻҪ���е�����������

template <typename T>
void love(const T& str)
{
	cout << "�װ���" << str << "�ţ�����һֻɵɵ��" << endl;;
}

template <class T>
class czs {
public:
	void operator()(const T& str)
	{
		cout << "�װ���" << str << "�ţ�����һֻɵɵ��" << endl;;
	}

};

//template <typename T>
//void foreach(const T first, const T last,void (*pfunc)(const string&))
//{
//	for (auto it = first; it != last; ++it) {
//		pfunc(*it);	// �Գ�Ů������Ϊʵ�λص��û��Զ���ĺ���
//	}
//}
//
//
//template <typename T>
//void foreach(const T first, const T last, czs& pfunc)
//{
//	for (auto it = first; it != last; ++it) {
//		pfunc(*it);	// �Գ�Ů����Ϊʵ�ε������operator()����
//	}
//}

// ����������ģ��ϲ���һ��ģ��
template <typename T1,typename T2>
void foreach(const T1 first, const T1 last, T2 pfunc)
{
	for (auto it = first; it != last; ++it) {
		pfunc(*it);
	}
}

//void foreach(const vector<string>::iterator first, const vector<string>::iterator last)
//{
//	for (auto it = first; it != last; ++it) {
//		cout << "�װ���" << *it << "�ţ�����һֻɵɵ��" << endl;;
//	}
//}

int main(void)
{
	vector<int> bh = { 5,8,2,6,9,3,1,7 };
	//vector<string> bh = { "05","08","02","06","09","03","01","07" };
	//list<string> bh = { "05","08","02","06","09","03","01","07" };	//list������֧���������

	for_each(bh.begin(), bh.end(), czs<int>()); //֧��vector������Ԫ�ص�����Ϊ�����������ͣ�֧����������

	for_each(bh.begin(), bh.end(),love<int> );

	return 0;
}