#include <iostream>
using namespace std;


void func1(int no,string str) //��ֵ
{
    no=8;
    str = "����һֻСС��";
    cout<<"�װ���"<<no<<"��:"<<str<<endl;
}

void func2(int *no,string *str) //��ָ��
{
    *no=8;
    *str = "����һֻСС��";
    cout<<"�װ���"<<*no<<"��:"<<*str<<endl;
}

void func3(int &no,string &str) //������
{
    no=8;
    str = "����һֻСС��";
    cout<<"�װ���"<<no<<"��:"<<str<<endl;
}

int main(void)
{
    int bh = 3;
    string message = "����һֻɵɵ��.";

    // func1(bh,message);
    // func2(&bh,&message);
    func3(bh,message);
    cout<<"�װ���"<<bh<<"��:"<<message<<endl;

    return 0;
}