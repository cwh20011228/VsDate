#include <iostream>
using namespace std;

#pragma pack(8)   // TODO:修改内存对齐的间隔。这是一个编译器指令，用于设置结构体成员变量以8字节对齐
#include <cstring>

struct StGril
{
    char name[21];
    int age;
    double weight;
    char sex;
    bool yz;
} ST{"西施",25,48.6,'X',false};

#pragma pack()  //todo: 在结构体后面再写一个 pragma pack(), 恢复原有的对齐方式

void func()
{
    StGril gril;
}

int main(void)
{

    // cout<<sizeof(StGril)<<endl;
    // cout<<sizeof(string)<<endl;
    // cout<<sizeof(ST.name)<<endl;
    // cout<<sizeof(ST.sex)<<endl;
    // cout<<sizeof(ST.yz)<<endl;
    // cout<<sizeof(ST.age)<<endl;
    // cout<<sizeof(ST.weight)<<endl;
    StGril ST{"西施",25,48.6,'X',false};
    StGril st;
    memset(&st,0,sizeof(st));
    // memcpy(&st,&ST,sizeof(ST));  // 复制
    st=ST;
    cout << "姓名:" << ST.name << "\t"
         << "年龄:" << ST.age << "\t"
         << "体重:" << ST.weight << "\t"
         << "性别:" << ST.sex << "\t"
         << "颜值:" << ST.yz << endl;
    // cout<<sizeof(ST)<<endl;
    cout << "姓名:" << st.name << "\t"
         << "年龄:" << st.age << "\t"
         << "体重:" << st.weight << "\t"
         << "性别:" << st.sex << "\t"
         << "颜值:" << st.yz << endl;
}