#include <iostream>
using namespace std;

int main(void)
{
    string str = "��ʩ";
    str = "��Ů��ʩ";
    cout<<"str ="<< str<<endl;
    cout<<"�����볬Ů���֣�";
    cin>>str;
    if(str=="����") cout<<"��ϲ��\n";
    if(str != "����") cout<<"�Ҳ�����\n";
    str = "������"+str+",�����ҵ���Ů��";
    cout<<str<<endl;
    //TODO: ��������ַ������ǳ��� �������� + 
    string str1 = "��Ů������" "����" "�������ҵ�ǰŮ��";
    cout<<str1<<endl;
    return 0;
}