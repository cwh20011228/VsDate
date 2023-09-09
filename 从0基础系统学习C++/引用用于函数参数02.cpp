#include <iostream>
using namespace std;

struct StGril
{
    int no; // 编号
    string str; // 表白内容
};

void func1(StGril gril) //传值
{
    gril.no=8;
    gril.str = "我有一只小小鸟。";
    cout<<"亲爱的"<<gril.no<<"号:"<<gril.str<<endl;
}

void func2(StGril *gril) //传指针
{
    gril->no=8;
    gril->str = "我有一只小小鸟。";
    cout<<"亲爱的"<<gril->no<<"号:"<<gril->str<<endl;
}

void func3(StGril & gril) //传引用
{
    gril.no=8;
    gril.str = "我有一只小小鸟。";
    cout<<"亲爱的"<<gril.no<<"号:"<<gril.str<<endl;
}

int main(void)
{
    StGril grill{3,"我是一只傻傻鸟"};

    func1(grill);
    func2(&grill);
    // func3(grill);
    cout<<"亲爱的"<<grill.no<<"号:"<<grill.str<<endl;

    return 0;
}