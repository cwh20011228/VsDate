#include <iostream>
#include <memory>

class BB;

class AA {
public:
	std::string m_name;
	AA() { std::cout << m_name << "������������AA()" << std::endl; }
	AA(const std::string& name) :m_name(name)
	{
		std::cout << "���ù��캯��AA(" << m_name << ")" << std::endl;
	}
	~AA() { std::cout << "��������������~AA(" << m_name << ")" << std::endl; }
	std::weak_ptr<BB> m_p;
};

class BB {
public:
	std::string m_name;
	BB() { std::cout << m_name << "������������BB()" << std::endl; }
	BB(const std::string& name) :m_name(name)
	{
		std::cout << "���ù��캯��BB(" << m_name << ")" << std::endl;
	}
	~BB() { std::cout << "��������������~BB(" << m_name << ")" << std::endl; }
	std::weak_ptr<AA> m_p;
};

int main(void)
{
	std::shared_ptr<AA> pa = std::make_shared<AA>("��ʩa");

	{
		std::shared_ptr<BB> pb = std::make_shared<BB>("��ʩb");

		// �������ڲ�����ʩb����Դû�й��ڣ�
		pa->m_p = pb;	// ��weak_ptr��shared_ptr��
		pb->m_p = pa;

		std::shared_ptr<BB> pp = pa->m_p.lock();
		// lock()��Ա�������̰߳�ȫ�ģ���ԭ�Ӳ�������������ɹ��ˣ��ͷ���һ����Ч��shared_ptr����Դ�����ü�����1���������ʧ���ˣ����ؿյ�shared_ptr
		if (pp == nullptr) {
			std::cout << "�����ڲ���pa->m_p�ѹ���" << std::endl;
		}
		else {
			std::cout << "�����ڲ���pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
		}
	}

	// �������ⲿ����ʩb����Դ�ѹ��ڣ�
	std::shared_ptr<BB> pp = pa->m_p.lock();
	if (pp == nullptr) {
		std::cout << "�����ⲿ��pa->m_p�ѹ���" << std::endl;
	}
	else {
		std::cout << "�����ⲿ��pa->m_p.lock()->m_name" << pa->m_p.lock()->m_name << std::endl;
	}

}