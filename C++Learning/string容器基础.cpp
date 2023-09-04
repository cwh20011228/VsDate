#include <iostream>
#include <string>
using namespace std;


int main(void)
{
//	cout << "npos=" << string::npos << endl;

	//TODO: 1）string(); // 创建一个长度为0的string对象（默认构造函数）。

	string s1;
	cout << "s1=" << s1 << endl;
	cout << "s1.capacity()=" << s1.capacity() << endl;	// 返回当前容量，可以存放字符的总数
	cout << "s1.size()=" << s1.size() << endl;	// 返回容器中数据的大小
	cout << "容器动态数组的首地址=" << (void*)s1.c_str() << endl;
	s1 = "xxxxxxxxxxxxxxxxxxxxxxxxxx";	//! string类扩展容器的时候，先分配更大的空间，然后把内容复制到新的空间，释放掉以前的空间
	cout << "s1.capacity()=" << s1.capacity() << endl;	// 返回当前容量，可以存放字符的总数
	cout << "s1.size()=" << s1.size() << endl;	// 返回容器中数据的大小
	cout << "容器动态数组的首地址=" << (void*)s1.c_str() << endl;
	cout << "-------------------" << endl;

	//TODO: 2）string(const char* s); // 将string对象初始化为s指向的NBTS（转换函数）。
	string s2("hello world");
	cout << "s2=" << s2 << endl;
	string s3 = "hello world";
	cout << "s3=" << s3 << endl;
	cout << "-------------------" << endl;


	//TODO: 3）string(const string & str); // 将string对象初始化为str（拷贝构造函数）。
	//! string类中有一个指向动态数组的指针，拷贝构造函数是深拷贝
	string s4(s3);
	cout << "s4=" << s4 << endl;
	string s5 = s3;
	cout << "s5=" << s5 << endl;
	cout << "-------------------" << endl;


	//TODO: 4）string(const char* s, size_t n); 
	// 将string对象初始化为s指向的地址后n字节的内容。不会判断str的结尾标志
	string s6("hello world", 5);
	cout << "s6=" << s6 << endl;
	cout << "s6.capacity()=" << s6.capacity() << endl;
	cout << "s6.size()=" << s6.size() << endl;
	string s7("hello world", 50);
	cout << "s7=" << s7 << endl;
	cout << "s7.capacity()=" << s7.capacity() << endl;
	cout << "s7.size()=" << s7.size() << endl;
	cout << "-------------------" << endl;

	//TODO: 5）string(const string & str, size_t pos = 0, size_t n = npos); 
	// 将sring对象初始化为str从位置pos开始到结尾的字符（或从位置pos开始的n个字符）。会判断str的结尾标志
	string s8(s3, 3,5);
	cout << "s8=" << s8 << endl;
	string s9(s3, 3);	// 从s3的第三个位置开始，截取后面所有内容
	cout << "s9=" << s9 << endl;
	cout << "s9.capacity()=" << s9.capacity() << endl;	// 返回当前容量，可以存放字符的总数
	cout << "s9.size()=" << s9.size() << endl;	// 返回容器中数据的大小

	string s10("hello world", 3, 5);  
	cout << "s10=" << s10 << endl;
	string s11("hello world", 3);	// 调用的是构造函数 4）string(const char* s, size_t n); 
	cout << "s11=" << s11 << endl;
	cout << "-------------------" << endl;


	//TODO: 6）template<class T> string(T begin, T end);
	// 将string对象初始化为区间[begin,end]内的字符，其中begin和end的行为就像指针，用于指定位置，范围包括begin在内，但不包括end。
	
	//7）string(size_t n, char c); // 创建一个由n个字符c组成的string对象。
	string s12(8, 'a');
	cout << "s12=" << s12 << endl;
	cout << "s12.capacity()=" << s12.capacity() << endl;
	cout << "s12.size()=" << s12.size() << endl;
	string s13(30, 0);
	cout << "s13=" << s13 << endl;
	cout << "s13.capacity()=" << s13.capacity() << endl;
	cout << "s13.size()=" << s13.size() << endl;


}