#include <iostream>
#include <cstring>
using namespace std;

class AA {
public:
	int* m_date = nullptr;	// 数据成员，指向堆区资源的指针

	AA() = default;	//启用默认构造函数

	void alloc()	// 给数据成员m_data分配内存
	{
		m_date = new(nothrow) int;	// 分配内存
		memset(m_date, 0, sizeof(int));	// 初始化已分配的内存
	}

	AA(const AA& a)	// 拷贝构造函数
	{
		cout << "调用了拷贝构造函数" << endl;
		if (m_date == nullptr) {
			alloc();	// 如果没有分配内存，就分配
		}
		memcpy(m_date, a.m_date, sizeof(int));	//把数据从源对象中拷贝过来
	}

	AA(AA&& a)	// 移动构造函数，需要操作源对象（被转移对象）的指针，所以形参不能用const
	{
		cout << "this=" << this << endl;
		cout << "调用了移动构造函数" << endl;
		if (m_date != nullptr) {
			delete m_date;	// 如果已分配内存，先释放掉，把指针空出来，准备指向新的资源
		}
		m_date = a.m_date;	//把资源从源对象中转移过来
		a.m_date = nullptr;	// 把源对象中的指针置空，它不再拥有资源
	}

	AA& operator=(const AA& a)	// 赋值函数
	{
		cout << "调用了赋值函数" << endl;
		if (this == &a) {	// 避免自我赋值
			return *this;	
		}
		if (m_date == nullptr) {	// 如果没有分配内存，就分配
			alloc();	
		}
		memcpy(m_date, a.m_date, sizeof(int));	//把数据从源对象中拷贝过来
		return *this;
	}


	AA& operator=(AA&& a)	// 移动赋值函数
	{
		cout << "&a=" << &a << endl;
		cout << "this=" << this << endl;
		cout << "调用了移动赋值函数" << endl;
		if (this == &a) {	// 避免自我赋值
			return *this;
		}
		if (m_date != nullptr) {	// 如果已分配内存，先释放掉，把指针空出来，准备指向新的资源
			delete m_date;
		}
		m_date = a.m_date;	// 把资源从源对象中转移过来
		a.m_date = nullptr;	// 把源对象的指针置空，它不再拥有资源
		return *this;
	}

	~AA()	// 析构函数
	{
		if (m_date != nullptr){
			delete m_date;
			m_date = nullptr;
		}
	}
};

//在c++11中，把拷贝数的操作叫拷贝语义。
//移动语义的意思是：不要拷贝，直接把资源转移过来（转移资源的操作叫移动语义）

// 不同的类，转移资源的方法是不同的，，移动构造函数和移动赋值函数的代码的写法也可能不一样，但是移动的语义是类似的

int main(void)
{
	//AA a1;
	//a1.alloc();	// 分配堆区内存
	//*a1.m_date = 3;	// 给堆区内存赋值
	//cout << "*a1.m_date=" << *a1.m_date << endl;

	//AA a2 = move(a1);	// 调用拷贝构造函数
	//cout << "*a2.m_date=" << *a2.m_date << endl;

	//AA a3;
	//a3 = move(a1);	// 调用赋值函数
	//cout << "*a3.m_date=" << *a3.m_date << endl;
	//cout << "------------------------------------" << endl;

	auto f = []()->AA 
	{ 
		AA aa; 
		aa.alloc();
		*aa.m_date = 8;
		cout << "对象aa的地址是" << &aa << endl;
		return aa; 
	};		// 返回AA类对象的lambda函数

	//AA a4 = f();	// 函数以值的方式返回AA类的临时对象，就是一个右值，将调用移动构造函数
	//cout << "*a4.m_date=" << *a4.m_date << endl;
	//cout << "&a4=" << &a4 << endl;

	AA a5;
	cout << "&a5=" << &a5 << endl;
	a5 = f();	// 调用移动赋值函数
	cout << "*a5.m_date=" << *a5.m_date << endl;
}