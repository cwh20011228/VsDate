#include <iostream>
using namespace std;

struct StGril
{
    int no; // ���
    string str; // �������
};

void func1(StGril gril) //��ֵ
{
    gril.no=8;
    gril.str = "����һֻСС��";
    cout<<"�װ���"<<gril.no<<"��:"<<gril.str<<endl;
}

void func2(StGril *gril) //��ָ��
{
    gril->no=8;
    gril->str = "����һֻСС��";
    cout<<"�װ���"<<gril->no<<"��:"<<gril->str<<endl;
}

void func3(StGril & gril) //������
{
    gril.no=8;
    gril.str = "����һֻСС��";
    cout<<"�װ���"<<gril.no<<"��:"<<gril.str<<endl;
}

int main(void)
{
    StGril grill{3,"����һֻɵɵ��"};

    func1(grill);
    func2(&grill);
    // func3(grill);
    cout<<"�װ���"<<grill.no<<"��:"<<grill.str<<endl;

    return 0;
}