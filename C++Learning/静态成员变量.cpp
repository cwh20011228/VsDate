#include <iostream>
using namespace std;

class CGirl {
	static  int m_age;
public:
	string m_name;
	
	CGirl(const string& name, int age);
	void ShowName() const;
	static void ShowAge();
};


// 类中的静态成员变量是属于整个类的，而不是属于类的每个具体实例的，所以在类的构造函数的初始化列表中不能初始化类的静态成员变量

CGirl::CGirl(const string& name, int age):m_name{name}
{
	m_age = age;
	cout << "调用了构造函数CGirl(const string& name, int age)" << endl;
}

void CGirl::ShowName() const
{
	cout << "姓名：" << m_name<<"      "<<m_age << endl;
	ShowAge();
}

void CGirl::ShowAge()
{
	cout << "年龄：" << m_age << endl;

}


int CGirl::m_age=20; // 初始化类的静态成员变量

int main()
{
	
	CGirl g1{ "西施1",23 },g2{"西施2",24},g3{"西施3",25};
	g1.ShowName(); g1.ShowAge();
	g2.ShowName(); g2.ShowAge();
	g3.ShowName(); g3.ShowAge();

	CGirl::ShowAge();
	/*cout << "年龄：" << CGirl::m_age << endl;*/

}