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

    Boy bboy = { "С��",25,45.3,'Y',true,{"���","С��"} };
    bboy = { "С��",35,45.7,'Y',false,{"����","���"} }; //TODO��C++11��׼���﷨
    bboy.ppet = { "С��","͵���ĵ�С��" };  //TODO��C++11��׼���﷨

}