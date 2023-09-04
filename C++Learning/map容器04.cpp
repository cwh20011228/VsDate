#include <iostream>
#include <map>
using namespace std;

class CGirl {
public:
	string m_name;
	int m_age;

	CGirl(const string name, const int age) :m_name{ name }, m_age{ age }
	{
		cout << "两个参数的构造函数" << endl;
	}

	CGirl(const CGirl& g) :m_name{ g.m_name }, m_age{ g.m_age }
	{
		cout << "拷贝构造函数,X" << endl;
	}
};

int main(void)
{
	map<int, CGirl> mm;
	 //mm.insert(pair<int, CGirl>(8, CGirl("冰冰", 18)));  // 一次构造函数，两次拷贝构造函数
	//mm.insert(make_pair<int, CGirl>(8, CGirl("冰冰", 18)));	// 一次构造函数，两次拷贝构造函数
	 mm.emplace(pair<int, CGirl>(8, CGirl("冰冰", 18)));	// 一次构造函数，两次拷贝构造函数
	//mm.emplace(make_pair<int, CGirl>(8, CGirl("冰冰", 18))); // 一次构造函数，两次拷贝构造函数
	//mm.emplace(8, CGirl("冰冰", 18));	// 一次构造函数，一次拷贝构造函数
	//mm.emplace(8, "冰冰", 18);		// 错误
	//mm.emplace(piecewise_construct, forward_as_tuple(8), forward_as_tuple("冰冰", 18)); // 调用了一次构造函数
	// 第一个参数表示分段构造，第二个参数表示用8构造key，第三个参数表示用"冰冰"和18构造value(超女类)
	
	for (auto& val : mm) {
		cout << val.first << " ," << val.second.m_name << " ," << val.second.m_age << "   ";
	}
	cout << endl;
}