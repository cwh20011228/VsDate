#include <iostream>
using namespace std;


class CGirl
{
friend void addscore(CGirl& g1,int score);
// friend void operator+(CGirl& g1,int score);
friend CGirl& operator+(CGirl& g1,int score);
friend CGirl& operator-(CGirl& g1,int score);
friend CGirl& operator+(int score,CGirl& g1);
friend CGirl& operator+(CGirl& g1,CGirl& g2);
/*friend void operator*(int& a,int &b);*/  //todo:���غ����Ĳ����б��б�����һ���û��Զ�������ͣ����ö�٣��������β�ȫΪ�������͵ģ�ֱ�ӱ���
private:
private:
    int m_xw;
    int m_score;
public:
    string m_name;
    CGirl();
    ~CGirl();
    void show();
    // void operator +(int score);
    // CGirl& operator-(int score);
};

CGirl::CGirl()
{
    m_name="��ʩ";
    m_xw=87;
    m_score=30;
    cout<<"The CGirl() constructor was called. "<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}

void CGirl::show()
{
    cout<<"������"<<m_name<<", ��Χ��"<<m_xw<<"�����֣�"<<m_score<<endl;
}

// void CGirl::operator+(int score)
// {
//     this->m_score=this->m_score+score;
//     cout<<"The this is "<<this<<endl;
// }

// CGirl& CGirl::operator-(int score)
// {
//     this->m_score = this->m_score-score;
//     return *this;
// }

//TODO: ����ÿ�μ�30����Ԫȫ�ֺ���
void addscore(CGirl& g1,int score)
{
    g1.m_score = g1.m_score+score;
}

// void operator+(CGirl& g1,int score) // operator+  ���Ǻ�����
// {
//     g1.m_score = g1.m_score+score;
// }

CGirl& operator-(CGirl& g1,int score) // operator-  ���Ǻ�����
{
    g1.m_score = g1.m_score-score;
    return g1;
}

CGirl& operator+(CGirl& g1,int score) // operator+  ���Ǻ�����
{
    g1.m_score = g1.m_score+score;
    return g1;
}

CGirl& operator+(int score,CGirl& g1) // operator+  ���Ǻ�����
{
    g1.m_score = g1.m_score+score;
    return g1;
}

CGirl& operator+(CGirl& g1,CGirl& g2)
{
    g1.m_score = g1.m_score+g2.m_score;
    return g1;
}

/*void operator*(int& a,int &b)
{
    a = a*b;
}*/
int main(void)
{
    CGirl g;
    cout<<"The address of g is "<<&g<<endl;
    g+30; //TODO:  ���ʻ��ǵ��ú�����operator+(g,30);ֻ����C++��������Ĵ���������ʵ��д�������+�����ߣ������˺����������ŵĴ�ͳ��д��ʽ

    // addscore(g,30);
    // operator+(g,30);
    g.show();
    // g=g-20-5-10; //TODO: ��������ؿ��������ã������Ǻ����Ķ�ε���
    //TODO�� ��һ�� g-20 ����operator- ,����g���ڶ��Σ�g-5 ����operator- ,����g���ڶ��Σ�g-10 ����operator- ,����g��
    // ����������غ�����,������ʽ���£�
    // g = operator-(operator-(operator-(g,20),5),10);
    // g = 20+5+10+g;  //TODO: ��һ�� 10+g ����operator+ ,����g���ڶ��Σ�5+g ����operator+ ,����g���ڶ��Σ�20+g ����operator+ ,����g��
    g = g+20+5+10+g;  //TODO: ʵ��Ϊ g+g
    g.show();
    return 0;
};