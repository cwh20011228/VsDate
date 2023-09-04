#include <iostream>
using namespace std;

/*	C++��ʹ��new�����������������£�
*		���ñ�׼�⺯�� operator new() �����ڴ�
*		���ù��캯����ʼ���ڴ�
* 
*	C++ʹ��delete�����������������£�
*		������������destructor
*		���ñ�׼�⺯�� operator delete() �ͷ��ڴ�	
* 
*	���������ڴ���亯�� operator new()  ��  �ڴ��ͷź���  operator delete()
*/

// Ϊ������new ��delete���������õķ�Χ���࣬������ȫ��
// ���ص���� new �� delete ������Ĭ���� static ��̬��Ա������ֻ�ܷ��ʾ�̬��Ա��
class CGirl {
public:
	int m_bh;
	int m_xw;
	CGirl(int bh, int xw);
	~CGirl();
	CGirl();
	void* operator new(size_t size); 
	void operator delete(void* ptr);
	void* operator new[](size_t size);
	void operator delete[](void* ptr);

};

void* CGirl::operator new(size_t size)
{
	cout << "������������ص�new:" << size << "�ֽڡ�" << endl;
	void* ptr = malloc(size);	// �����ڴ�
	cout << "���뵽���ڴ�ĵ�ַ�ǣ�" << ptr << endl;
	return ptr;
}

void CGirl::operator delete(void* ptr)
{
	cout << "������������ص�delete" << endl;
	if (ptr == 0) return;
	free(ptr);
}

void* CGirl::operator new[](size_t size)
{
	cout << "������������ص�new[]:" << size << "�ֽڡ�" << endl;
	void* ptr = malloc(size);
	cout << "������ڴ�ĵ�ַ��" << ptr << endl;
	return ptr;
}

void CGirl::operator delete[](void* ptr)
{
	cout << "������������ص�delete[]" << endl;
	if (ptr == 0) return;
	free(ptr);
}

CGirl::CGirl(int bh, int xw):m_bh{bh},m_xw{xw}
{
	cout << "�����˹��캯��CGirl(int bh, int xw)" << endl;
}

CGirl::~CGirl()
{
	cout << "��������������~CGirl()" << endl;
}

CGirl::CGirl():m_bh{10},m_xw{87}
{
	cout << "������Ĭ�Ϲ��캯��CGirl()" << endl;
}

// typedef unsigned __int64 size_t;
void* operator new(size_t size)
{
	cout << "������ȫ�����ص�new:" << size << "�ֽڡ�" << endl;
	void* ptr = malloc(size);	// �����ڴ�
	cout << "���뵽���ڴ�ĵ�ַ�ǣ�" << ptr << endl;
	return ptr;
}

void operator delete(void* ptr)
{
	cout << "������ȫ�����ص�delete" << endl;
	if (ptr == 0) return;	//�Կ�ָ��delete�ǰ�ȫ��

	free(ptr);	//�ͷ��ڴ�
}

int main(void)
{
	int* p1 = new int{ 3 };
	cout << "p1=" << (void*)p1 << "  *p1=" << *p1 << endl;
	delete p1;
	cout << endl;

	CGirl* g1=new CGirl(3,87);
	cout << "g1�ĵ�ַ�ǣ�" << g1 << "  ��ţ�" << g1->m_bh << "  XW��" << g1->m_xw << endl;
	delete g1;

	cout << endl;
	CGirl* g2 = new CGirl[5];
	delete[] g2;

}