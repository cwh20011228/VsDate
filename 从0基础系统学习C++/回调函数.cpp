#include <iostream>
using namespace std;
// TODO: �ص���������һ�������Ĵ���Ƕ�뵽��һ������
// ���ص��������ݲ�������
// 1. �ɵ����ߺ����ṩ����
// 2. ��ʵ�δ����洫����

void zs(int a)
{
    cout<<"a="<<a<<"  ��Ҫ�ȷ�������ͷ�ٱ�ס�\n";
}

void ls(int a)
{
    cout<<"a="<<a<<"����һֻСС��\n";
}

void show(void (*pf)(int))
{
    cout<<"���֮ǰ��׼�������Ѿ���ɡ�\n";
    int b=3; //TODO:�ɵ����ߺ����ṩ����
    pf(b);
    cout<<"���֮�����λ��������ɡ�\n";
}

void show(void (*pf)(int),int b) //TODO: ��ʵ�δ����洫����
{
    cout<<"���֮ǰ��׼�������Ѿ���ɡ�\n";
    pf(b);
    cout<<"���֮�����λ��������ɡ�\n";
}

int main(void)
{
    show(zs);
    show(ls,3);
    return 0;
}