#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    void show();
    // CGirl();
    // ~CGirl();
    CGirl &operator=(const CGirl &g0);
};

// CGirl::CGirl()
// {
//     cout<<"The CGirl() constructor was called."<<endl;
// }

// CGirl::~CGirl()
// {
//     cout<<"The ~CGirl() destructor was called."<<endl;
// }

void CGirl::show()
{
    cout << "bh=" << m_bh << "   name=" << m_name << endl;
}

// ���ظ�ֵ�����,����ֵ��CGirl& ��Ŀ���� ������������ �� g1=g2=g3=g4;
CGirl &CGirl::operator=(const CGirl &g0)
{   // ���صĸ�ֵ������ͱ������ṩ��Ĭ�ϸ�ֵ������һ���� 
    if (this != &g0)
    {
        this->m_bh = g0.m_bh;
        this->m_name = g0.m_name;
        cout << "The operator=(const CGirl& g0) overload function was called." << endl;
        return *this;
    }
    return *this;
}

int main(void)
{
    CGirl g1, g2,g3;
    g1.m_bh = 8;
    g1.m_name = "��ʩ";
    g1.show();
    g2.show();
    // TODO: ��ֵ����У��������������ͬ����û��Ҫִ�к����ˣ� g1=g1 , ����Ӧ���ں������ж� = �����ǲ���ͬһ������
    g2 =g3= g1; // TODO:(����ĸ�ֵ�Ƕ�Զ�Ĺ�ϵ����Ҳ��һһ��Ӧ)�൱�ڣ� g2.m_bh = g1.m_bh;   g2.m_name = g1.m_name;
    // first, g3 = g1 ; ����ֵ��g3;
    // second,  g2= g3;  ����ֵ��g2;
    g2.show();
    g3.show();
    g1=g1;
    return 0;
}