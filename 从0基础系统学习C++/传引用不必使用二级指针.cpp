#include <iostream>
using namespace std;

void func1(int **p)  // ����ַ��ʵ��ʵָ��ĵ�ַ���β��Ƕ���ָ��
{
    *p = new int(3); // p �Ƕ���ָ�룬���ָ��ĵ�ַ
    cout<<"func1�ڴ�ĵ�ַ:"<<*p<<"   �ڴ��е�ֵ:"<<**p<<endl;
}

void func2(int *&p)  // �����ã�ʵ����ָ�룬�β���ָ��ı���
{
    p = new int(3);  // p��ָ��ı���
    cout<<"func2�ڴ�ĵ�ַ:"<<p<<"   �ڴ��е�ֵ:"<<*p<<endl;
}


int main(void)
{
    int *p = nullptr;  // ������Ӻ����ж�̬�����ڴ�ĵ�ַ

    // func1(&p);
    func2(p);
    cout<<"main �ڴ�ĵ�ַ:"<<p<<"   �ڴ��е�ֵ:"<<*p<<endl;
    return 0;
}