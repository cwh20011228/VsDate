#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    double m_weight;
    CGirl():m_bh(8),m_name("��ʩ"),m_weight(50.7){ cout<<"The CGirl() Constructor was called."<<endl;}
    operator int() {return m_bh;}
    operator double() {return m_weight;}
    operator string() {return m_name;}
    int to_int() {return m_bh;}
};

//TODO: explicit ʹ��ת������������ʾ�ĵ���

int main(void)
{
    CGirl g;
    // ��ʽת�������������� = ����߱������������ͣ����������ĸ�ת������
    int a=g;            cout<<"g.m_bh="<<g.m_bh<<"   a="<<a<<endl;
    string b=g;         cout<<"g.m_name="<<g.m_name<<"   b="<<b<<endl;
    double c=g;         cout<<"g.m_weight="<<g.m_weight<<"   c="<<c<<endl;

    // ��ʾת�����ڶ�����ǰ��ָ����������
    int d=(int)g;       cout<<"g.m_bh="<<g.m_bh<<"   d="<<d<<endl;
    string e=(string)g; cout<<"g.m_name="<<g.m_name<<"   e="<<e<<endl;
    double f=(double)g; cout<<"g.m_weight="<<g.m_weight<<"   f="<<f<<endl;
    // ��ʾת��
    int k=int(g);       cout<<"g.m_bh="<<g.m_bh<<"   k="<<k<<endl;
    string h=string(g); cout<<"g.m_name="<<g.m_name<<"   h="<<h<<endl;
    double j=double(g); cout<<"g.m_weight="<<g.m_weight<<"   j="<<j<<endl;

    // short l = g;  // ���ֶ����ԣ�int() �� double() �����ԣ���������֪��ѡ���ĸ�
    int m= g.to_int();
    return 0;
}