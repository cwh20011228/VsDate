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
    cout<<"姓名:"<<sg->name<<"  年龄:"<<sg->age<<"  体重:"
        <<sg->weight<<"  性别:"<<sg->sex<<"  颜值:"<<sg->yz<<endl;
}
int main(void)
{
    StGril stgril{"西施",26,38.5,'X',true};
    StGril *stg=&stgril;
    cout<<"姓名:"<<stg->name<<"  年龄:"<<stg->age<<"  体重:"
        <<stg->weight<<"  性别:"<<stg->sex<<"  颜值:"<<stg->yz<<endl;

    cout<<"姓名:"<<(*stg).name<<"  年龄:"<<(*stg).age<<"  体重:"
        <<(*stg).weight<<"  性别:"<<(*stg).sex<<"  颜值:"<<(*stg).yz<<endl;
    func(stg);
    StGril *ssg=new StGril{0};

    // memset(ssg,0,sizeof(StGril));
    cout<<"姓名:"<<ssg->name<<"  年龄:"<<ssg->age<<"  体重:"
        <<ssg->weight<<"  性别:"<<ssg->sex<<"  颜值:"<<ssg->yz<<endl;
    delete ssg;
}