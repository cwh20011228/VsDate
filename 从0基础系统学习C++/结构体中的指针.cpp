#include <iostream>
#include <cstring>
using namespace std;

struct St
{
    int a;
    int *p;
};

struct ss{
    string name;  // string��һ����,������һ��ָ�붯̬����ռ�
};

int main(void)
{   
    int *pointer=nullptr;
    cout<<"ָ��Ĵ�С��"<<sizeof(pointer)<<endl;
    St stt;
    memset(&stt,0,sizeof(stt));
    stt.p=new int[100];
    cout<<"sizeof(stt)="<<sizeof(stt)<<endl;
    cout<<"����ǰ stt.a="<<stt.a<<"  stt.p="<<stt.p<<endl;

    // memset(&stt,0,sizeof(stt));
    stt.a=0;  // ��ճ�Աa
    memset(stt.p,0,sizeof(int)*100); // ���pָ����ڴ��е�����
    cout<<"���ú� stt.a="<<stt.a<<"  stt.p="<<stt.p<<endl;
    //TODO: �ڶ�̬�����ڴ�֮��ʹ��memeset ��0��pָ��ĵ�ַ��Ϊ0 , ����������������ǲ�����ָ�롣ָ��pԭ��ָ����ڴ�û�б��ͷţ������ڴ�й©�����Ľ���Ƕ��е��ڴ�Խ��Խ�٣�ϵͳԽ��Խ��������Ҳ�������
    // ��û�ж�̬�����ڴ�֮ǰ���Ϳ����� memset������սṹ��
    cout<<"--------------------------"<<endl;
    ss st;
    st.name="��ʩ";
    cout<<"st.name="<<st.name<<endl;
    memset(&st,0,sizeof(st));
    st.name="��С��";
    cout<<"st.name="<<st.name<<endl;
    delete [] stt.p;   // �ͷŶ�̬������ڴ�

    return 0;
} 