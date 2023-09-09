#include <iostream>
using namespace std;

inline void show(const short& bh,const string& message)
{
    cout<<"亲爱的"<<bh<<"号:"<<message<<endl;
}

int main(void)
{
    show(3,"我是一只傻傻鸟");
    // {
    //     int bh=3;
    //     string message = "我是一只傻傻鸟";
    //     cout<<"亲爱的"<<bh<<"号:"<<message<<endl;
    // }

    show(8,"我有一只小小鸟");
    // {
    //     int bh=8;
    //     string message = "我有一只小小鸟";
    //     cout<<"亲爱的"<<bh<<"号:"<<message<<endl;
    // }

    show(5,"我是一只小小鸟");
    // {
    //     int bh=5;
    //     string message = "我时一只小小鸟";
    //     cout<<"亲爱的"<<bh<<"号:"<<message<<endl;
    // }
    return 0;
}