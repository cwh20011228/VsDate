#include<iostream>
#include <vector>
#include <list>
using namespace std;

struct Node
{
	int item;
	Node* next;
};

//int* find_(int* arr, int n, const int& val)	//����������arr�в���ֵΪval��Ԫ��
//{
//	for (int ii = 0; ii < n; ii++) {
//		if (arr[ii] == val) return &arr[ii];
//	}
//
//	return nullptr;
//}
//
//int* find_(int* begin, int* end, const int& val)	//����������������в���ֵΪval��Ԫ��
//{
//	cout << "����2��" << endl;
//	for (int* iter = begin; iter != end; iter++) {
//		if (*iter == val) {
//			return iter;
//		}
//	}
//
//	return nullptr;
//}
//
//Node* find_(Node* begin, Node* end,const Node& val)		// �ڵ������в���ֵΪval��Ԫ��
//{
//	for (Node* iter = begin; iter != end; iter=iter->next) {
//		if (iter->item == val.item) {
//			return iter;
//		}
//	}
//
//	return nullptr;
//}


// ����Ԫ�ص��㷨
template<typename T1,typename T2>
// begin-�������俪ʼ��λ��   end-�������������λ��   val-�����ҵ�ֵ
T1 find_(T1 begin, T1 end, const T2& val)
{
	cout << "ģ��" << endl;
	for (T1 iter = begin; iter != end; iter++) {
		if (*iter == val) {
			return iter;
		}
	}

	return end;
}

int main(void)
{
	// begin() ���������е�һ��Ԫ��ǰ����Ǹ�λ��
	// end() �������������һ��Ԫ�غ�����Ǹ�λ��
	vector<int> vv = { 1,2,3,4,5 };
	vector<int>::iterator it2 = find_(vv.begin(), vv.end(),3);
	if (it2 != vv.end()) {
		cout << "���ҳɹ�" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}



	list<int> ll = { 1,2,3,4,5 };
	list<int>::iterator it3 = find_(ll.begin(), ll.end(), 4);
	if (it3 != ll.end()) {
		cout << "���ҳɹ�" << endl;
	}
	else {
		cout << "����ʧ��" << endl;
	}
}