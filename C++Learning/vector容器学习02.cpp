#include <iostream>
#include <vector>
using namespace std;

class AA {
public:
	int m_bh;
	string m_name;

	AA()
	{
		cout << "默认构造函数AA()" << endl;
	}

	AA(const int& bh, const string& name) :m_bh(bh), m_name(name)
	{
		cout << "构造函数，name=" << m_name << endl;
	}

	AA(const AA& gg)
	{
		cout << "拷贝构造函数，name=" << m_name << endl;
	}

	~AA()
	{
		cout << "析构函数" << endl;
	}

};
int main(void)
{
	/*vector<int> v1;
	int a;

	a = 1;		v1.emplace_back(a);
	a = 2;		v1.emplace_back(a);
	a = 3;		v1.emplace_back(a);

	for (int ii = 0; ii < v1.size(); ii++) {
		cout << v1[ii] << "  ";
	}
	cout << endl;
	return 0;*/

	vector<AA> v;
	//AA a(18, "西施");
	//*v.push_back(a);*/
	//v.emplace_back(a);
	v.emplace_back(18, "西施");

	cout << "bh=" << v[0].m_bh << "  name=" << v[0].m_name << endl;


}