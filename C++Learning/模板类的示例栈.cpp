#include <iostream>
using namespace std;

typedef string DataType;

class Stack
{
private:
	DataType* items;  // 栈数组，栈的元素用整数数组存放，动态分配出来
	int stacksize;	//栈实际的大小
	int top;	//栈顶指针 ，用整数，不是c++中的指针，而是位置指针
public:
	// 构造函数要干两件事：（1）分配栈数组内存（2）初始化栈顶指针（把栈顶指针初始化为0）
	Stack(int size) :stacksize{ size }, top{ 0 } 
	{
		items = new DataType[stacksize];
	}

	~Stack() 
	{
		delete[] items;
		items = nullptr;
	}

	bool isempty() const		// 判断栈是否为空
	{
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isfull() const		// 判断栈是否已满
	{
		if (top == stacksize) {
			return true;
		}else{
			return false;
		}
	}

	bool push(const DataType& item)		// 元素入栈
	{
		if (top < stacksize)
		{
			items[top] = item;
			top = top + 1;
			/* items[top++]=item;*/
			return true;
		}else{
			return false; //	入栈失败
		}
	}

	bool pop(DataType& item)		// 元素出栈
	{
		if (top > 0) {		// 栈如果没空的话，就可以出栈
			
			top = top - 1;
			item = items[top];
			 //item=items[--top];
			return true;
		}
		else {
			return false;
		}
	}
};

int main(void)
{
	Stack ss(5);   // 创建栈对象，大小是5

	// 元素入栈
	ss.push("西施");
	ss.push("西瓜");
	ss.push("李白");
	ss.push("张三");
	ss.push("李四");

	// 元素出栈
	DataType item;
	while (ss.isempty() == false)
	{
		ss.pop(item);
		cout << item <<endl;
	}


	return 0;
}