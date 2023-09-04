#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// 传统的思想是 传对象的地址或引用，只能满足某种类型的容器
// 模板的思想是 传迭代器，函数可以支持多种容器，只要它有迭代器就行了

template <typename T>
void love(const T& str)
{
	cout << "亲爱的" << str << "号，我是一只傻傻鸟" << endl;;
}

template <class T>
class czs {
public:
	void operator()(const T& str)
	{
		cout << "亲爱的" << str << "号，我是一只傻傻鸟" << endl;;
	}

};

//template <typename T>
//void foreach(const T first, const T last,void (*pfunc)(const string&))
//{
//	for (auto it = first; it != last; ++it) {
//		pfunc(*it);	// 以超女对象编号为实参回调用户自定义的函数
//	}
//}
//
//
//template <typename T>
//void foreach(const T first, const T last, czs& pfunc)
//{
//	for (auto it = first; it != last; ++it) {
//		pfunc(*it);	// 以超女对象为实参调用类的operator()函数
//	}
//}

// 将上面两个模板合并成一个模板
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
//		cout << "亲爱的" << *it << "号，我是一只傻傻鸟" << endl;;
//	}
//}

int main(void)
{
	vector<int> bh = { 5,8,2,6,9,3,1,7 };
	//vector<string> bh = { "05","08","02","06","09","03","01","07" };
	//list<string> bh = { "05","08","02","06","09","03","01","07" };	//list容器不支持随机访问

	for_each(bh.begin(), bh.end(), czs<int>()); //支持vector容器的元素的类型为其他数据类型，支持其他容器

	for_each(bh.begin(), bh.end(),love<int> );

	return 0;
}