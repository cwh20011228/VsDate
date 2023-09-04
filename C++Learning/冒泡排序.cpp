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
#include <algorithm>	// STL算法函数
#include <functional>	// STL仿函数
using namespace std;

template <typename T>
bool compasc(const T& left, const T& right)	// 用于升序
{
	/*if (left < right) return true;
	return false;*/
	return left < right;
}

template <class T>
class _creat {
public:
	bool operator()(const T& left, const T& right) {	//仿函数，升序
		return left < right;
	}
};


template <typename T>
bool compdesc(const T& left, const T& right)	// 用于降序
{
	/*if (left > right) return true;
	return false;*/
	return left>right;
}

template <class T>
class _less {
public:
	bool operator()(const T& left, const T& right) {	//仿函数，降序
		return left > right;
	}
};

template <typename T1,typename compare>
void bsort(const T1 first, const T1 last,compare comp)
{
	while (true)
	{
		bool bswap = false;	// 本轮遍历已交换过元素的标识，true 交换过  false 未交换过
		for (auto it = first; ;) {
			auto left = it;		// 左边的元素
			it++;
			auto right = it;	// 右边的元素
			if (right == last) {		// 表示it已经是最后一个元素了
				break;
			}

			// 如果是c++内置的数据类型或字符串，可以用>和< ; 如果是自定义的数据类型，就不能用 < 和 > 了
			//! 要满足用户需求，用 回调程序员自定义的函数
			//if (*left < *right) {	//如果左边的元素比右边大，交换他们的值,升序
			
			// 如果comp()返回true,left排在前面，否则right排在后面
			if (comp(*left, *right) == true) {
				continue;
			}

			auto tmp = *left;
			*left = *right;
			*right = tmp;
			bswap = true;	//一轮遍历已交换元素的标识
		}

		if (bswap == false) {	// 如果在for循环中不曾交换过元素，说明全部的元素已有序
			break;	
		}
	}
	
}


int main(void)
{
	vector<int> bh = { 5,8,2,6,9,33,1,7 };
	//vector<string> bh = { "05","08","02","06","09","01","07","33"};
	
	//bsort(bh.begin(), bh.end(),compdesc<string>);	//普通函数，降序
	//bsort(bh.begin(), bh.end(), compasc<string>);	// 普通函数，升序

	//bsort(bh.begin(), bh.end(), _creat<string>());	//仿函数，升序
	//bsort(bh.begin(), bh.end(), _less<string>());	//仿函数，降序，_less<string>()表示创建你匿名对象
	//bsort(bh.begin(), bh.end(), _less<int>());


	//bsort(bh.begin(), bh.end(), less<int>());	// STL提供的仿函数，升序
	//bsort(bh.begin(), bh.end(), greater<int>());	// STL提供的仿函数，降序

	//sort(bh.begin(), bh.end(), _creat<int>());	// STL提供的算法函数，升序，回调函数是自己写的仿函数
	//sort(bh.begin(), bh.end(), _less<int>());	// STL提供的算法函数，降序，回调函数是自己写的仿函数
	
	//sort(bh.begin(), bh.end(), less<int>());	// STL提供的算法函数，升序，回调函数是STL提供的仿函数
	sort(bh.begin(), bh.end(), greater<int>());	// STL提供的算法函数，降序，回调函数是STL提供的仿函数

	for (auto& val : bh)
	{
		cout << val << " ";
	}
	cout << endl;
}







