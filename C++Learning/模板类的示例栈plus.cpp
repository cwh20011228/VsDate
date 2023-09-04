#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
	T* items;	// 栈数组，动态分配出来
	int stacksize; // 栈的实际大小
	int top;  // 栈顶指针（位置指针）
public:
	Stack(int size);	//! 构造函数的作用：（1）为栈数组new内存（2）初始化栈顶指针(top=0)
	~Stack();	// 释放分配的内存空间
	bool isempty();	// 判断栈是否为空
	bool isfull();  // 判断栈是否已满
	bool push(const T& item);  // 元素入栈
	bool pop(T& item);	// 元素出栈
};

template <class T>
Stack<T>::Stack(int size) :stacksize{ size }, top{ 0 }
{
	items = new T[size];
}

template <class T>
Stack<T>::~Stack()
{
	delete[] items;
	items = nullptr;
}

template <class T>
bool Stack<T>::push(const T& item)
{
	if (top < stacksize) {
		items[top] = item;
		top = top + 1;
		return true;
	}
	else {
		return false;
	}
}

template <class T>
bool Stack<T>::isempty()
{
	if (top == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
bool Stack<T>::isfull()
{
	if (top == stacksize) {
		return true;
	}
	else {
		return false;
	}
}


template <class T>
bool Stack<T>::pop(T& item)
{
	if (isempty() == false) {
		top = top - 1;
		item = items[top];
		return true;
	}
	else {
		return false;
	}
}


int main(void)
{
	Stack<string> s1(6);

	// 元素入栈
	s1.push("西施");
	s1.push("西瓜");
	s1.push("张三");
	s1.push("李四");

	// 元素出栈
	string num;
	while (s1.isempty() == false) {
		s1.pop(num);
		cout << num << endl;
	}

	return 0;
}