#include <iostream>
using namespace std;

void func(int bh,string message)
{
    cout<<"�װ���"<<bh<<"�ţ�"<<message<<endl;
}

int main(void)
{
    int bh = 3;
    string messages = "����һֻСС��";
    func(bh,messages);

    void (*pfunc)(int,string); // ������׺����ĺ���ָ��
    pfunc = func;  // �Ժ���ָ�븳ֵ�� �﷨�� ����ָ���� = �����������������Ǻ����ĵ�ַ
    pfunc(bh,messages); // �ú���ָ�������ú�����c++�﷨
    (*func)(bh,messages);  // c����

    return 0;
}