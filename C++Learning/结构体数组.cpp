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

int main(void)
{
    StGril grils[3];
    memset(grils, 0, sizeof(grils));

    strcpy(grils[0].name, "西施"); grils[0].age = 35; grils[0].weight = 48.5; grils[0].sex = 'X'; grils[0].yz = true;
    grils[1] = { "刘备",48,65.9,'Y',true };
    grils[2] = { "小刘",58,85.9,'Y',false };

    for (int i = 0; i < 3; i++)
    {
        cout << "姓名:" << grils[i].name << "  年龄:" << grils[i].age
            << "  体重:" << grils[i].weight << "  性别:"
            << grils[i].sex << "  颜值:" << grils[i].yz << endl;
    }
}