#include <iostream>
using namespace std;
//TODO: ���õı�����ָ�볣�� ��  ���� * const ָ����  (eg: int *const rb=&a;), ָ������ʼ��
// C++��ô��ָ�볣��αװΪ���ã��Ա�������˵�����ַ������滻�� int &ra=a;  int &�滻Ϊ int * const ,  a �滻Ϊ &a
int main(void)
{
    int a=3;
    int &ra =a;             // ra��a�ı����� ���ñ����ڴ�����ʱ��ͳ�ʼ���� �����Ѵ���ÿ�������ı���
    int * const rb=&a;      // ����ָ�볣��rb,����ָ��a
    cout<<" a�ĵ�ַ��:  "<<&a<<",  a��ֵ��:  "<<a<<endl;
    cout<<"ra�ĵ�ַ��:  "<<&a<<", ra��ֵ��:  "<<ra<<endl;
    cout<<"rb�ĵ�ַ��:  "<<rb<<", rb��ֵ��:  "<<*rb<<endl;

    int b = 5;

    ra = 5;
    cout<<" b�ĵ�ַ��:  "<<&b<<",  b��ֵ��:  "<<b<<endl;
    cout<<" a�ĵ�ַ��:  "<<&a<<",  a��ֵ��:  "<<a<<endl;
    cout<<"ra�ĵ�ַ��:  "<<&a<<", ra��ֵ��:  "<<ra<<endl;
    cout<<"rb�ĵ�ַ��:  "<<rb<<", rb��ֵ��:  "<<*rb<<endl;
}