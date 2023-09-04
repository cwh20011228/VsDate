#include <iostream>
using namespace std;

typedef string DataType;

class Stack
{
private:
	DataType* items;  // ջ���飬ջ��Ԫ�������������ţ���̬�������
	int stacksize;	//ջʵ�ʵĴ�С
	int top;	//ջ��ָ�� ��������������c++�е�ָ�룬����λ��ָ��
public:
	// ���캯��Ҫ�������£���1������ջ�����ڴ棨2����ʼ��ջ��ָ�루��ջ��ָ���ʼ��Ϊ0��
	Stack(int size) :stacksize{ size }, top{ 0 } 
	{
		items = new DataType[stacksize];
	}

	~Stack() 
	{
		delete[] items;
		items = nullptr;
	}

	bool isempty() const		// �ж�ջ�Ƿ�Ϊ��
	{
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isfull() const		// �ж�ջ�Ƿ�����
	{
		if (top == stacksize) {
			return true;
		}else{
			return false;
		}
	}

	bool push(const DataType& item)		// Ԫ����ջ
	{
		if (top < stacksize)
		{
			items[top] = item;
			top = top + 1;
			/* items[top++]=item;*/
			return true;
		}else{
			return false; //	��ջʧ��
		}
	}

	bool pop(DataType& item)		// Ԫ�س�ջ
	{
		if (top > 0) {		// ջ���û�յĻ����Ϳ��Գ�ջ
			
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
	Stack ss(5);   // ����ջ���󣬴�С��5

	// Ԫ����ջ
	ss.push("��ʩ");
	ss.push("����");
	ss.push("���");
	ss.push("����");
	ss.push("����");

	// Ԫ�س�ջ
	DataType item;
	while (ss.isempty() == false)
	{
		ss.pop(item);
		cout << item <<endl;
	}


	return 0;
}