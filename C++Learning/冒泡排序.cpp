//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int num[] = { 1,5,9,6,3,7,11 };
//				1,5,6,3,7,9,11
//				1,5,3,6,7,9,11
//				1,3,5,6,7,9,11
//	int len = sizeof(num) / sizeof(int);
//
//	for (int i = 0; i < len - 1; i++) {
//		for (int j = 0; j < len - i - 1; j++) {
//			if (num[j] > num[j + 1]) {
//				int temp = num[j];
//				num[j] = num[j + 1];
//				num[j + 1] = temp;
//			}
//		}
//	}
//
//	for (auto& val : num) {
//		cout << val << " ";
//	}
//	cout << endl;
//}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>	// STL�㷨����
#include <functional>	// STL�º���
using namespace std;

template <typename T>
bool compasc(const T& left, const T& right)	// ��������
{
	/*if (left < right) return true;
	return false;*/
	return left < right;
}

template <class T>
class _creat {
public:
	bool operator()(const T& left, const T& right) {	//�º���������
		return left < right;
	}
};


template <typename T>
bool compdesc(const T& left, const T& right)	// ���ڽ���
{
	/*if (left > right) return true;
	return false;*/
	return left>right;
}

template <class T>
class _less {
public:
	bool operator()(const T& left, const T& right) {	//�º���������
		return left > right;
	}
};

template <typename T1,typename compare>
void bsort(const T1 first, const T1 last,compare comp)
{
	while (true)
	{
		bool bswap = false;	// ���ֱ����ѽ�����Ԫ�صı�ʶ��true ������  false δ������
		for (auto it = first; ;) {
			auto left = it;		// ��ߵ�Ԫ��
			it++;
			auto right = it;	// �ұߵ�Ԫ��
			if (right == last) {		// ��ʾit�Ѿ������һ��Ԫ����
				break;
			}

			// �����c++���õ��������ͻ��ַ�����������>��< ; ������Զ�����������ͣ��Ͳ����� < �� > ��
			//! Ҫ�����û������� �ص�����Ա�Զ���ĺ���
			//if (*left < *right) {	//�����ߵ�Ԫ�ر��ұߴ󣬽������ǵ�ֵ,����
			
			// ���comp()����true,left����ǰ�棬����right���ں���
			if (comp(*left, *right) == true) {
				continue;
			}

			auto tmp = *left;
			*left = *right;
			*right = tmp;
			bswap = true;	//һ�ֱ����ѽ���Ԫ�صı�ʶ
		}

		if (bswap == false) {	// �����forѭ���в���������Ԫ�أ�˵��ȫ����Ԫ��������
			break;	
		}
	}
	
}


int main(void)
{
	vector<int> bh = { 5,8,2,6,9,33,1,7 };
	//vector<string> bh = { "05","08","02","06","09","01","07","33"};
	
	//bsort(bh.begin(), bh.end(),compdesc<string>);	//��ͨ����������
	//bsort(bh.begin(), bh.end(), compasc<string>);	// ��ͨ����������

	//bsort(bh.begin(), bh.end(), _creat<string>());	//�º���������
	//bsort(bh.begin(), bh.end(), _less<string>());	//�º���������_less<string>()��ʾ��������������
	//bsort(bh.begin(), bh.end(), _less<int>());


	//bsort(bh.begin(), bh.end(), less<int>());	// STL�ṩ�ķº���������
	//bsort(bh.begin(), bh.end(), greater<int>());	// STL�ṩ�ķº���������

	//sort(bh.begin(), bh.end(), _creat<int>());	// STL�ṩ���㷨���������򣬻ص��������Լ�д�ķº���
	//sort(bh.begin(), bh.end(), _less<int>());	// STL�ṩ���㷨���������򣬻ص��������Լ�д�ķº���
	
	//sort(bh.begin(), bh.end(), less<int>());	// STL�ṩ���㷨���������򣬻ص�������STL�ṩ�ķº���
	sort(bh.begin(), bh.end(), greater<int>());	// STL�ṩ���㷨���������򣬻ص�������STL�ṩ�ķº���

	for (auto& val : bh)
	{
		cout << val << " ";
	}
	cout << endl;
}







