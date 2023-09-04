#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class AA {
public:
	string m_name;
	AA() { cout << "�����˹��캯��AA()" << endl; }
	AA(const string& name) :m_name(name) { cout << "�����˹��캯��AA(const dtring& name):" << m_name << endl; }
	~AA() { cout << "��������������~AA()��" << m_name << endl; }

};


unique_ptr<AA> func()
{
	unique_ptr<AA> pp(new AA("��ʩ3"));
	return pp;
}

// ����func1()��Ҫһ��ָ�룬���������ָ�븺��(�ͷ���Դ�����飬�����������)
void func1(const AA* a)
{
	cout << a->m_name << endl;

}

// ����func2()��Ҫһ��ָ�룬�����ָ�븺�� �ͷ���Դ��������func2()�� ��
void func2(AA* a)
{
	cout << a->m_name << endl;
	delete a;
}

// ����func3()��Ҫһ��unique_ptr���󣬲�������unique_ptr������
void func3(const unique_ptr<AA>& a)
{
	cout << a->m_name << endl;
}

// ����func4()��Ҫһ��unique_ptr���󣬶����unique_ptr������
void func4(unique_ptr<AA> a)
{
	cout << a->m_name << endl;
}




int main(void)
{
	//AA* parr1 = new AA[2]; // ��ָͨ������
	////AA* parr1 = new AA[2]{ string("��ʩ1"),string("��ʩ2") };
	//parr1[0].m_name = "��ʩ1";
	//cout << "parr1[0].m_name= " << parr1[0].m_name << endl;
	//parr1[1].m_name = "��ʩ2";
	//cout << "parr1[1].m_name= " << parr1[1].m_name << endl;
	//delete[] parr1;

	unique_ptr<AA[]> parr1(new AA[2]);	// unique_ptr����
	// unique_ptr<AA[]> parr1(new AA[2]{string("��ʩ1"),string("��ʩ2")});  // ָ����ʼ��
	parr1[0].m_name = "��ʩ1";
	cout << "parr1[0].m_name= " << parr1[0].m_name << endl;
	parr1[1].m_name = "��ʩ2";
	cout << "parr1[1].m_name= " << parr1[1].m_name << endl;


	
	
}