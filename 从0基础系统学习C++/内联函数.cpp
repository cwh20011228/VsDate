#include <iostream>
using namespace std;

inline void show(const short& bh,const string& message)
{
    cout<<"�װ���"<<bh<<"��:"<<message<<endl;
}

int main(void)
{
    show(3,"����һֻɵɵ��");
    // {
    //     int bh=3;
    //     string message = "����һֻɵɵ��";
    //     cout<<"�װ���"<<bh<<"��:"<<message<<endl;
    // }

    show(8,"����һֻСС��");
    // {
    //     int bh=8;
    //     string message = "����һֻСС��";
    //     cout<<"�װ���"<<bh<<"��:"<<message<<endl;
    // }

    show(5,"����һֻСС��");
    // {
    //     int bh=5;
    //     string message = "��ʱһֻСС��";
    //     cout<<"�װ���"<<bh<<"��:"<<message<<endl;
    // }
    return 0;
}