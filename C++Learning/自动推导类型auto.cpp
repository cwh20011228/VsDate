#include <iostream>
using namespace std;

// ��������ʱ�������ָ���������ͣ���ʹ��auto�ؼ��֣�����������ݵȺ�=�ұߵ����ݣ��Զ��Ƶ�����������������

//class AA {
//	auto m_a;
//};


string func()
{
	return "���";
}

//void show(auto aa)
//{
//	cout << "aa= " << aa << endl;
//}

int main(void)
{
	//! c++���Զ��Ƶ�����
	// ����������auto�ؼ���
	auto a = 3+1;
	cout << "a= " << a << endl;
	auto b = 3.3+a;
	cout << "b= " << b << endl;
	auto c = "���";			// �������Ƶ���c�ı���������const char*
	cout << "c= " << c << endl;	
	auto d = func();			// �������Ƶ���d�ı��������� string
	cout << "d= " << d << endl;
	
	/*auto ss[22] = { 0 };*/

	//! ע�⣺(1) auto�����ı��������ڶ����ʱ���ʼ��
	//! (2) auto��ʼ������ֵ�����Ǿ������ֵ��Ҳ�����Ǳ��ʽ�򷵻�ֵ
	//! (3) �������β����Ͳ�����auto
	//! (4) auto����ֱ����������
	//! (5) auto���ܶ�����ķǾ�̬��Ա����
	
	return 0;
}