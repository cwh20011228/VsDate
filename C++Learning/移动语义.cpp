#include <iostream>
#include <cstring>
using namespace std;

class AA {
public:
	int* m_date = nullptr;	// ���ݳ�Ա��ָ�������Դ��ָ��

	AA() = default;	//����Ĭ�Ϲ��캯��

	void alloc()	// �����ݳ�Աm_data�����ڴ�
	{
		m_date = new(nothrow) int;	// �����ڴ�
		memset(m_date, 0, sizeof(int));	// ��ʼ���ѷ�����ڴ�
	}

	AA(const AA& a)	// �������캯��
	{
		cout << "�����˿������캯��" << endl;
		if (m_date == nullptr) {
			alloc();	// ���û�з����ڴ棬�ͷ���
		}
		memcpy(m_date, a.m_date, sizeof(int));	//�����ݴ�Դ�����п�������
	}

	AA(AA&& a)	// �ƶ����캯������Ҫ����Դ���󣨱�ת�ƶ��󣩵�ָ�룬�����ββ�����const
	{
		cout << "this=" << this << endl;
		cout << "�������ƶ����캯��" << endl;
		if (m_date != nullptr) {
			delete m_date;	// ����ѷ����ڴ棬���ͷŵ�����ָ��ճ�����׼��ָ���µ���Դ
		}
		m_date = a.m_date;	//����Դ��Դ������ת�ƹ���
		a.m_date = nullptr;	// ��Դ�����е�ָ���ÿգ�������ӵ����Դ
	}

	AA& operator=(const AA& a)	// ��ֵ����
	{
		cout << "�����˸�ֵ����" << endl;
		if (this == &a) {	// �������Ҹ�ֵ
			return *this;	
		}
		if (m_date == nullptr) {	// ���û�з����ڴ棬�ͷ���
			alloc();	
		}
		memcpy(m_date, a.m_date, sizeof(int));	//�����ݴ�Դ�����п�������
		return *this;
	}


	AA& operator=(AA&& a)	// �ƶ���ֵ����
	{
		cout << "&a=" << &a << endl;
		cout << "this=" << this << endl;
		cout << "�������ƶ���ֵ����" << endl;
		if (this == &a) {	// �������Ҹ�ֵ
			return *this;
		}
		if (m_date != nullptr) {	// ����ѷ����ڴ棬���ͷŵ�����ָ��ճ�����׼��ָ���µ���Դ
			delete m_date;
		}
		m_date = a.m_date;	// ����Դ��Դ������ת�ƹ���
		a.m_date = nullptr;	// ��Դ�����ָ���ÿգ�������ӵ����Դ
		return *this;
	}

	~AA()	// ��������
	{
		if (m_date != nullptr){
			delete m_date;
			m_date = nullptr;
		}
	}
};

//��c++11�У��ѿ������Ĳ����п������塣
//�ƶ��������˼�ǣ���Ҫ������ֱ�Ӱ���Դת�ƹ�����ת����Դ�Ĳ������ƶ����壩

// ��ͬ���࣬ת����Դ�ķ����ǲ�ͬ�ģ����ƶ����캯�����ƶ���ֵ�����Ĵ����д��Ҳ���ܲ�һ���������ƶ������������Ƶ�

int main(void)
{
	//AA a1;
	//a1.alloc();	// ��������ڴ�
	//*a1.m_date = 3;	// �������ڴ渳ֵ
	//cout << "*a1.m_date=" << *a1.m_date << endl;

	//AA a2 = move(a1);	// ���ÿ������캯��
	//cout << "*a2.m_date=" << *a2.m_date << endl;

	//AA a3;
	//a3 = move(a1);	// ���ø�ֵ����
	//cout << "*a3.m_date=" << *a3.m_date << endl;
	//cout << "------------------------------------" << endl;

	auto f = []()->AA 
	{ 
		AA aa; 
		aa.alloc();
		*aa.m_date = 8;
		cout << "����aa�ĵ�ַ��" << &aa << endl;
		return aa; 
	};		// ����AA������lambda����

	//AA a4 = f();	// ������ֵ�ķ�ʽ����AA�����ʱ���󣬾���һ����ֵ���������ƶ����캯��
	//cout << "*a4.m_date=" << *a4.m_date << endl;
	//cout << "&a4=" << &a4 << endl;

	AA a5;
	cout << "&a5=" << &a5 << endl;
	a5 = f();	// �����ƶ���ֵ����
	cout << "*a5.m_date=" << *a5.m_date << endl;
}