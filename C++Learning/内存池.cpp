#include <iostream>
using namespace std;

/*	重载new和delete的目的是实现内存池
*/

class CGirl {
public:
	int m_bh;
	int m_xw;

	static char* m_pool; // 内存池的起始地址

	static bool initpool(); // 初始化内存池的函数
	static void freepool(); // 释放内存池
	CGirl(int bh,int xw);
	CGirl();
	~CGirl();
	void show();
	static void* operator new(size_t size);
	static void operator delete(void* ptr);
};

bool CGirl::initpool()
{
	m_pool = (char*)malloc(18); // 向系统申请18字节的内存,即18字节的内存池
	if (m_pool == 0) return false;
	memset(m_pool, 0, 18);
	cout << "内存池的起始地址是" << (void*)m_pool << endl;
	return true;
}

void CGirl::freepool()
{
	if (m_pool == 0) return;  // 如果内存池为空，不需要释放，直接返回
	free(m_pool);
	cout << "内存池已释放" << endl;
}

CGirl::CGirl(int bh, int xw) :m_bh{ bh }, m_xw{ xw }
{
	cout << "调用了构造函数CGirl(int bh, int xw)" << endl;
}

CGirl::CGirl() :m_bh{ 10 }, m_xw{ 87 }
{
	cout << "调用了构造函数CGirl()" << endl;
}

CGirl::~CGirl()
{
	cout << "调用了析构函数~CGirl()" << endl;
}

void CGirl::show()
{
	cout << "编号=" << m_bh << "  XW=" << m_xw << endl;
}

// 重载的new 和delete函数默认是静态成员函数，静态只能访问静态，
void* CGirl::operator new(size_t size)
{
	if (m_pool[0] == 0) {	// 判断第一个位置是否空闲
		cout << "分配了第一块内存：" << (void*)(m_pool + 1) << endl;
		m_pool[0] = 1; // 把第一个位置标记为已分配，即第一个位置是做标记作用的
		return m_pool + 1; // 返回第一个用于存放的地址
	}

	if (m_pool[9] == 0) {	// 判断第2个位置是否空闲
		cout << "分配了第二块内存：" << (void*)(m_pool + 9) << endl;
		m_pool[9] = 1; // 把第9个位置标记为已分配，即第一个位置是做标记作用的
		return m_pool + 9; // 返回第一个用于存放的地址
	}
	// 如果以上两个位置不可用，就直接向系统申请内存
	void* ptr = malloc(size);
	cout << "申请到的系统内存的地址是：" << ptr << endl;
	return ptr;
}
//如果内存池用完了，三种解决方法：
//（1）扩展内存池
//（2）直接向系统申请内存
//（3）返回空地址

void CGirl::operator delete(void* ptr)
{
	if (ptr == 0) return; // 如果传进来的地址为空，直接返回
	if (ptr == m_pool + 1) {	// 如果传进来的地址是内存池中的第一个位置
		cout << "释放了第一块内存" << endl;
		m_pool[0] = 0;	// 将第一个位置置0，表示第一块内存空闲
		return;
	}
	if (ptr == m_pool + 9) {	// 如果传进来的地址是内存池的第二个位置
		cout << "释放了第二块内存" << endl;
		m_pool[9] = 0;	// 将第9个位置置0，表示第2块内存空闲
		return;
	}
	// 如果传进来的地址不属于内存池，把它归还给系统
	free(ptr);
}

char* CGirl::m_pool = nullptr;

int main(void)
{
	// 初始化内存池
	if (CGirl::initpool() == false) {
		cout << "初始化内存池失败。" << endl;
		return -1;
	}

	CGirl* g1 = new CGirl{ 20,87 };	//分配内存池中的第一块地址
	cout << "g1的地址是" << g1 <<"   编号："<<g1->m_bh<<"  xw="<<g1->m_xw << endl;

	CGirl* g2 = new CGirl{ 20,87 };		//分配内存池中的第2块地址
	cout << "g2的地址是" << g2 << "   编号：" << g2->m_bh << "  xw=" << g2->m_xw << endl;

	CGirl* g3 = new CGirl{ 20,87 };		//分配系统中的地址
	cout << "g3的地址是" << g3 << "   编号：" << g3->m_bh << "  xw=" << g3->m_xw << endl;


	delete g1;	// 释放内存池第一块地址

	CGirl* g4 = new CGirl{ 20,87 };		//分配内存池中的第一块地址
	cout << "g1的地址是" << g4 << "   编号：" << g4->m_bh << "  xw=" << g4->m_xw << endl;

	delete g2;
	delete g3;
	delete g4;

	CGirl::freepool(); // 释放内存池
}