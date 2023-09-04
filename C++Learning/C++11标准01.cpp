#include <iostream>
using namespace std;

class CGirl {
private:
	int m_bh=20;
	string m_name="西施";
	char m_xb = 'X';
public:
	CGirl() = default;		// 启用默认构造函数
	CGirl(int bh,string name,char xb):m_bh(bh),m_name(name),m_xb(xb) { }
	CGirl(const CGirl& g) = delete;		// 删除拷贝构造函数
	void show() { cout << "bh=" << m_bh << ",m_name=" << m_name << endl; }
	//~CGirl() = delete;	// 删除析构函数
};

// 如果我们提供了构造函数，那么编译器就不会提供默认构造函数


int main(void)
{
	CGirl g1;
	g1.show();
	CGirl g2 = g1;
	return 0;
}