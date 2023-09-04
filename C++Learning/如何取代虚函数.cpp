#include <iostream>
#include <functional>
using namespace std;

struct Hero {	// Ӣ�ۻ���
	//virtual void show() { cout << "Ӣ���ͷ��˼���" << endl; }
	function<void()> m_callback;	// ���ڰ�����ĳ�Ա��������������m_callback

	// ע�������Ա����ģ�壬�����Ա����û�в���
	template<typename Fn,typename... Args>
	void callback(Fn&& fn, Args... args)
	{
		m_callback = bind(forward<Fn>(fn), forward<Args>(args)...);
		// �󶨵��ǳ�Ա���������Եڶ�������Ҫ�Ѷ����thisָ�봫�������ɱ����������һ������������ĵ�ַ��
	}

	void show() { m_callback(); }
};

struct XS :public Hero {	// ��ʩ������
	void show() { cout << "��ʩ�ͷ��˼���" << endl; }
};

struct HX :public Hero {	// ����������
	void show() { cout << "�����ͷ��˼���" << endl; }
};

int main(void)
{
	// �����û�ѡ���Ӣ�ۣ��ͷż���
	int id = 0;	// Ӣ�۱��
	cout << "������Ӣ�ۣ�1-��ʩ��2-���ţ���";
	cin >> id;

	// ��������ָ�룬��ָ������������û���ָ�������������麯��
	Hero* ptr = nullptr;

	if (id == 1) {
		ptr = new XS;
		ptr->callback(&XS::show,static_cast<XS*>(ptr));	// ע���Ա����
	}
	if (id == 2) {
		ptr = new HX;
		ptr->callback(&HX::show,static_cast<HX*>(ptr));	// ע���Ա����
	}

	if (ptr !=nullptr) {
		ptr->show();
		delete ptr;
	}
	
}