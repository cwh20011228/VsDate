#include <iostream>
using namespace std;

class CGirl
{
public:
    int m_bh;
    string m_name;
    int *m_ptr; // ׼��ʹ�öѿռ�
    void show();
    CGirl();
    ~CGirl();
    CGirl &operator=(const CGirl &g0);
};

CGirl::CGirl()
{
    m_ptr = nullptr;
    cout << "The CGirl() constructor was called." << endl;
}

CGirl::~CGirl()
{
    if (m_ptr)
        delete m_ptr;
    cout << "The ~CGirl() destructor was called." << endl;
}

void CGirl::show()
{
    // ���m_ptr=nullptr , ��ô *m_ptr�����
    cout << "bh=" << m_bh << "   name=" << m_name << /*"  *m_ptr=" << *m_ptr << */"  m_ptr=" << m_ptr << endl;
}

//TODO: ���
// ���ظ�ֵ�����,����ֵ��CGirl& ��Ŀ���� ������������ �� g1=g2=g3=g4;
CGirl &CGirl::operator=(const CGirl &g0)
{
    //TODO�� g0��Դ����*this��Ŀ�����   g1=g0;   Դ����g0    Ŀ�����g1
    if (this != &g0)
    {
        if (g0.m_ptr == nullptr) // ���Դ�����ָ��Ϊ�գ������Ŀ�������ڴ��ָ��
        {
            if (this->m_ptr != nullptr)
            {
                delete this->m_ptr;
                this->m_ptr = nullptr;
            }
        }
        else // ���Դ�����ָ�벻Ϊ��
        {
            // ���Ŀ������ָ��Ϊ�ա��ȷ����ڴ�
            if (this->m_ptr == nullptr)
                this->m_ptr = new int;
            //  Ȼ�󣬰�Դ�����ڴ��е����ݸ��Ƶ�Ŀ�������ڴ���
            memcpy(this->m_ptr, g0.m_ptr, sizeof(int));
        }
        this->m_bh = g0.m_bh;
        this->m_name = g0.m_name;
        cout << "The operator=(const CGirl& g0) overload function was called." << endl;
        return *this;
    }
    return *this;
}

int main(void)
{
    CGirl g1, g2;
    g1.m_bh = 8;
    g1.m_name = "��ʩ";
    g1.m_ptr=new int(3);
    g1.show();
    g2.show();

    g2=g1;
    g2.show();
    cout<<"*g1.m_ptr="<<*g1.m_ptr<<"   *g2.m_ptr="<<*g2.m_ptr<<endl;
    return 0;
}