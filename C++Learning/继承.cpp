#include <iostream>         // ����ͷ�ļ���
using namespace std;        // ָ��ȱʡ�������ռ䡣

class CAllComers          // ��ѡ��������
{
public:
    string    m_name;    // ����
    string    m_tel;         // ��ϵ�绰
protected:
    int m_a;
private:
    int m_b;
public:
    // ���캯����
    CAllComers() { m_name = "ĳŮ"; m_tel = "����"; }
    // ����ʱ��Ҫ��һ�׸衣
    void sing() { cout << "����һֻСС��\n"; }
    // ����������
    void setname(const string& name) { m_name = name; m_b = 0;  cout << "m_b= " << m_b << endl; }
    // ���õ绰���롣
    void settel(const string& tel) { m_tel = tel; }
};

class CGirl :protected CAllComers        // ��Ů��
{
public:
    int m_bh;          // ��š�
    CGirl() { m_bh = 8; }
    void show() { 
        setname("��ʩ");
        cout << "��ţ�" << m_bh << "��������" << m_name << "����ϵ�绰��" << m_tel << endl;

        sing();
    }
    using CAllComers::setname;

};

int main()
{
    CGirl g;
    g.setname("jj");

    g.show();
}
