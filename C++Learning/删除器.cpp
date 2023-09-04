#include <iostream>
#include <memory>

class AA {
public:
	std::string m_name;
	AA() { std::cout << m_name << "������������AA()" << std::endl; }
	AA(const std::string& name) :m_name(name)
	{
		std::cout << "���ù��캯��AA(" << m_name << ")" << std::endl;
	}
	~AA() { std::cout << "��������������~AA(" << m_name << ")" << std::endl; }
};

void deletefunc(AA* a)	// ɾ��������ͨ����
{
	std::cout << "�Զ���ɾ������ȫ�ֺ�����" << std::endl;
	delete a;
}

class deleteclass {		// ɾ�������º���
public:
	void operator()(AA* a)
	{
		std::cout << "�Զ���ɾ����(�º���)" << std::endl;
		delete a;
	}
};

auto deletelamb = [](AA* a)		// ɾ������Lambda���ʽ
{
	std::cout << "�Զ���ɾ����(Lambda)" << std::endl;
	delete a;
};

//! ����ָ�����ɾ������ʱ�򣬻����Դ��ԭʼָ�봫������
//! �Զ���ɾ������Ŀ����ϣ���ͷ���Դ��ʱ�����������������


int main(void)
{
	//std::shared_ptr<AA> pa1 = std::make_shared<AA>("��ʩa");	// ��ȱʡ��ɾ����

	//std::shared_ptr<AA> pa1(new AA("��ʩa"), deletefunc);	// ɾ��������ͨ����
	//std::shared_ptr<AA> pa2(new AA("��ʩb"), deleteclass());	// ɾ�������º�������������
	//std::shared_ptr<AA> pa3(new AA("��ʩc"),deletelamb);	// ɾ������Lambda���ʽ

	//std::unique_ptr<AA, decltype(deletefunc)*> pu1(new AA("��ʩ1"), deletefunc);	// ɾ��������ͨ����
	//std::unique_ptr<AA, void (*)(AA*)> pu0(new AA("��ʩ1"),deletefunc);	// ɾ��������ͨ����(�ڶ���ģ������õ��Ǻ���ָ��)
	//std::unique_ptr<AA, deleteclass> pu2(new AA("��ʩ2"),deleteclass()); // ɾ�������º�������������
	std::unique_ptr<AA, decltype(deletelamb)> pu3(new AA("��ʩ3"), deletelamb);	// ɾ������Lambda���ʽ



}