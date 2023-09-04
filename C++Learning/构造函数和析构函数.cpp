#include <iostream>
#include <cstring>
using namespace std;

class CGirl {
public:
    string m_name;
    int m_age;
    char m_memo[301];
    //int* m_ptr;

    CGirl();
    CGirl(string name);
    CGirl(string name, int age);
    void SetValue(string name, int age);
    void show();
    ~CGirl();
};

CGirl::CGirl()
{
    m_name.clear();
    m_age = 0;
    memset(m_memo, 0, sizeof(m_memo));
    //m_ptr = nullptr;
    cout<<"The CGirl() constructor was called."<<endl;
}

CGirl::CGirl(string name)
{
    CGirl();    // 创建的是匿名临时对象，没有名字，创建后马上被销毁 
    // m_name.clear();
    // m_age = 0;
    // memset(m_memo,0,sizeof(m_memo));
    m_name = name;
    // cout<<"The CGirl(string) constructor was called."<<endl;
}

CGirl::CGirl(string name, int age)
{
    cout << "aaa\n";
    CGirl();
    cout << "bbb\n";
    // m_name.clear();
    // m_age = age;
    // memset(m_memo,0,sizeof(m_memo));
    m_name = name;
    // cout<<"The CGirl(string,int) constructor was called."<<endl;
}

void CGirl::SetValue(string name, int age)
{
    m_name = name;
    m_age = age;
}

void CGirl::show()
{
    cout << "姓名：" << m_name << "  年龄：" << m_age << "  备注：" << m_memo << endl;
}

CGirl::~CGirl()
{
    m_name.clear();
    m_age = 0;
    memset(m_memo, 0, sizeof(m_memo));
    //if (m_ptr != nullptr) delete m_ptr;
    cout << "The destructor ~CGirl() was called." << endl;
    
}

int main()
{
    CGirl girl("Jack", 25);
    // CGirl girl;
    girl.show();
    // girl.~CGirl();
    CGirl gril1 = CGirl();
    gril1.show();

    return 0;
}