#include <iostream>
using namespace std;

class CGirl
{
private:
    string m_name;
    int m_yz;
    int m_sc;
    int m_acting;
public:
    CGirl(string name,int yz,int sc,int acting);
    ~CGirl();
    // 成员函数版本
    bool operator==(const CGirl& g1);  // 重载==关系运算符
    bool operator>(const CGirl& g1);
    bool operator<(const CGirl& g1);
};

CGirl::CGirl(string name,int yz,int sc,int acting):m_name(name),m_yz(yz),m_sc(sc),m_acting(acting)
{
    cout<<"The CGirl(string,int ,int,int) constructor was called."<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}

bool CGirl::operator==(const CGirl& g1)
{
    if((m_acting+m_sc+m_yz)==(g1.m_acting+g1.m_sc+g1.m_yz)) return true;
    else return false;
}

bool CGirl::operator>(const CGirl& g1)
{
    if((m_acting+m_sc+m_yz)>(g1.m_acting+g1.m_sc+g1.m_yz)) return true;
    else return false;
}

bool CGirl::operator<(const CGirl& g1)
{
    if((m_acting+m_sc+m_yz)<(g1.m_acting+g1.m_sc+g1.m_yz)) return true;
    else return false;
}


int main(void)
{
    CGirl c1("J1",2,3,4),c2("G1",2,5,7);
    int result;
    result = c1<c2;
    cout<<result<<endl;
    return 0;
}