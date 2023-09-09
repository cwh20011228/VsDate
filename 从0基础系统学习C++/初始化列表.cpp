#include <iostream>
using namespace std;

class CBoy
{
public:
    string m_xm;
    CBoy();
    CBoy(string name);
    CBoy(const CBoy& bb);
    ~CBoy();
};

CBoy::CBoy()
{
    m_xm.clear();
    cout<<"The CBoy() constructor was called." << endl;
}

CBoy::CBoy(string name):m_xm(name)
{
    cout<<"The CBoy(string ) constructor was called." << endl;
}

CBoy::CBoy(const CBoy& bb):m_xm(bb.m_xm)
{
    cout<<"The CBoy(const CBoy& ) constructor was called." << endl;
}

CBoy::~CBoy()
{
    cout<<"The CBoy() destructor was called." << endl;
}


class CGirl
{
public:
    string m_name;
    const int m_age;
    CBoy& m_boy;
    //CGirl();
    CGirl(string name, int age,CBoy& boy);
    ~CGirl();
    void show();
};

/*
CGirl::CGirl() : m_name("Jake"), m_age(23)
{
    cout << "The CGir() constructor was called." << endl;
}
*/

void CGirl::show()
{
    cout << "name=" << m_name << "   age=" << m_age << "  BOY's name="<<m_boy.m_xm<<endl;
}
/*
CGirl::CGirl(string name, int age,CBoy& boy) : m_name(name), m_age(age)
{
    m_boy.m_xm=boy.m_xm;
    cout << "The CGir(string name,int age,CBoy boy) constructor was called." << endl;
}
*/


CGirl::CGirl(string name, int age,CBoy& boy) : m_name(name), m_age(age),m_boy(boy)
{
    cout<<"The address of object boy is "<<&boy<<endl;
    cout<<"The address of object m_boy is "<<&m_boy<<endl;
    // m_boy.m_xm=boy.m_xm;
    cout << "The CGir(string name,int age,CBoy boy) constructor was called." << endl;
}


/*
CGirl::CGirl(string name, int age,CBoy& boy) :m_age(age)
{
    // m_age=age;
    m_boy = boy; m_name=name;
    cout << "The CGir(string name,int age,CBoy boy) constructor was called." << endl;
}
*/

CGirl::~CGirl()
{
    cout << "The CGir() destructor was called." << endl;
}

//TODO: 用类创建对象时，先初始化构造函数的形参对象，再初始化类的成员
int main(void)
{
    CBoy boy0("JACK");
    cout<<"The address of object boy0 is "<<&boy0<<endl;
    CGirl g1("Jenny", 23,boy0);
    g1.show();
}