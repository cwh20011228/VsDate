#include <iostream>
using namespace std;

struct StGril{
    int no;
    string name;
    StGril *Next;
};

int main(void)
{
    StGril *head=nullptr, *tail = nullptr, *tmp = nullptr; // head ��ͷָ�룬 tail ��βָ�룬 tmp ����ʱָ��
    tmp = new StGril({1,"��ʩ",nullptr}); // �����һ���ڵ�
    // tmp->no=1;
    // tmp->name="��ʩ";
    // tmp->Next=nullptr;
    head=tail=tmp;  // ��ͷָ�룬βָ�붼ָ����

    tmp = new StGril({6,"����",nullptr});  // ����ڶ����ڵ�
    tail->Next=tmp; //����һ���ڵ��nextָ��ָ���½ڵ�
    tail=tmp; // �ƶ�βָ�룬��βָ��ָ��ǰ�·���Ľڵ�

    tmp = new StGril({3,"����",nullptr});  // ����������ڵ�
    tail->Next=tmp; //����һ���ڵ��nextָ��ָ���½ڵ�
    tail=tmp; // �ƶ�βָ�룬��βָ��ָ��ǰ�·���Ľڵ�

    // ��������
    tmp = head;  // ��ͷ�ڵ㿪ʼ
    while(tmp!=nullptr)
    {
        cout<<"no="<<tmp->no<<"  name="<<tmp->name<<" tmp->Next="<<tmp->Next;
        tmp = tmp->Next;
        cout<<endl;
    }

    // �ͷ�����
    while(head!=nullptr)
    {
        tmp=head;
        head=head->Next;
        delete tmp;
    }

    return 0;
}