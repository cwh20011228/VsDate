#include <iostream>
#include <cstring>
using namespace std;

struct StGril
{
    char name[21];
    int age;
    double weight;
    char sex;
    bool yz;
};


void func(const StGril *sg)
{
    cout<<"����:"<<sg->name<<"  ����:"<<sg->age<<"  ����:"
        <<sg->weight<<"  �Ա�:"<<sg->sex<<"  ��ֵ:"<<sg->yz<<endl;
}
int main(void)
{
    StGril stgril{"��ʩ",26,38.5,'X',true};
    StGril *stg=&stgril;
    cout<<"����:"<<stg->name<<"  ����:"<<stg->age<<"  ����:"
        <<stg->weight<<"  �Ա�:"<<stg->sex<<"  ��ֵ:"<<stg->yz<<endl;

    cout<<"����:"<<(*stg).name<<"  ����:"<<(*stg).age<<"  ����:"
        <<(*stg).weight<<"  �Ա�:"<<(*stg).sex<<"  ��ֵ:"<<(*stg).yz<<endl;
    func(stg);
    StGril *ssg=new StGril{0};

    // memset(ssg,0,sizeof(StGril));
    cout<<"����:"<<ssg->name<<"  ����:"<<ssg->age<<"  ����:"
        <<ssg->weight<<"  �Ա�:"<<ssg->sex<<"  ��ֵ:"<<ssg->yz<<endl;
    delete ssg;
}