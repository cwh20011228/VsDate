#include <iostream>
using namespace std;

void func(int *no,string *str);

int main(void)
{
    int *bh=nullptr;//=new int{3};
    string *message=nullptr;// = new string{"我是一只傻傻鸟"};
    func(bh,message);
    return 0;
}

void func(int *no,string *str)
{
    if(no==nullptr || str==nullptr) return ;
    cout<<"亲爱的"<<*no<<"号:"<<*str<<endl;
}