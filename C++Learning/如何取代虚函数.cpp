#include <iostream>
#include <functional>
using namespace std;

struct Hero {	// 英雄基类
	//virtual void show() { cout << "英雄释放了技能" << endl; }
	function<void()> m_callback;	// 用于绑定子类的成员函数给函数对象m_callback

	// 注册子类成员函数模板，子类成员函数没有参数
	template<typename Fn,typename... Args>
	void callback(Fn&& fn, Args... args)
	{
		m_callback = bind(forward<Fn>(fn), forward<Args>(args)...);
		// 绑定的是成员函数，所以第二个参数要把对象的this指针传进来，可变参数包将有一个参数（对象的地址）
	}

	void show() { m_callback(); }
};

struct XS :public Hero {	// 西施派生类
	void show() { cout << "西施释放了技能" << endl; }
};

struct HX :public Hero {	// 韩信派生类
	void show() { cout << "韩信释放了技能" << endl; }
};

int main(void)
{
	// 根据用户选择的英雄，释放技能
	int id = 0;	// 英雄编号
	cout << "请输入英雄（1-西施；2-韩信）：";
	cin >> id;

	// 创建基类指针，将指向派生类对象，用基类指针调用派生类的虚函数
	Hero* ptr = nullptr;

	if (id == 1) {
		ptr = new XS;
		ptr->callback(&XS::show,static_cast<XS*>(ptr));	// 注册成员函数
	}
	if (id == 2) {
		ptr = new HX;
		ptr->callback(&HX::show,static_cast<HX*>(ptr));	// 注册成员函数
	}

	if (ptr !=nullptr) {
		ptr->show();
		delete ptr;
	}
	
}