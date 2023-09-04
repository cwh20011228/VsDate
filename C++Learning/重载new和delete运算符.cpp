#include <iostream>
using namespace std;

/*	C++中使用new，编译器做了两件事：
*		调用标准库函数 operator new() 分配内存
*		调用构造函数初始化内存
* 
*	C++使用delete，编译器做了两件事：
*		调用析构函数destructor
*		调用标准库函数 operator delete() 释放内存	
* 
*	可以重载内存分配函数 operator new()  和  内存释放函数  operator delete()
*/

// 为类重载new 和delete函数，作用的范围是类，而不是全局
// 重载的类的 new 和 delete 函数，默认是 static 静态成员函数，只能访问静态成员。
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
	cout << "调用了类的重载的new:" << size << "字节。" << endl;
	void* ptr = malloc(size);	// 分配内存
	cout << "申请到的内存的地址是：" << ptr << endl;
	return ptr;
}

void CGirl::operator delete(void* ptr)
{
	cout << "调用了类的重载的delete" << endl;
	if (ptr == 0) return;
	free(ptr);
}

void* CGirl::operator new[](size_t size)
{
	cout << "调用了类的重载的new[]:" << size << "字节。" << endl;
	void* ptr = malloc(size);
	cout << "申请的内存的地址是" << ptr << endl;
	return ptr;
}

void CGirl::operator delete[](void* ptr)
{
	cout << "调用了类的重载的delete[]" << endl;
	if (ptr == 0) return;
	free(ptr);
}

CGirl::CGirl(int bh, int xw):m_bh{bh},m_xw{xw}
{
	cout << "调用了构造函数CGirl(int bh, int xw)" << endl;
}

CGirl::~CGirl()
{
	cout << "调用了析构函数~CGirl()" << endl;
}

CGirl::CGirl():m_bh{10},m_xw{87}
{
	cout << "调用了默认构造函数CGirl()" << endl;
}

// typedef unsigned __int64 size_t;
void* operator new(size_t size)
{
	cout << "调用了全局重载的new:" << size << "字节。" << endl;
	void* ptr = malloc(size);	// 分配内存
	cout << "申请到的内存的地址是：" << ptr << endl;
	return ptr;
}

void operator delete(void* ptr)
{
	cout << "调用了全局重载的delete" << endl;
	if (ptr == 0) return;	//对空指针delete是安全的

	free(ptr);	//释放内存
}

int main(void)
{
	int* p1 = new int{ 3 };
	cout << "p1=" << (void*)p1 << "  *p1=" << *p1 << endl;
	delete p1;
	cout << endl;

	CGirl* g1=new CGirl(3,87);
	cout << "g1的地址是：" << g1 << "  编号：" << g1->m_bh << "  XW：" << g1->m_xw << endl;
	delete g1;

	cout << endl;
	CGirl* g2 = new CGirl[5];
	delete[] g2;

}