#include <iostream>
using namespace std;

// TODO: 结构体赋初始值只能一次，之后只能一个成员一个成员的赋值

class CGril
{
public:
    string name;
    int age;
    // int times=0;
private:
    double height;
    double weight;
    char sex = 'X'; // X:女   Y:男
    bool yz;        // 颜值
    string special; // 特长
    string memo;    // 备注
public:
    void show()
    {
        // if(times++>10) return;
        cout << "姓名:" << name << "  年龄:" << age << "  身高:" << height << "  体重:" << weight
            << "  性别:" << sex << "  颜值:" << yz << "  特长:" << special << "  备注:" << memo << endl;
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
    girl.setvalue("西施", 26, 170.5, 50.5, 'X', true, "唱，跳，rap", "篮球");
    girl.show();
    cout<<girl.name<<endl;
    // cout<<girl.yz<<endl;

}