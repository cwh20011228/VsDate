#include <iostream>
using namespace std;
// ����������У�operator new  �� operator delete  ��ȫ�ֺ��������ӹ�ȫ��new��delete�����ڴ�Ĺ�����
void* operator new(size_t size)  // ����������size_t,����ֵ������void*  ,   size_t    -->   unsigned long long
{
    cout<<"������ȫ�����ص�new:"<<size<<"�ֽڡ�\n";
    void *ptr = malloc(size); // �����ڴ�   ��ptr��ָ������ڴ����ʼ��ַ���������ʧ�ܣ�����null
    cout<<"���뵽���ڴ����ʼ��ַ�ǣ�"<<ptr<<endl;
    return ptr;  // ���ط��������ڴ����ʼ��ַ����Ϊͨ�������ַ�����ҵ�����ڴ棬���Է���ֵ������  void*
}


void operator delete(void* ptr) //  ����������void*������ֵ������ void
{
    cout<<"������ȫ�����ص�delete.\n";
    if(ptr==nullptr)  return ;  // �Կ�ָ��delete�ǰ�ȫ��
    free(ptr);  // �ͷ��ڴ�
}

//TODO�� ���Ϊ������new��delete���������õķ�Χ�����࣬������ȫ��
class CGirl 
{
public:
    int m_bh;
    int m_xw;
    CGirl(int bh,int xw);
    ~CGirl();
    void* operator new(size_t size);
    void operator delete(void* ptr);
};

CGirl::CGirl(int bh,int xw):m_bh(bh),m_xw(xw)
{
    cout<<"The CGirl(int ,int ) constructor was called."<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}
//TODO: Ϊ�ഴ��������new��delete,Ĭ����staic ��Ա������ֻ�ܵ���static��Ա 
void* CGirl::operator new(size_t size)  // ����������size_t,����ֵ������void*  ,   size_t    -->   unsigned long long
{
    cout<<"������������ص�new:"<<size<<"�ֽڡ�\n";
    void *ptr = malloc(size); // �����ڴ�   ��ptr��ָ������ڴ����ʼ��ַ���������ʧ�ܣ�����null
    cout<<"���뵽���ڴ����ʼ��ַ�ǣ�"<<ptr<<endl;
    return ptr;  // ���ط��������ڴ����ʼ��ַ����Ϊͨ�������ַ�����ҵ�����ڴ棬���Է���ֵ������  void*
}


void CGirl::operator delete(void* ptr) //  ����������void*������ֵ������ void
{
    cout<<"������������ص�delete.\n";
    if(ptr==nullptr)  return ;  // �Կ�ָ��delete�ǰ�ȫ��
    free(ptr);  // �ͷ��ڴ�
}


int main(void)
{
    int *p1 = new int(3); // ��������ָ��p1 ,ָ����new������ڴ� ,�ڴ��е�ֵ��3
    cout<<"p1="<<(void*)p1<<"  *p1="<<*p1<<endl;
    delete p1;

    cout<<endl;

    CGirl* g=new CGirl(25,36);
    cout<<"The address of g is "<<g<<"     m_bh="<<g->m_bh<<"     m_xw="<<g->m_xw<<endl; 
    delete g;
    return 0;

    // int *l  = new int[5];
    // delete[] l;
}