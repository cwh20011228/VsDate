#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class AA {
public:
	string m_name;
	AA() { cout <<m_name<< "	�����˹��캯��AA()" << endl; }
	AA(const string& name) :m_name(name) { cout << m_name << "	�����˹��캯��AA(const string& name)" << endl; }
	~AA() { cout << "��������������~AA()	" << m_name << endl; }
};

int main(void)
{
	///*AA* p = new AA("��ʩ");*/
	//unique_ptr<AA> pu1(new AA("��ʩ"));
	//// ģ�����AA��ʾ��Ҫ�������ָͨ��Ļ����ͣ�ָ��Ķ�����������ͣ���AA��p��ʾ�������ָ�룬pָ����new�����Ķ���ĵ�ַ
	//// ��ӵ���˼��������ָ��pu1���������
	//// ����ָ�����࣬����������������������������ʹ����delete���
	//// ����ָ�������� * �� -> ����������ʹ����ָͨ��һ��ʹ������ָ��

	//cout << "m_name=" << (*pu1).m_name << endl;
	//cout << "m_name=" << pu1->m_name << endl;

	//AA* p = new AA("��ʩ");
	//unique_ptr<AA> pu2(p);

	////TODO: ����
	//unique_ptr<AA> pu3 = p;		//ERROR�����ܰ���ָͨ��ֱ�Ӹ�ֵ������ָ�루����ָ��Ĺ��캯����explicit���Σ���������ת��������
	//unique_ptr<AA> pu4 = new AA("��ʩ"); //error, ���ܰ���ָͨ��ֱ�Ӹ�ֵ������ָ�루
	//
	//unique_ptr <AA> pu5 = pu1;	// error,���ÿ������캯������������������ָ�뿽������

	//unique_ptr<AA> pu6;
	//pu6 = pu1;					// error ,������ = ��unique_ptr���и�ֵ
	////! unique_ptr�����Ŀ���Ƕ�����󣬼�һ��unique_ptr����ֻ��һ����Դ����
	////! ���unique_ptr���������ƣ���ô����ֶ��unique_ptr����ָ��ͬһ���ڴ�������������һ��unique_ptr������ڵ�ʱ���ͷ��ڴ棻������unique_ptr������ڵ�ʱ���ֻ��ͷ��ڴ棬��ɵĽ���Ƕ�ͬһ���ڴ��ͷŶ�Σ��ͳ��˲���Ұָ�롣
	////TODO: ����

	// ��ָ�������ָͨ�룬Ҳ��ԭʼָ��
	// ��ʵ�ʿ����У����ʹ��������ָ�룬��ò�Ҫʹ����ָ��
	AA* p = new AA("��ʩ");
	unique_ptr<AA> pu1(p);
	unique_ptr<AA> pu2(p);
	unique_ptr<AA> pu3(p);
	return 0;
}