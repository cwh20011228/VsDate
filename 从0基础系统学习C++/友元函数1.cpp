#include <iostream>
using namespace std;
// ��CBoy��func1��������ΪCGirl����Ԫ����
// TODO�� (1) CGirl�������ǰ�� (2)CBoy�Ķ������CGril�Ķ���֮ǰ ��3����CBoy�ĳ�Ա�����ĺ��������Ķ������ó��������ڶ���CGirl��ĺ���
// TODO�� (4)��CBoy��ĳ�Ա��������ΪCGirl�����Ԫ����

class CGirl; // TODO�� CGirl���ǰ������
class CBoy
{
public:
    void func1(const CGirl &g);
    void func2(const CGirl &g);
};



class CGirl
{
    friend void CBoy::func1(const CGirl &g);
    // friend void CBoy::func2(const CGirl &g);

public:
    string m_name;
    CGirl();
    ~CGirl();
    void showname();

private:
    int m_xw;
    void showxw() const;
};

CGirl::CGirl()
{
    m_name = "��ʩ";
    m_xw = 87;
    cout << "The CGir() constructor was called." << endl;
}

CGirl::~CGirl()
{
    cout << "The ~CGir() destructor was called." << endl;
}

void CGirl::showname()
{
    cout << "������" << m_name << endl;
}

void CGirl::showxw() const
{
    cout << "��Χ��" << m_xw << endl;
}

// ������ֻ�ܷ���constԼ���ĳ�Ա
void CBoy::func1(const CGirl &g)
{
    cout << "Ů���ѵ�xw�ǣ�" << g.m_xw << endl;
}

void CBoy::func2(const CGirl &g)
{
    cout << "Ů���ѵ������ǣ�" << g.m_name << endl;
}

int main(void)
{
    CGirl g;
    CBoy b;
    b.func1(g);
    b.func2(g);
    return 0;
}