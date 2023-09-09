#include <iostream>
#include <cstring>
using namespace std;

class CGirl{
    public:
        string m_name;
        int m_age;
        int *m_ptr;
    CGirl();
    CGirl(string name,int age);
    // CGirl(string name,int age,int *ptr);
    CGirl(const CGirl& g0); // Ĭ�ϵĿ������캯��
    CGirl(const CGirl& g0,int ii);
    ~CGirl();
    void show();
};

CGirl::CGirl()
{
    m_name.clear();
    m_age=0;
    m_ptr=nullptr;
    cout<<"The CGirl() constructor was called."<<endl;
}

CGirl::CGirl(string name,int age)
{
    m_name=name;
    m_age=age;
    m_ptr=nullptr;
    cout<<"The CGirl(string name,int age) constructor was called."<<endl;
}

CGirl::CGirl(const CGirl& g0)
{
    m_name = g0.m_name;
    m_age=g0.m_age;
    m_ptr=new int; // �����ڴ�
    *m_ptr = *g0.m_ptr; // ��������
    //TODO�� memcpy(m_ptr,g0.m_ptr,sizeof(int));  ����һ�����memcpy
    cout<<"The CGirl(const CGirl&) Copy constructor was called"<<endl;
}

CGirl::CGirl(const CGirl& g0,int ii)
{
    m_name = g0.m_name;
    m_age=g0.m_age;
    m_ptr=g0.m_ptr;
    cout<<"The CGirl(const CGirl&,int ii) Copy constructor was called"<<endl;
}
CGirl::~CGirl()
{
    if(m_ptr!=nullptr)
    {
        delete m_ptr;
        m_ptr=nullptr;
    }
    cout<<"The ~CGirl() destructor was called."<<endl;
}

void CGirl::show()
{
    cout<<"name="<<m_name<<"  age="<<m_age<<"  m_ptr="<<m_ptr<<"  *m_ptr="<<*m_ptr<<endl;
}
/* 
TODO:   �Կ�ָ������� *p   (p=nullptr)  �ǷǷ���
ǳ��������˳���ı���������������ݵĻ��ң����е�ָ��ָ��ͬһ��������
TODO: �����ָ��Aָ��һ���ڴ棬��ô�����·���һ����ͬ��С���ڴ棬��ָ��Bָ�����ڴ棬Ȼ���ٰ�ָ��Aָ����ڴ��е����ݿ��������ڴ��С����ֿ����ķ����ܳ��ף��ڿ����󣬴�Ҹ��Բ����Լ���ָ����ڴ�
�������ṩ�Ŀ������캯����ǳ����
������������裺1.�����ڴ�   2. ��������
*/
int main(void)
{
    CGirl g1("Smith",25);
    g1.m_ptr= new int(3); // ֻ��һ���������ٳɹ���g2��,g1���ٵ�ʱ��m_ptr��Ϊ��Ұָ�룬���������ֻ������һ��destructor
    g1.show(); 
    CGirl g2(g1);
    *g2.m_ptr=8;
    g1.show();
    g2.show();
    return 0;
}