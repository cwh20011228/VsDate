#include <iostream>
using namespace std;

// C++�У��ַ��������Ƿ�װ���ַ�������࣬������string���ַ��������һλ�ǿ��ַ�
//  �±������[]�����ó�Ա�����汾����

class CGirl
{
private:
    string m_boys[3];
public:
    string m_name;
    void show();
    CGirl();
    ~CGirl();
    // string& Boys(int ii);
    //TODO: �����±��������
    string& operator[](int ii);                 // first, []�������Է�������Ԫ�أ��������޸�����Ԫ��
    const string& operator[](int ii) const;     // second ,[]ֻ�ܷ��ʶ������޸�����Ԫ��
    CGirl(const CGirl& g3);     //  copy constructor
};

CGirl::CGirl()
{
    m_boys[0]="�Ӷ�";
    m_boys[1]="�˰�";
    m_boys[2]="����";
    cout<<"The CGirl() constructor was called."<<endl;
}

CGirl::CGirl(const CGirl& g3)
{
    m_boys[0]=g3.m_boys[0];
    m_boys[1]=g3.m_boys[1];
    m_boys[2]=g3.m_boys[2];
    m_name=g3.m_name;
    cout<<"The CGril(const CGirl& g3) copy constructor was called."<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}

void CGirl::show()
{
    cout<<m_boys[0]<<" , "<<m_boys[1]<<" , "<<m_boys[2]<<endl;
}

// string& CGirl::Boys(int ii)
// {
//     return m_boys[ii];
// }
// ���Boys���ص������õĻ������Խ��������õı��ʽ����������ʹ�á����ص����þ���m_boy[ii]�ı������Ϳ�ʵ��   g.Boys(1)="Jack";

string& CGirl::operator[](int ii)
{
    return m_boys[ii];
}

const string& CGirl::operator[](int ii) const
{
    return m_boys[ii];
}


int main(void)
{
/*    string a = "abcd";
    cout<<"a=   "<<a<<endl;
    cout<<"a[0]="<<a[0]<<endl;
    cout<<"a[1]="<<a[1]<<endl;
    cout<<"a[2]="<<a[2]<<endl;
    cout<<"a[3]="<<a[3]<<endl;
    cout<<"a[4]="<<a[4]<<endl;
    cout<<"a[5]="<<a[5]<<endl; // Խ��  */
    CGirl g;
    // g.Boys(1)="Jack";
    // cout<<"��һ�������ѣ�"<<g.Boys(1)<<endl;
    g[1]="Jack";
    cout<<"��һ�������ѣ�"<<g[1]<<endl;
    g.show();

    const CGirl g1 = g; //TODO�� ������ֻ�ܷ��ʳ��������� constԼ���Ķ���ֻ�ܷ��� constԼ���ĳ�Ա����
    cout<<"��һ�������ѣ�"<<g1[1]<<endl;

    return 0;
}