#include <iostream>
using namespace std;

int main(void)
{
    // int *array = new int[5]{1,2,3,4,5};
    // cout<<sizeof(array)<<endl;
    // for(int i=0;i<5;i++)
    // {
    //     cout<<"array["<<i<<"]="<<array[i]<<endl;
    // }
    //TODO:  ������ͨ�����ʱ�����鳤�ȿ����ñ���,�൱����ջ�϶�̬��������
    //TODO:����д��������ݣ�Ӧ���ö�������ռ�
    //TODO: new(std::nothrow) ����ڴ治�������ؿյ�ַnullptr ,
    // int b;
    // cin>>b;
    // int num[b]={0};
    // int *array = new int[5];
    // for(int i=0;i<5;i++)
    // {
    //     array[i]=i+100;
    //     cout<<"*(array+"<<i<<")="<<*(array+i)<<endl;
    // }
    // delete[] array;
    // array = nullptr;

    int *a=new(std::nothrow) int[100000000000001];
    
    if(a==nullptr)
        cout<<"�����ڴ�ʧ��.\n";
    else{
        a[100000000000000]=8;
        delete[] a;
    }
    
    return 0;
}