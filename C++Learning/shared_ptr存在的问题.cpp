#include <iostream>
#include <memory>

class BB;

class AA {
public:
	std::string m_name;
	AA() { std::cout << m_name << "调用析构函数AA()" << std::endl; }
	AA(const std::string& name) :m_name(name)
	{
		std::cout << "调用构造函数AA(" << m_name << ")" << std::endl;
	}
	~AA() { std::cout << "调用了析构函数~AA(" << m_name << ")" << std::endl; }
	std::weak_ptr<BB> m_p;
};

class BB {
public:
	std::string m_name;
	BB() { std::cout << m_name << "调用析构函数BB()" << std::endl; }
	BB(const std::string& name) :m_name(name)
	{
		std::cout << "调用构造函数BB(" << m_name << ")" << std::endl;
	}
	~BB() { std::cout << "调用了析构函数~BB(" << m_name << ")" << std::endl; }
	std::weak_ptr<AA> m_p;
};

int main(void)
{
	std::shared_ptr<AA> pa = std::make_shared<AA>("西施a");

	{
		std::shared_ptr<BB> pb = std::make_shared<BB>("西施b");

		// 在语句块内部，西施b的资源没有过期，
		pa->m_p = pb;	// 将weak_ptr与shared_ptr绑定
		pb->m_p = pa;

		std::shared_ptr<BB> pp = pa->m_p.lock();
		// lock()成员函数是线程安全的，是原子操作，如果提升成功了，就返回一个有效的shared_ptr，资源的引用计数加1；如果提升失败了，返回空的shared_ptr
		if (pp == nullptr) {
			std::cout << "语句块内部：pa->m_p已过期" << std::endl;
		}
		else {
			std::cout << "语句块内部：pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
		}
	}

	// 在语句块外部，西施b的资源已过期，
	std::shared_ptr<BB> pp = pa->m_p.lock();
	if (pp == nullptr) {
		std::cout << "语句块外部：pa->m_p已过期" << std::endl;
	}
	else {
		std::cout << "语句块外部：pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
	}

}