#include <iostream>
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
	/*cout << "������Swap()����" << endl;*/
}

template <typename T>
T Add(T a, T b)
{
	return a + b;
}


template <typename T1,typename T2>
void show(T1 no, T2 message)
{
	cout << "no="<<no << "  message="<<message << endl;
}


template <typename T>
void func(T a)
{
	cout << "func(T a)" << endl;
}

template <typename T1,typename T2>
void func(T1 a, T2 b)
{
	cout << "func(T1 a, T2 b)" << endl;
}

template <typename T1,typename T2>
void func(T1 a, T2 b, int c)
{
	cout << "func(T1 a, T2 b, int c)" << endl;
}

//class CGirl {
//public:
//	template <typename T>
//	CGirl(T a)
//	{
//		cout << "a=" << a << endl;
//	}
//
//	template <typename T>
//	void show(T b)
//	{
//		cout << "b=" << b << endl;
//	}
//
//
//};

int main()
{
	//CGirl a("��ʩ");
	//a.show(2);
	//a.show("���");

	//int a = 1;
	//int b = 2;
	//Swap(a,b);
	//cout << "a=" << a << "   b=" << b << endl;
	/*Swap<int>();*/

	int a = 10;
	char b = '20';
	int c = Add<int>(10, 20);
	cout << "c=" << c << endl;

	int bh = 3;
	string message = "����һֻɵɵ��";
	show(bh, message);
	/*string a = "����";
	string b = " ��ʩ";
	string c = Add(a, b);*/

	/*CGirl a;
	CGirl b;
	CGirl c = Add(a, b);*/

	func(2);
	func(1, 2);
	func(1, 2, 3);

	return 0;
}


//! ����ģ���ע�����
//! ��1������Ϊ��ĳ�Ա��������ģ�壬���������麯������������
//! ��2��ʹ�ú���ģ��ʱ��������ȷ�������ͣ�ȷ��ʵ���뺯��ģ����ƥ����
//! ��3��ʹ�ú���ģ��ʱ���Ƶ����������ͱ�����Ӧ����ģ���еĴ���
//! ��4��...��������Զ������Ƶ������ᷢ����ʽ����ת���������ʾָ���˺���ģ����������ͣ����Է�����ʽת��
//! ��5������ģ��֧�ֶ��ͨ���������͵Ĳ���
//! ��6������ģ��֧�����أ������з�ͨ���������͵Ĳ���