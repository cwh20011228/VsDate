#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
	T* items;	// ջ���飬��̬�������
	int stacksize; // ջ��ʵ�ʴ�С
	int top;  // ջ��ָ�루λ��ָ�룩
public:
	Stack(int size);	//! ���캯�������ã���1��Ϊջ����new�ڴ棨2����ʼ��ջ��ָ��(top=0)
	~Stack();	// �ͷŷ�����ڴ�ռ�
	bool isempty();	// �ж�ջ�Ƿ�Ϊ��
	bool isfull();  // �ж�ջ�Ƿ�����
	bool push(const T& item);  // Ԫ����ջ
	bool pop(T& item);	// Ԫ�س�ջ
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

	// Ԫ����ջ
	s1.push("��ʩ");
	s1.push("����");
	s1.push("����");
	s1.push("����");

	// Ԫ�س�ջ
	string num;
	while (s1.isempty() == false) {
		s1.pop(num);
		cout << num << endl;
	}

	return 0;
}