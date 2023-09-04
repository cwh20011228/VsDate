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

	T1 first;   // 第一个成员，一般表示key。

	T2 second; // 第二个成员，一般表示value。

	Pair()    // 默认构造函数。
	{
		cout << "调用了默认构造函数" << endl;
	}
	Pair(const T1& val1, const T2& val2):first{val1},second{val2}  // 有两个参数的构造函数。
	{
		cout << "调用了构造函数Pair(const T1& val1, const T2& val2)" << endl;
	}
	Pair(const pair<T1, T2>& p) :first{ p.first }, second{ p.second }     // 拷贝构造函数。
	{
		cout << "调用了拷贝构造函数" << endl;
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
	//pair<int, string> p0;	// 创建一个空的键值对
	//cout << "p0.first=" << p0.first << " ,p0.second=" << p0.second << endl;
	//cout << "---------------------------------------------" << endl;

	//pair<int, string> p1{ 1,"西施" };	//两个参数的构造函数
	//cout << "p1.first=" << p1.first << " ,p1.second=" << p1.second << endl;
	//cout << "---------------------------------------------" << endl;


	//pair<int, string> p2{ p1 };	//拷贝构造函数
	//cout << "p2.first=" << p2.first << " ,p2.second=" << p2.second << endl;
	//cout << "---------------------------------------------" << endl;

	auto p3 = Pair<int, string>{ 3,"西施" };	//匿名对象
	cout << "p3.first=" << p3.first << " ,p3.second=" << p3.second << endl;
	cout << "---------------------------------------------" << endl;


	auto p5 = make_Pair<int,string>(5, "西施");	//	make_pair返回的对象
	cout << "p5.first=" << p5.first << " ,p5.second=" << p5.second << endl;
	cout << "---------------------------------------------" << endl;

	//auto p6 = make_pair( 6,"西施" );	//慎用，让make_pair()函数自动推导，再调用拷贝构造(p6=make_pair()返回的键值对)
	//cout << "p6.first=" << p6.first << " ,p6.second=" << p6.second << endl;
	//cout << "---------------------------------------------" << endl;

	//pair<int, string> p7 = make_pair(7,"西施");	//慎用，这里让make_pair()函数自动推导，调用了拷贝构造，再隐式转换
	//cout << "p7.first=" << p7.first << " ,p7.second=" << p7.second << endl;
	//cout << "---------------------------------------------" << endl;

	//p5.swap(p7);
	//cout << "p5.first=" << p5.first << " ,p5.second=" << p5.second << endl;
	//cout << "p7.first=" << p7.first << " ,p7.second=" << p7.second << endl;
	//cout << "---------------------------------------------" << endl;


	//// 用pair存放结构体数据
	//pair<int, st_girl> p{ 3,{"西施",23,48.6}};
	//cout << "p.first=" << p.first << endl;
	//cout << "p.second.name=" << p.second.name << endl;
	//cout << "p.second.age=" << p.second.age << endl;
	//cout << "p.second.height=" << p.second.height << endl;

}