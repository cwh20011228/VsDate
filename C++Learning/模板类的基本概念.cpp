#include <iostream>
using namespace std;

template <class T1, class T2=string>		// �ڶ���ͨ�ò���ȱʡ������������string
class AA {
public:
	T1 m_a;		// ͨ����������ģ����
	T2 m_b;		// ͨ����������ģ����

	AA() { m_a.aaaaaaaa(); }
	AA(T1 a,T2 b):m_a{a},m_b{b} { }		// ͨ���������ڳ�Ա�����Ĳ���
	
	// ͨ���������ڳ�Ա�����ķ���ֵ
	T1 geta();
	T2 getb();
	
};

template <class T1,class T2>
T1 AA<T1,T2>::geta()
{
	T1 a = 2;
	return m_a + a;
}


template <class T1,class T2>
T2 AA<T1,T2>::getb()
{
	T2 b = "was";
	return m_b + b;
}


int main(void)
{
	//! ʹ�ú���ģ��ʱ������������ʵ���Զ��Ƶ����βε��������ͣ�Ҳ�����ֶ���ʾָ���������ͣ����ɸ����͵ĺ�������
	//! ��ģ�岻һ�����������Զ��Ƶ����͵�˵������ôָ��������ģ�崴�������ʱ��ָ��
	//! ʹ����ģ��ʱ���������ͱ�����Ӧ��ģ���еĴ���
	//! ��ģ�����Ϊͨ����������ָ��ȱʡ���������ͣ���c++11��׼�ĺ���ģ��Ҳ���ԣ�
	//! ��ĳ�Ա����Ҳ����������ʵ��
	//! ������new����ģ�������
	//! ģ����ĳ�Ա����ʹ���˲Żᴴ��
	
	/*AA<int> aa;
	aa.m_a = 20;
	aa.m_b = "��ʩ";
	cout << "aa.geta()=" << aa.geta() << endl << "aa.getb()=" << aa.getb() << endl;
	*/

	// ��ģ�岻��һ��ͨ���������ͣ���������ʱ��Ҫ��ʾָ�������������ͣ�
	AA<int, string>* a = new AA<int, string> {30,"����"};
	auto b = a;
	a->geta();
	a->getb();
	cout << "a->geta()=" << a->geta() << endl << "a->getb()=" << a->getb() << endl;

	delete a;
	a = nullptr;
	

	AA<int, string>* c;
	// ��Ȼ���������ָ�룬����û�д�����Ķ��󣬲�����ù��캯����
	// ģ������κγ�Ա������ֻҪ������û�е��ã��Ͳ��ᴴ����
	// ���Ծ���û�� m_a.aaaaaaaa(); �������������û�б���



}