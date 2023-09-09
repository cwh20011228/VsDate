#include <iostream>
#include <cstring>
using namespace std;

class CGirl{
    public:
        string m_name;
        int m_age;
        char m_memo[301];

        CGirl(); 
        CGirl(string name);
        CGirl(string name,int age);
        void SetValue(string name,int age);
        void show();
        void initdata();
        ~CGirl();
};

CGirl::CGirl()
{
    // m_name.clear();
    // m_age = 0;
    // memset(m_memo,0,sizeof(m_memo));
    initdata();
    cout<<"The CGirl() constructor was called."<<endl;
}

CGirl::CGirl(string name)
{
    // m_name.clear();
    // m_age = 0;
    // memset(m_memo,0,sizeof(m_memo));
    initdata();
    m_name = name;
    cout<<"The CGirl(string) constructor was called."<<endl;
}

CGirl::CGirl(string name,int age)
{
    // m_name.clear();
    // m_age = 0;
    // memset(m_memo,0,sizeof(m_memo));
    initdata();
    m_age = age;
    m_name = name;
    cout<<"The CGirl(string,int) constructor was called."<<endl;
}

void CGirl::SetValue(string name,int age)
{
    m_name = name;
    m_age = age;
}

void CGirl::show()
{
    cout<<"ÐÕÃû£º"<<m_name<<"  ÄêÁä£º"<<m_age<<"  ±¸×¢£º"<<m_memo<<endl;
}

CGirl::~CGirl()
{
    m_name.clear();
    m_age = 0;
    memset(m_memo,0,sizeof(m_memo));
    cout<<"The destructor ~CGirl() was called."<<endl;
}

void CGirl::initdata()
{
    m_name.clear();
    m_age = 0;
    memset(m_memo,0,sizeof(m_memo));
}

int main()
{   
    // CGirl girl("Jack",25);
    // CGirl girl;
    // girl = CGirl("Jack",25);
    // girl.show();
    // girl.~CGirl();
    // CGirl *girl = new CGirl("Jack",25);
    //  CGirl *girl = new CGirl();
    // girl->show();
    // delete girl;

    // CGirl girl = {"Jack",25};
    // CGirl girl {"Jack",25};
    CGirl *girl= new CGirl{"Jack",25};
    girl->show();
    delete girl;

    return 0;
}