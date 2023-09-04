#include <iostream>
using namespace std;


void* operator new(size_t size)   // ����new�������
{
	void* ptr = malloc(size);        // �����ڴ档
	cout << "���뵽���ڴ�ĵ�ַ�ǣ�" << ptr << "����С�ǣ�" << size << endl;
	return ptr;
}


void operator delete(void* ptr)
{
	if (ptr == nullptr) return;
	free(ptr);
	cout << "�ͷ����ڴ�" << endl;
}

class A {
public:
	int m_a = 10;
protected:
	int m_b = 20;
private:
	int m_c = 30;
public:
	A() {
		cout << "A��thisָ����:" << this << endl;
		cout << "A��m_a�ĵ�ַ��:" <<&m_a << endl;
		cout << "A��m_b�ĵ�ַ��:" << &m_b << endl;
		cout << "A��m_c�ĵ�ַ��:" << &m_c << endl;
	}

};

class B :public A {
public:
	int m_d = 40;
	B() {
		cout << "B��thisָ����:" << this << endl;
		cout << "B��m_a�ĵ�ַ��:" << &m_a << endl;
		cout << "B��m_b�ĵ�ַ��:" << &m_b << endl;
		cout << "B��m_d�ĵ�ַ��:" << &m_d << endl;
	}
};
	


int main(void)
{
	cout << "����ռ���ڴ�Ĵ�С��" << sizeof(A) << endl;
	cout << "������ռ���ڴ�Ĵ�С��" << sizeof(B) << endl;
	B* b=new B;
	delete b;

	return 0;
}