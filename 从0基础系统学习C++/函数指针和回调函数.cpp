#include <iostream>
using namespace std;

void func(int no,string str);
int main(void)
{
    //TODO: ���������Ǻ����ĵ�ַ
    int bh = 3;
    string message = "����һֻɵɵ��";

    func(bh,message);

    void (*pfunc)(int,string); //TODO: ����һ������ָ�룬����ָ�����Ĳ���Ҫ�뺯���Ĳ���һ��
    pfunc = func; // TODO: �Ժ���ָ�븳ֵ��c++�У�����ָ���� = ������
    pfunc(bh,message); // TODO�� �ú���ָ�������ú�����C++
    (*func)(bh,message); //TODO: C�����У��ú���ָ�������ú���
    return 0;
}

void func(int no,string str)
{
    cout<<"�װ���"<<no<<"�ţ�"<<str<<endl;
}