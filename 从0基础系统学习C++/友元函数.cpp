#include <iostream>
using namespace std;

class CGirl
{
    // friend class CBoy;
    friend void func();
    friend int main();
    //TODO�� ��main()��������ΪCGirl�����Ԫ����,������Ԫ�Ĵ���������ʲô�ط������ԣ�����public��private�ؼ��ֵ�Լ����һ�����������
    // ��mian�����оͿ��Է���CGirl��˽�г�Ա
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

void func()
{
    CGirl g;
    g.showname();
    g.showxw();
}

// class CBoy
// {
// public:
//     void func1(const CGirl &g);
// };

// ������ֻ�ܷ���constԼ���ĳ�Ա
// void CBoy::func1(const CGirl &g)
// {
//     cout << "Ů���ѵ������ǣ�" << g.m_name << endl;
//     cout << "Ů���ѵ�xw�ǣ�" << g.m_xw << endl;
//     g.showxw();
// }

// ��Ԫ��Ա���������Է�����һ��������г�Ա��ע�������Ͷ����˳��
int main(void)
{
    func();
    CGirl g;
    g.showname();
    g.showxw();

    // CGirl g;
    // CBoy b;
    // b.func1(g);

    return 0;
}