#include <iostream>
using namespace std;

class CGirl
{  
public:
    string m_name;
    static int m_age;
    CGirl(const string& name,int age);
    void showname();
    static void showage();
    ~CGirl();
};



CGirl::CGirl(const string& name,int age):m_name(name)
{
    m_age=age;
    cout<<"The CGir(const string& name,int yz) constructor was called."<<endl;
}

void CGirl::showage()
{
    cout<<"���䣺"<<m_age<<endl;
}
// TODO: ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
// ��̬��Ա�������ô������󣬾Ϳ��Է��ʺ���
// ��̬��Ա���������ڶ���û��thisָ��
void CGirl::showname()
{
    cout<<"������"<<m_name<<endl;
    // showage(); //�Ǿ�̬��Ա���Է��ʾ�̬�ͷǾ�̬
}

CGirl::~CGirl()
{
    cout<<"The ~CGir() destructor was called."<<endl;
}

int CGirl::m_age=8;  //TODO: ��ʼ����ľ�̬��Ա����

int main(void)
{
    // CGirl::showage();
    // cout<<CGirl::m_age<<endl;
    CGirl g1("��ʩ1",23),g2("��ʩ2",23),g3("��ʩ3",23);
    g1.showage();
    g1.showname();
    g2.showage();
    g2.showname();
    g3.showage();
    g3.showname();
    return 0;
}