#include <iostream>
using namespace std;

//! �������÷������� 
//! auto��һ��ռλ��(c++11��auto�����Ĺ���),Ϊ��������ֵռ��һ��λ��
// int func(){ }
auto func() -> int 
{
	cout << "������func()����" << endl;
	return 3;
}

//! �����ķ���ֵ������ decltype(x+y)  ,ֻ��д�ں��棨�������β�x��y�������򣩣�����д��ǰ�棨ǰ��û����x��y�������򣩣�
//template <typename T1,typename T2>
//auto Add(T1 x, T2 y) -> decltype(x + y)
//{
//	decltype(x + y) temp = x + y;
//	cout << "temp=" << temp << endl;
//	return temp;
//}


//! c++14��׼�Ժ������������Ƶ����������Ż��������ķ���ֵ���Ϳ�����auto������β�淵������
template <typename T1, typename T2>
auto Add(T1 x, T2 y){
	decltype(x + y) temp = x + y;
	cout << "temp=" << temp << endl;
	return temp;
}


int main(void)
{
	/*decltype(func()) fa;
	decltype (func) *fp=func;
	fp();*/

	Add(2.3, 5);

	return 0;
}