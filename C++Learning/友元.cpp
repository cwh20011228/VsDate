#include <iostream>
using namespace std;



// 声明友元friend的代码放在类的什么地方都可以，不受public和private的约束，一般放在最上面

/*
* 友元成员函数
* （1）把CGilr类的声明前置
* （2）把CBoy类的定义放在CGirl类前面
* （3）把CBoy类的成员函数的函数体从类的定义拿出来,放在定义CGirl类的后面
* （4）把Cboy类的成员函数声明为CGirl类的友元函数
*/ 

class CGirl;

class CBoy {
public:
	void func1(const CGirl& g);
	void func2(const CGirl& g);
};



class CGirl {
	//friend class CBoy;
	friend void  CBoy::func1(const CGirl& g);
	friend void  CBoy::func2(const CGirl& g);
public:
	string m_name;
	CGirl() :m_name{ "西施" }, m_xw{ 87 }{  };
	void ShowName();
private:
	int m_xw;
	void ShowXw() const;
};


void CGirl::ShowName()
{
	cout << "姓名：" << m_name << endl;
	/*ShowXw();*/
}

void CGirl::ShowXw() const
{
	cout << "Xm=" << m_xw << endl;
}

// 每个成员函数都有一个this指针，谁调用它，this就指向它

void CBoy::func1(const CGirl& g)
{
	cout << "func1  Xw = " << g.m_xw << endl;
}

void CBoy::func2(const CGirl& g)
{
	cout << "func2  姓名 = " << g.m_name << endl;
}




int main(void)
{
	CGirl g;
	CBoy b;
	b.func1(g);
	b.func2(g);
	return 0;
}