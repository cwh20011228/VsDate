#include <iostream>
using namespace std;

// TODO: �ṹ�帳��ʼֵֻ��һ�Σ�֮��ֻ��һ����Աһ����Ա�ĸ�ֵ

class CGril
{
public:
    string name;
    int age;
    // int times=0;
private:
    double height;
    double weight;
    char sex = 'X'; // X:Ů   Y:��
    bool yz;        // ��ֵ
    string special; // �س�
    string memo;    // ��ע
public:
    void show()
    {
        // if(times++>10) return;
        cout << "����:" << name << "  ����:" << age << "  ���:" << height << "  ����:" << weight
            << "  �Ա�:" << sex << "  ��ֵ:" << yz << "  �س�:" << special << "  ��ע:" << memo << endl;
        show();
    }

    void setvalue(string name1, int age1, double height1, double weight1, char sex1, bool yz1, string special1, string memo1);
};

void CGril::setvalue(string name1, int age1, double height1, double weight1, char sex1, bool yz1, string special1, string memo1)
    {
        name = name1;
        age = age1;
        height = height1;
        weight = weight1;
        sex = sex1;
        yz = yz1;
        special = special1;
        memo = memo1;
        // show();
    }

int main(void)
{
    CGril girl;
    girl.setvalue("��ʩ", 26, 170.5, 50.5, 'X', true, "��������rap", "����");
    girl.show();
    cout<<girl.name<<endl;
    // cout<<girl.yz<<endl;

}