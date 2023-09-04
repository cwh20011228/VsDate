#include <iostream>
using namespace std;
// 模板的作用就是代码重用
// 函数模板不支持模板的模板参数

template <class T1,int len>
class LinkList {		//! 链表类模板
public:
	T1* m_head;			// 链表头结点
	int m_len = len;	// 表长
	void insert() { cout << "向链表中插入了一条记录。" << endl; }
	void ddelte() { cout << "向链表中删除了一条记录。" << endl; }
	void update() { cout << "向链表中更新了一条记录。" << endl; }
};


template <class T1,int len>
class Array {			//! 数组类模板
public:
	T1* m_data;			// 数组指针
	int m_len = len;	// 表长
	void insert() { cout << "向数组中插入了一条记录。" << endl; }
	void ddelte() { cout << "向数组中删除了一条记录。" << endl; }
	void update() { cout << "向数组中更新了一条记录。" << endl; }

};

//! C++支持模板的模板，把模板名当作一种特殊的数据类型。实例化对象的时候，可以用模板名作为参数，传给模板

// 线性表模板类：tabletype-线性表类型   datatype-线性表的数据类型
template <template<class,int> class tabletype,class datatype,int len>
//TODO: template<class,int> 表示要填两个参数的模板名， 并且要求类模板的第一个参数是通用类型，第二个参数是int型
class LinearList {
public:
	tabletype<datatype, len> m_table;		// 创建线性表对象
	void insert() { m_table.insert(); }		// 线性表插入操作
	void ddelte() { m_table.ddelte(); }		// 线性表删除操作
	void update() { m_table.update(); }		// 线性表更新操作

	void oper()	// 按业务要求操作线性表
	{
		cout << "len=" << m_table.m_len << endl;
		m_table.insert();
		m_table.update();
	}
};

int main(void)
{
	//创建线性表对象，容器类型为链表，链表的数据类型为int，表长为20
	LinearList<LinkList, int, 20> a;
	a.insert();		a.ddelte();		a.update();

	// 创建线性表对象，容器类型为数组，数组的数据类型为string，表长为20
	LinearList<Array, string, 20> b;
	b.insert();		b.ddelte();		b.update();

}