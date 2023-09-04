#include <iostream>
#include <memory>

class AA {
public:
	std::string m_name;
	AA() { std::cout << m_name << "调用析构函数AA()" << std::endl; }
	AA(const std::string& name) :m_name(name)
	{
		std::cout << "调用构造函数AA(" << m_name << ")" << std::endl;
	}
	~AA() { std::cout << "调用了析构函数~AA(" << m_name << ")" << std::endl; }
};

void deletefunc(AA* a)	// 删除器，普通函数
{
	std::cout << "自定义删除器（全局函数）" << std::endl;
	delete a;
}

class deleteclass {		// 删除器，仿函数
public:
	void operator()(AA* a)
	{
		std::cout << "自定义删除器(仿函数)" << std::endl;
		delete a;
	}
};

auto deletelamb = [](AA* a)		// 删除器，Lambda表达式
{
	std::cout << "自定义删除器(Lambda)" << std::endl;
	delete a;
};

//! 智能指针调用删除器的时候，会把资源的原始指针传进来。
//! 自定义删除器的目的是希望释放资源的时候可以做其他的事情


int main(void)
{
	//std::shared_ptr<AA> pa1 = std::make_shared<AA>("西施a");	// 用缺省的删除器

	//std::shared_ptr<AA> pa1(new AA("西施a"), deletefunc);	// 删除器，普通函数
	//std::shared_ptr<AA> pa2(new AA("西施b"), deleteclass());	// 删除器，仿函数（匿名对象）
	//std::shared_ptr<AA> pa3(new AA("西施c"),deletelamb);	// 删除器，Lambda表达式

	//std::unique_ptr<AA, decltype(deletefunc)*> pu1(new AA("西施1"), deletefunc);	// 删除器，普通函数
	//std::unique_ptr<AA, void (*)(AA*)> pu0(new AA("西施1"),deletefunc);	// 删除器，普通函数(第二个模板参数用的是函数指针)
	//std::unique_ptr<AA, deleteclass> pu2(new AA("西施2"),deleteclass()); // 删除器，仿函数（匿名对象）
	std::unique_ptr<AA, decltype(deletelamb)> pu3(new AA("西施3"), deletelamb);	// 删除器，Lambda表达式



}