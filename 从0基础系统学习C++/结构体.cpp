#include <iostream>
using namespace std;

#pragma pack(8)   // TODO:�޸��ڴ����ļ��������һ��������ָ��������ýṹ���Ա������8�ֽڶ���
#include <cstring>

struct StGril
{
    char name[21];
    int age;
    double weight;
    char sex;
    bool yz;
} ST{"��ʩ",25,48.6,'X',false};

#pragma pack()  //todo: �ڽṹ�������дһ�� pragma pack(), �ָ�ԭ�еĶ��뷽ʽ

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
    StGril ST{"��ʩ",25,48.6,'X',false};
    StGril st;
    memset(&st,0,sizeof(st));
    // memcpy(&st,&ST,sizeof(ST));  // ����
    st=ST;
    cout << "����:" << ST.name << "\t"
         << "����:" << ST.age << "\t"
         << "����:" << ST.weight << "\t"
         << "�Ա�:" << ST.sex << "\t"
         << "��ֵ:" << ST.yz << endl;
    // cout<<sizeof(ST)<<endl;
    cout << "����:" << st.name << "\t"
         << "����:" << st.age << "\t"
         << "����:" << st.weight << "\t"
         << "�Ա�:" << st.sex << "\t"
         << "��ֵ:" << st.yz << endl;
}