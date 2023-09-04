#include <iostream>
using  namespace std;

struct st_girl {
	int bh;
	string name;
	st_girl* Next;
};

int main()
{
	st_girl* head = nullptr, * tail = nullptr, * temp = nullptr;


	temp = new st_girl({ 3,"彬彬",nullptr }); // 分配第一个节点
	head = tail = temp;	

	temp = new st_girl({ 4,"哈哈",nullptr }); // 分配第二个节点
	tail->Next = temp;	// 使尾节点的Next指针指向第二个节点
	tail = temp;	// 尾指针向后移动，指向新分配的节点

	temp = new st_girl({ 7,"QQ",nullptr });
	tail->Next = temp;
	tail = temp;

	temp = head; // head指针记录着链表的头部
	while (temp != nullptr)
	{
		cout << "编号：" << temp->bh << " 姓名：" << temp->name << endl;
		temp = temp->Next;
	}

	while (head != nullptr)		// 释放链表
	{
		temp = head;	// 使temp指针指向头结点
		head = head->Next;	// 头指针向后一个节点移动
		delete temp;	// 释放第一个节点
	}

	return 0;
}