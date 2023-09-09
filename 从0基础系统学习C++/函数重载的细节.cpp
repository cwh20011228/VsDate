#include <iostream>
using namespace std;

void show(short bh,string message)
{
    cout<<"short 亲爱的"<<bh<<"号:"<<message<<endl;
}

// void show(short& bh,string message)
// {
//     cout<<"short& 亲爱的"<<bh<<"号:"<<message<<endl;
// }

// void show(short& bh,string message,string gift="小猫")
// {
//     cout<<"short& 亲爱的"<<bh<<"号:"<<message<<"   gitf="<<gift<<endl;
// }

// void show(const short bh,string message)
// {
//     cout<<"const short 亲爱的"<<bh<<"号:"<<message<<endl;
// }


void show(long bh,string message)
{
    cout<<"long 亲爱的"<<bh<<"号:"<<message<<endl;
}


void show(double bh,string message)
{
    cout<<"double 亲爱的"<<bh<<"号:"<<message<<endl;
}

int main(void)
{
    short no=3;
    string str = "我是一只小小鸟。";
    show(no,str);
    // show(no,str,"小狗");
}