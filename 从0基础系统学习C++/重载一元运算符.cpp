#include <iostream>
using namespace std;

class CGirl
{
public:
    string m_name;
    int m_ranking;
    CGirl(){m_name="��ʩ";m_ranking=5;}
    void show(){ cout<<"������"<<m_name<<"��������"<<m_ranking<<endl;}
    // CGirl& operator++()     //TODO�����������ǰ��
    // {
    //     m_ranking++;
    //     return *this;
    // }

    // CGirl operator++(int)     //TODO���������������
    // {
    //     CGirl tmp  = *this;
    //     m_ranking++;
    //     return tmp;
    // }
};

CGirl& operator++(CGirl& g) // ���������ǰ��
{
    g.m_ranking++;
    return g;
}

CGirl operator++(CGirl& g, int)   //  �������������
{
    CGirl tmp;
    tmp=g;
    g.m_ranking++;
    return tmp;
}

CGirl operator--(CGirl& g,int) //  �Լ����������
{
    CGirl tmp;
    tmp=g;
    g.m_ranking--;
    return tmp;
}

CGirl& operator--(CGirl& g)     // �Լ������ǰ��
{
    g.m_ranking--;
    return g;
}


int main(void)
{
    CGirl g1,g2;
    // ++g1;
    // ++(++(++g1));
    // g1.show();
    // (g2++)++;
    // g2.show();  

    int ii=5,jj=5;
    int xx=++(++(++ii));    // ++ǰ�ÿ���Ƕ��
    int yy=jj++;    // ++���ò���Ƕ��
    cout<<"xx="<<xx<<"   ii="<<ii<<endl;
    cout<<"yy="<<yy<<"   jj="<<jj<<endl;

    CGirl g3  = ++(++(++g1));
    CGirl g4  = g2++;
    cout<<"g1.m_ranking="<<g1.m_ranking<<"  g3.m_ranking="<<g3.m_ranking<<endl;
    cout<<"g2.m_ranking="<<g2.m_ranking<<"  g4.m_ranking="<<g4.m_ranking<<endl;

    CGirl g5 = g3--;
    CGirl g6 = --(--g4);
    cout<<"g3.m_ranking="<<g3.m_ranking<<"  g5.m_ranking="<<g5.m_ranking<<endl;
    cout<<"g4.m_ranking="<<g4.m_ranking<<"  g6.m_ranking="<<g6.m_ranking<<endl;
    
    return 0;
}