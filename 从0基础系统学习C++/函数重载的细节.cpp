#include <iostream>
using namespace std;

void show(short bh,string message)
{
    cout<<"short �װ���"<<bh<<"��:"<<message<<endl;
}

// void show(short& bh,string message)
// {
//     cout<<"short& �װ���"<<bh<<"��:"<<message<<endl;
// }

// void show(short& bh,string message,string gift="Сè")
// {
//     cout<<"short& �װ���"<<bh<<"��:"<<message<<"   gitf="<<gift<<endl;
// }

// void show(const short bh,string message)
// {
//     cout<<"const short �װ���"<<bh<<"��:"<<message<<endl;
// }


void show(long bh,string message)
{
    cout<<"long �װ���"<<bh<<"��:"<<message<<endl;
}


void show(double bh,string message)
{
    cout<<"double �װ���"<<bh<<"��:"<<message<<endl;
}

int main(void)
{
    short no=3;
    string str = "����һֻСС��";
    show(no,str);
    // show(no,str,"С��");
}