#include <iostream>
using namespace  std;

class CBoy
{
public:
	string m_xm;
	/*CBoy();*/
	CBoy(string xm);
	CBoy(const CBoy& bb);
};

//CBoy::CBoy()
//{
//	m_xm.clear();
//	cout << "调用了默认构造函数CBoy()" << endl;
//}

CBoy::CBoy(string xm) :m_xm{ xm }
{
	cout << "调用了构造函数CBoy(string xm)" << endl;
}

CBoy::CBoy(const CBoy& bb) :m_xm{ bb.m_xm }
{
	cout << "调用了拷贝构造函数CBoy(const CBoy& bb)" << endl;
}



class CGirl
{
public:
	CBoy m_boy;
	string m_name;
	const int m_age;
	/*CGirl()
	{
		cout << "调用了CGirl()默认构造函数" << endl;
	}	*/
	/*CGirl(const CGirl& gg);*/
	CGirl(string name, int age, CBoy& boy);
	void show();
	~CGirl();

};

//CGirl::CGirl(const CGirl& gg) :m_name{ gg.m_name }, m_age{ gg.m_age }
//{
//	cout << "调用了拷贝构造函数CGirl(const CGirl& gg)" << endl;
//}

void CGirl::show()
{
	cout << "姓名：" << m_name << "  年龄：" << m_age <<"  男朋友："<<m_boy.m_xm << endl;
}

CGirl::~CGirl()
{
	cout << "调用了析构函数~CGirl()" << endl;
}

//CGirl::CGirl(string name, int age, CBoy& boy)
//{
//	m_age = age;
//	m_name = name;
//	m_boy.m_xm = boy.m_xm;
//	cout << "调用了构造函数CGirl(string name,int age,CBoy& boy)" << endl;
//}

//CGirl::CGirl(string name, int age, CBoy& boy) :m_name{ "漂亮的" + name }, m_age{ age - 1 }
//{
//	/*m_age = age;
//	m_name = name;*/
//	m_boy.m_xm = boy.m_xm;
//	cout << "调用了构造函数CGirl(string name,int age,CBoy& boy)" << endl;
//}


CGirl::CGirl(string name, int age, CBoy& boy) :m_name{ "漂亮的" + name }, m_age{ age  -1},m_boy{boy}
{
	cout << "调用了构造函数CGirl(string name,int age,CBoy& boy)" << endl;
}

int main(int argc,char* argv[])
{
	/*CGirl g1;
	g1.show();

	CGirl g2 = g1;
	g2.show();*/
	CBoy boy{ "Jack" };
	CGirl g3("西施", 23,boy);
	g3.show();

}
// 用类创建对象的时候，先初始化构造函数的形参对象，再初始化类的成员
// 没有采用初始化列表，对象的初始化和赋值初始化是两步操作，调用的是成员类的普通构造函数
// 采用初始化列表，对象的初始化和赋值初始化是一步操作，调用的是成员类的拷贝构造函数

// 常量在声明时必须初始化，并且初始化后，值不能被修改。 const int as = 8; 
// 引用必须在声明时初始化，初始化后不能改变