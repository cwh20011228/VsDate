#include <iostream>
using namespace std;

class CGirl
{
public:
    string m_name;
    int m_yz;
    CGirl(const string& name, int yz);  // constructor
    void show() const ;
    ~CGirl();                           //  destructor
    const CGirl& pk(const CGirl& g) const;
};

CGirl::CGirl(const string& name, int yz):m_name(name),m_yz(yz)
{
    cout<<"The CGir(const string& name,int yz) constructor was called."<<endl;
}

void CGirl::show() const
{
    cout<<"����:  "<<m_name<<",��Ư���ĳ�Ů��"<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGir() destructor was called."<<endl;
}

const CGirl& CGirl::pk(const CGirl& g) const
{
    // cout<<"The address of the this is "<<this<<endl;
    if(this->m_yz>g.m_yz) return *this;
    return g;
}

const CGirl& pk(const CGirl& gg1, const CGirl& gg2)
{
    if(gg1.m_yz>gg2.m_yz)  return gg1;
    return gg2;
}

// TODO: ˭�����˳�Ա������thisָ���ָ��˭
// ���Ҫ����ĳ�Ա�����з����Լ���ָ������ã�Ҫ�õ�thisָ��
// ������ֻ�ܷ��ʼ���constԼ���ĳ�Ա����
int main(void)
{
    CGirl g1("��ʩ",1),g2("����",2),g3("����",3),g4("СС",4),g5("����",5);
    /*cout<<"The address of the g1 is "<<&g1<<endl;
    cout<<"The address of the g2 is "<<&g2<<endl;*/
    //const CGirl& g3 = pk(g1,g2);
    const CGirl& g =g1.pk(g2).pk(g3).pk(g4).pk(g5); //TODO�� 5����Ů���бȽ�
    // const CGirl& g3 =g2.pk(g1);
    g.show();
    return 0;
}