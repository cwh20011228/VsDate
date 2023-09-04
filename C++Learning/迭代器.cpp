#include<iostream>
#include <vector>
#include <list>
using namespace std;

struct Node
{
	int item;
	Node* next;
};

//int* find_(int* arr, int n, const int& val)	//在整型数组arr中查找值为val的元素
//{
//	for (int ii = 0; ii < n; ii++) {
//		if (arr[ii] == val) return &arr[ii];
//	}
//
//	return nullptr;
//}
//
//int* find_(int* begin, int* end, const int& val)	//在整型数组的区间中查找值为val的元素
//{
//	cout << "具体2。" << endl;
//	for (int* iter = begin; iter != end; iter++) {
//		if (*iter == val) {
//			return iter;
//		}
//	}
//
//	return nullptr;
//}
//
//Node* find_(Node* begin, Node* end,const Node& val)		// 在单链表中查找值为val的元素
//{
//	for (Node* iter = begin; iter != end; iter=iter->next) {
//		if (iter->item == val.item) {
//			return iter;
//		}
//	}
//
//	return nullptr;
//}


// 查找元素的算法
template<typename T1,typename T2>
// begin-查找区间开始的位置   end-查找区间结束的位置   val-待查找的值
T1 find_(T1 begin, T1 end, const T2& val)
{
	cout << "模板" << endl;
	for (T1 iter = begin; iter != end; iter++) {
		if (*iter == val) {
			return iter;
		}
	}

	return end;
}

int main(void)
{
	// begin() 返回容器中第一个元素前面的那个位置
	// end() 返回容器中最后一个元素后面的那个位置
	vector<int> vv = { 1,2,3,4,5 };
	vector<int>::iterator it2 = find_(vv.begin(), vv.end(),3);
	if (it2 != vv.end()) {
		cout << "查找成功" << endl;
	}
	else {
		cout << "查找失败" << endl;
	}



	list<int> ll = { 1,2,3,4,5 };
	list<int>::iterator it3 = find_(ll.begin(), ll.end(), 4);
	if (it3 != ll.end()) {
		cout << "查找成功" << endl;
	}
	else {
		cout << "查找失败" << endl;
	}
}