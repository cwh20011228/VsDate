#include <iostream>
using namespace std;

struct Pet
{
    char name[21];
    char type[21];
};

struct StGril
{
    char name[21];
    int scor[3];
    int sscore[2][3] = { {11,12,13},{21,22,23} };
    int age=25;
    double weight=36.2;
    char sex=1;
    bool yz=false;
};

struct Boy
{
    char name[21];
    int age;
    double weight;
    char sex;
    bool yz;
    struct Pet ppet;
};


void func(StGril* pst)
{
    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            cout << "pst->sscore[" << ii << "][" << jj << "]=" << pst->sscore[ii][jj] << "  ";
        }
        cout << endl;
    }
}
int main(void) {
    StGril gril;
    // for(int ii=0;ii<3;ii++)
    // {
    //     gril.score[ii]=86+ii;
    // }

    // for(int ii=0;ii<3;ii++)
    // {
    //     cout<<gril.score[ii]<<"  ";
    // }
    func(&gril);
    cout << endl;

    Boy bboy = { "小刘",25,45.3,'Y',true,{"大黄","小狗"} };
    bboy = { "小李",35,45.7,'Y',false,{"贝贝","天蛾"} }; //TODO：C++11标准的语法
    bboy.ppet = { "小黑","偷袈裟的小狗" };  //TODO：C++11标准的语法

}