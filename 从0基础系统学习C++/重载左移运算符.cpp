#include <iostream>
using namespace std;

class CGirl
{
    friend ostream &operator<<(std::ostream &cout, const CGirl &g1);

private:
    string m_name;
    int m_xw;
    int m_score;

public:
    CGirl();
    ~CGirl();
    void show() const;
};

CGirl::CGirl()
{
    m_name = "��ʩ";
    m_score = 30;
    m_xw = 87;
    cout << "The CGirl() constructor was called." << endl;
}

CGirl::~CGirl()
{
    cout << "The ~CGirl() destructor was called." << endl;
}

void CGirl::show() const
{
    cout << "������" << m_name << "����Χ��" << m_xw << "�����֣�" << m_score << endl;
    // TODO: ����һ��ʵ���Ƕ�ε��������غ�������һ�ε��õ�ʱ�򣬲�����cout����� "������" ���������"����"�󣬷���cout����
    // TODO���ڶ��ε��õ���󣬺���������ʵ���� cout����� m_name ,��� m_name�󣬷���ֵ��cout����
}

ostream &operator<<(std::ostream &cout, const CGirl &g1)
{
    // g1.show();
    cout << "������" << g1.m_name << "����Χ��" << g1.m_xw << "�����֣�" << g1.m_score << endl;
    return cout; //TODO: ����ֵ������ostream�Ķ���
}

int main(void)
{
    CGirl g;
    cout << g ;
    return 0;
}