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


	temp = new st_girl({ 3,"���",nullptr }); // �����һ���ڵ�
	head = tail = temp;	

	temp = new st_girl({ 4,"����",nullptr }); // ����ڶ����ڵ�
	tail->Next = temp;	// ʹβ�ڵ��Nextָ��ָ��ڶ����ڵ�
	tail = temp;	// βָ������ƶ���ָ���·���Ľڵ�

	temp = new st_girl({ 7,"QQ",nullptr });
	tail->Next = temp;
	tail = temp;

	temp = head; // headָ���¼�������ͷ��
	while (temp != nullptr)
	{
		cout << "��ţ�" << temp->bh << " ������" << temp->name << endl;
		temp = temp->Next;
	}

	while (head != nullptr)		// �ͷ�����
	{
		temp = head;	// ʹtempָ��ָ��ͷ���
		head = head->Next;	// ͷָ�����һ���ڵ��ƶ�
		delete temp;	// �ͷŵ�һ���ڵ�
	}

	return 0;
}