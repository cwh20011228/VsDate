#include <iostream>
using namespace std;
// ģ������þ��Ǵ�������
// ����ģ�岻֧��ģ���ģ�����

template <class T1,int len>
class LinkList {		//! ������ģ��
public:
	T1* m_head;			// ����ͷ���
	int m_len = len;	// ��
	void insert() { cout << "�������в�����һ����¼��" << endl; }
	void ddelte() { cout << "��������ɾ����һ����¼��" << endl; }
	void update() { cout << "�������и�����һ����¼��" << endl; }
};


template <class T1,int len>
class Array {			//! ������ģ��
public:
	T1* m_data;			// ����ָ��
	int m_len = len;	// ��
	void insert() { cout << "�������в�����һ����¼��" << endl; }
	void ddelte() { cout << "��������ɾ����һ����¼��" << endl; }
	void update() { cout << "�������и�����һ����¼��" << endl; }

};

//! C++֧��ģ���ģ�壬��ģ��������һ��������������͡�ʵ���������ʱ�򣬿�����ģ������Ϊ����������ģ��

// ���Ա�ģ���ࣺtabletype-���Ա�����   datatype-���Ա����������
template <template<class,int> class tabletype,class datatype,int len>
//TODO: template<class,int> ��ʾҪ������������ģ������ ����Ҫ����ģ��ĵ�һ��������ͨ�����ͣ��ڶ���������int��
class LinearList {
public:
	tabletype<datatype, len> m_table;		// �������Ա����
	void insert() { m_table.insert(); }		// ���Ա�������
	void ddelte() { m_table.ddelte(); }		// ���Ա�ɾ������
	void update() { m_table.update(); }		// ���Ա���²���

	void oper()	// ��ҵ��Ҫ��������Ա�
	{
		cout << "len=" << m_table.m_len << endl;
		m_table.insert();
		m_table.update();
	}
};

int main(void)
{
	//�������Ա������������Ϊ�����������������Ϊint����Ϊ20
	LinearList<LinkList, int, 20> a;
	a.insert();		a.ddelte();		a.update();

	// �������Ա������������Ϊ���飬�������������Ϊstring����Ϊ20
	LinearList<Array, string, 20> b;
	b.insert();		b.ddelte();		b.update();

}