#include <iostream>
using namespace std;

struct StGril{
    int no;
    string name;
    StGril *Next;
};

int main(void)
{
    StGril *head=nullptr, *tail = nullptr, *tmp = nullptr; // head 是头指针， tail 是尾指针， tmp 是临时指针
    tmp = new StGril({1,"西施",nullptr}); // 分配第一个节点
    // tmp->no=1;
    // tmp->name="西施";
    // tmp->Next=nullptr;
    head=tail=tmp;  // 让头指针，尾指针都指向它

    tmp = new StGril({6,"冰冰",nullptr});  // 分配第二个节点
    tail->Next=tmp; //把上一个节点的next指针指向新节点
    tail=tmp; // 移动尾指针，让尾指针指向当前新分配的节点

    tmp = new StGril({3,"蜜蜜",nullptr});  // 分配第三个节点
    tail->Next=tmp; //把上一个节点的next指针指向新节点
    tail=tmp; // 移动尾指针，让尾指针指向当前新分配的节点

    // 遍历链表
    tmp = head;  // 从头节点开始
    while(tmp!=nullptr)
    {
        cout<<"no="<<tmp->no<<"  name="<<tmp->name<<" tmp->Next="<<tmp->Next;
        tmp = tmp->Next;
        cout<<endl;
    }

    // 释放链表
    while(head!=nullptr)
    {
        tmp=head;
        head=head->Next;
        delete tmp;
    }

    return 0;
}