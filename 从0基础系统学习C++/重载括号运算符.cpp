#include <iostream>
using namespace std;

class CGirl
{
public:
    void operator()(string str)
    {
        cout<<"���غ�����"<<str<<endl;
    }
};

void show(string str)
{
    cout<<"��ͨ������"<<str<<endl;
}

// TODO����������������������ഴ���Ķ���Ҳ�к������󣬻��߷º���
int main(void)
{
    show("����");

    CGirl show;
    show("��ʩ");   //TODO: ���԰Ѷ�����������������ʹ�ã�
    show("����");   // show���õ������غ����� ���Ҫ����ȫ�ֺ���,��ʽӦ��Ϊ ::show("����")
    ::show("����"); //show���õ�����ͨ����
    return 0;
}