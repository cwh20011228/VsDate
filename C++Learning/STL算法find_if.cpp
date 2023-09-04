#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
bool love(const T& str)
{
	if (str != 3) return false;
	cout << "亲爱的" << str << "号，我是一只傻傻鸟" << endl;
	return true;
}

template <class T>
class zxc {
public:
	T m_no;
	zxc(const T& no):m_no(no) { }
	bool operator()(const T& str)
	{
		if (str != m_no) return false;
		cout << "亲爱的" << str << "号，我是一只傻傻鸟" << endl;
		return true;
	}
};

template <typename T1,typename T2>
T1 findif(const T1 first, const T1 last, T2 pfunc)
{
	for (auto it = first; it != last; ++it) {
		if (pfunc(*it) == true) {
			return it;
		}
	}
	return last;
}

int main(void)
{
	vector<int> bh = { 5,8,2,6,9,3,1,7 };

	auto it1=find_if(bh.begin(),bh.end(),love<int>);
	if (it1 == bh.end()) {
		cout << "查找失败" << endl;
	}
	else {
		cout << "查找成功：" <<*it1<< endl;
	}

	auto it2 = find_if(bh.begin(), bh.end(), zxc<int>(8));
	if (it2 == bh.end()) {
		cout << "查找失败" << endl;
	}
	else {
		cout << "查找成功：" << *it2 << endl;
	}
	return 0;
}