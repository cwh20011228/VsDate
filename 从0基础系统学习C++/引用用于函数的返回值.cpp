#include <iostream>
using namespace std;
//TODO: ����ʹ�û���ԭ�򣺱����õı�������������Ҫ�����ó�
int func1() // ���ص���ֵ
{
    int ii=3;
    return ii;
}

// int ii=5;
int& func2() // ���ص�������
{
    static int ii=3;  //��̬�ֲ�������ֻ��ʼ��һ�Σ��ڱ���ʱ��ʼ�����������������������������ֱ��ε�ֵ�����´�ʹ�õ�ʱ�򣬾�ʹ�����ֵ
    // int ii=3;
    return ii;
}

int& func3(int &ra) //���ص�������
{
    ra++;
    cout<<"ra�ĵ�ַ��:"<<&ra<<"  ra="<<ra<<endl;
    return ra;
}

int main(void)
{
    int a=func1(); cout<<"a="<<a<<endl;
    int c=func2(); cout<<"c="<<c<<endl;
    // int a=3;
    // int &b = func3(a);  // ���ص�������
    // cout<<"a�ĵ�ַ��:"<<&a<<"  a="<<a<<endl;
    // cout<<"b�ĵ�ַ��:"<<&b<<"  b="<<b<<endl;

    // func3(a)=10;  //�������õĺ����Ǳ����ñ����ı���
    // cout<<"a�ĵ�ַ��:"<<&a<<"  a="<<a<<endl;
    // cout<<"b�ĵ�ַ��:"<<&b<<"  b="<<b<<endl;
    return 0;
}