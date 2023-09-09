#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    double m_weight;
    CGirl():m_bh(0),m_weight(0) { m_name.clear(); cout<<"The CGirl() constructor was called."<<endl;}
    void show() { cout<<"bh="<<m_bh<<"   name="<<m_name<<"   weight="<<m_weight<<endl;}
    CGirl(int bh):m_bh(bh),m_weight(0) {m_name.clear(); cout<<"The CGirl(int) constructor was called."<<endl;}  // ������constructor,����ת������
    CGirl(const CGirl& g):m_bh(g.m_bh),m_name(g.m_name),m_weight(g.m_weight) {cout<<"The CGirl(const CGirl&) constructor was called."<<endl;}
    CGirl(double weight):m_bh(0),m_weight(weight) { m_name.clear(); cout<<"The CGirl(double) constructor was called."<<endl;}
    ~CGirl() {cout<<"��������������\n";}
};

void func(CGirl g)
{
    g.show();
}

CGirl func1(){    return 8;}

CGirl func2(){    char c = 8;    return c;}


int main(void)
{
    // CGirl g1(8);    // ��ʾת��  
    // CGirl g2 = CGirl(8); //��ʾת�� 
    // CGirl g3=8;  // ��ʽת��,ֱ�Ӵ���  CGirl g3(8);
    // CGirl g4;
    // g4 = 8;  //  ��ʽת��,��CGirl(8)������ʱ����,�ٸ�ֵ��g4

    // g1.show();
    // g2.show();
    // g3.show();
    // g4.show();

    // CGirl g5 = 8.7;
    // g5.show();

    func(8);    // ��intֵ���ݸ����� CGirl�����ĺ���ʱ��������  ��ʽת��
    func1();    // ����ֵ������Ϊ CGirl �ĺ�����ͼ���� int ֵ �� ��ʽת�� �������˲���Ϊint��ת������
    func2();    // ���ֵ���������Ļ�������ת��Ϊ����������ת������
    return 0;
}