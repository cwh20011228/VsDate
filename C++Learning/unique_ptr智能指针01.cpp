#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class AA {
public:
	string m_name;
	AA() { cout << m_name << "	�����˹��캯��AA()" << endl; }
	AA(const string& name) :m_name(name) { cout << m_name << "	�����˹��캯��AA(const string& name)" << endl; }
	~AA() { cout << "��������������~AA()	" << m_name << endl; }
};


void func(unique_ptr<AA>* pp)
{
	cout << "m_name=" << ( * pp)->m_name << endl;
}

int main(void)
{
	//AA* p = new AA("��ʩ");		// ����ԭʼָ��p,�����ڴ�
	//unique_ptr<AA> pu1(p);
	unique_ptr<AA> pu1(new AA("��ʩ"));		// ��������ָ�����pu1�����ڹ���ԭʼָ��p

	func(&pu1);
	//cout << "��ָ���ֵ�ǣ�         " << p << endl;
	//cout << "pu1�����ֵ�ǣ�        " << pu1 << endl;
	//cout << "pu1.get()����Ľ���ǣ�" << pu1.get() << endl;
	//cout << "pu1�ĵ�ַ�ǣ�          " << &pu1 << endl;
	////!����ָ������࣬������һ����Ա��������ԭʼָ��


}