#include <iostream>
using namespace std;

//!������������ array
// ��ͨ���������Ͳ���������ȱʡֵ
// ģ���в����޸ķ�ͨ�����Ͳ�����ֵ

template <class T,int len=5>
class Array {
private:
	T items[len];	//����Ԫ��
public:
	Array() { /*memset(items, 0, sizeof(items));*/ }	// Ĭ�Ϲ��캯������ʼ������
	~Array() { }
	T& operator[](int ii) { return items[ii]; }	// ���ز�����[] ,�����޸������е�Ԫ��
	const T& operator[](int ii) const { return items[ii]; }	// ���ز�����[] �������޸������е�Ԫ��
};

//! string���࣬������һ��ָ������ڴ��ָ�룬

// ����ģ�崴�������ʱ����Ҫָ����ͨ�����Ͳ�����ֵ

int main(void)
{
	Array<string,5> a1;
	Array<string, 6> a2;
	Array<string, 7> a3;
	//! Array<string,5>  Array<string, 6>  Array<string, 7>  ���������࣬����Ķ����ƴ����������е�ʱ��ռ�õ��ڴ�ռ����
	
	a1[0] = "��ʩ"; 
	a1[1] = "����";
	a1[2] = "����";
	a1[3] = "����";
	a1[4] = "����";

	for (int i = 0; i < 5; i++)
	{
		cout << a1[i] << endl;
	}

	return 0;
}