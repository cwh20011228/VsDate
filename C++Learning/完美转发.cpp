#include <iostream>
using namespace std;

void func1(int& ii)	// �����������ֵ�����ô˺���
{
	cout << "��������ֵ=" << ii << endl;
}

void func1(int&& ii)	// �����������ֵ�����ô˺���
{
	cout << "��������ֵ=" << ii << endl;
}

//void func2(int& ii)	// ��ֵ�汾
//{
//	func1(ii);
//}

//void func2(int&& ii)	// ��ֵ�汾
//{
//	func1(move(ii));
//}

//template<typename T>
//void func2(T&& ii)	// ��ֵ
//{
//	func1(move(ii));
//}

//template<typename T>
//void func2(T& ii)	// ��ֵ
//{
//	func1(ii);
//}
// ����ϣ�����ǣ�func2()�Ѳ�������func1()��ʱ��ҲҪ����ֵ����ֵ֮��

template<typename T>
void func2(T&& ii)
{
	func1(forward<T>(ii));
}

// ����������������ֵ����ֵ������ģ���ʱ�����Ѳ���������ֵ���Դ�������
// forward()ģ�庯���ٶ�ȡ����������Ϣ��Ȼ��ת����ȥ

int main(void)
{
	int ii = 3;
	func2(ii);	// ��������ֵ����
	func2(8);	// ��������ֵ����


}