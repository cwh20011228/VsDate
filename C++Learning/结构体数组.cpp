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

    strcpy(grils[0].name, "��ʩ"); grils[0].age = 35; grils[0].weight = 48.5; grils[0].sex = 'X'; grils[0].yz = true;
    grils[1] = { "����",48,65.9,'Y',true };
    grils[2] = { "С��",58,85.9,'Y',false };

    for (int i = 0; i < 3; i++)
    {
        cout << "����:" << grils[i].name << "  ����:" << grils[i].age
            << "  ����:" << grils[i].weight << "  �Ա�:"
            << grils[i].sex << "  ��ֵ:" << grils[i].yz << endl;
    }
}