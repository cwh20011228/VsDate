#include <iostream>
using namespace std;


void* operator new(size_t size)   // 重载new运算符。
{
	void* ptr = malloc(size);        // 申请内存。
	cout << "申请到的内存的地址是：" << ptr << "，大小是：" << size << endl;
	return ptr;
}


void operator delete(void* ptr)
{
	if (ptr == nullptr) return;
	free(ptr);
	cout << "释放了内存" << endl;
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
		cout << "A中this指针是:" << this << endl;
		cout << "A中m_a的地址是:" <<&m_a << endl;
		cout << "A中m_b的地址是:" << &m_b << endl;
		cout << "A中m_c的地址是:" << &m_c << endl;
	}

};

class B :public A {
public:
	int m_d = 40;
	B() {
		cout << "B中this指针是:" << this << endl;
		cout << "B中m_a的地址是:" << &m_a << endl;
		cout << "B中m_b的地址是:" << &m_b << endl;
		cout << "B中m_d的地址是:" << &m_d << endl;
	}
};
	


int main(void)
{
	cout << "基类占用内存的大小：" << sizeof(A) << endl;
	cout << "派生类占用内存的大小：" << sizeof(B) << endl;
	B* b=new B;
	delete b;

	return 0;
}