#include <iostream>
using namespace std;

class CGirl
{
public:
    string m_name;
    int m_ranking;
    CGirl(){m_name="西施";m_ranking=5;}
    void show(){ cout<<"姓名："<<m_name<<"，排名："<<m_ranking<<endl;}
    // CGirl& operator++()     //TODO：自增运算符前置
    // {
    //     m_ranking++;
    //     return *this;
    // }

    // CGirl operator++(int)     //TODO：自增运算符后置
    // {
    //     CGirl tmp  = *this;
    //     m_ranking++;
    //     return tmp;
    // }
};

CGirl& operator++(CGirl& g) // 自增运算符前置
{
    g.m_ranking++;
    return g;
}

CGirl operator++(CGirl& g, int)   //  自增运算符后置
{
    CGirl tmp;
    tmp=g;
    g.m_ranking++;
    return tmp;
}

CGirl operator--(CGirl& g,int) //  自减运算符后置
{
    CGirl tmp;
    tmp=g;
    g.m_ranking--;
    return tmp;
}

CGirl& operator--(CGirl& g)     // 自减运算符前置
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
    int xx=++(++(++ii));    // ++前置可以嵌套
    int yy=jj++;    // ++后置不能嵌套
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