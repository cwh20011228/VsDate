#include <iostream>
using namespace std;

void func(int no,const string &name="��ʩ",const string& str="��ϲ���㡣");

int main(void)
{
    func(3,"С��","����һֻɵɵ��");
    func(5,"����һֻ��ӥ");
    return 0;
}

void func(int no,const string &name,const string& str)
{
    cout<<"�װ���:"<<name<<" ("<<no<<") "<<str<<endl;
}