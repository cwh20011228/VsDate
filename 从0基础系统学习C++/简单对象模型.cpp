#include <iostream>
#include <cstring>
using namespace std;
//TODO�� �ڳ���Գ������C++������һ�����壬���ǣ�����ĸ��ֳ�Ա�����ͳ�Ա����ʵ�����Ƿ�ɢ���ڴ�ģ�����,��C++�ڲ����϶�����˳�Ա�ĵ�ַ��Ϣ���Ǿ��Ƕ����ָ���
//TODO: ��̬��Ա�����࣬������������ֻ��һ�ݣ��������ڶ���Ĵ�С��
class CGirl
{  
public:
    static char m_name[3];
    // char m_name[3];
    int m_age;
    int m_bh;
    CGirl();
    void showname();
    void showage();
    ~CGirl();
};
// ��ĳ�Ա�����Ƿֿ��洢�ģ�������ڴ������Ĵ�����У������Ƿ񴴽��˶��󣬶���ռ�ô洢�ռ䡣���ܴ����˶��ٶ������ڴ���ֻ��һ��������Ҳ�������ڶ����С֮��

char CGirl::m_name[3] = {0}; // ��̬��Ա����������ȫ������ʼ���������ڴ��������ʱ���ʼ��

CGirl::CGirl()
{
    memset(m_name,0,sizeof(m_name));
    m_age=0;
    m_bh=0;
    cout<<"The CGir() constructor was called."<<endl;
}

void CGirl::showage()
{
    cout<<"���䣺"<<m_age<<endl;
}

void CGirl::showname()
{
    cout<<"������"<<m_name<<endl;

}

CGirl::~CGirl()
{
    cout<<"The ~CGir() destructor was called."<<endl;
}

class A{};
int aaa; 
void func() {}

int main(void)
{
    CGirl g;
    cout<<"����gռ�õ��ڴ��С�ǣ�"<<sizeof(g)<<endl;
//TODO��  �Ǿ�̬��Ա�����ĵ�ַ�������ġ���̬��Ա������ȫ�ֱ����ĵ�ַ����һ��������
//TODO:  ����ĵ�ַ�ǵ�һ���Ǿ�̬��Ա�����ĵ�ַ 
    cout<<"����g�ĵ�ַ�ǣ�          "<<&g<<endl;
    cout<<"��Ա����m_name�ĵ�ַ�ǣ� "<<&g.m_name<<endl;
    cout<<"����aaa�ĵ�ַ�ǣ�        "<<&aaa<<endl;
    cout<<"��Ա����m_age�ĵ�ַ�ǣ�  "<<&g.m_age<<endl;
    cout<<"��Ա����m_bh�ĵ�ַ�ǣ�   "<<&g.m_bh<<endl;

// ��Ա�����ĵ�ַ�ͳ�Ա�����ĵ�ַ����һ��
// ��ĳ�Ա�����ĵ�ַ����ͨ�����ĵ�ַ����һ���
    printf("��Ա����showname()�ĵ�ַ�ǣ�%p\n",&CGirl::showname);
    printf("��Ա����showage()�ĵ�ַ�ǣ� %p\n",&CGirl::showage);
    printf("��ͨ����func()�ĵ�ַ�ǣ�    %p\n",&func);
    // A a;
    // cout<<"����aռ�õ��ڴ��С�ǣ�"<<sizeof(a)<<endl;

    CGirl *g1 = nullptr;
    g1->showname();
    return 0;
}