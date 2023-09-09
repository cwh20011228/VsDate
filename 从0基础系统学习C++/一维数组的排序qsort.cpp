#include <iostream>
using namespace std;

int compasc(const void *p1, const void *p2)
{
    // if(*((int*)p1) <  *((int*)p2)) return -1;
    // if(*((int*)p1) == *((int*)p2)) return  0;
    // if(*((int*)p1) >  *((int*)p2)) return  1;
    return *((int*)p1) - *((int*)p2);  // �Ż�
}
/*  qsort() c++�ĺ��������ڶԸ����������͵������������
    ԭ�ͣ� void qsort(void *base,size_t nmemb,size_t size,int (*compar)(const void *,const void *));
    base: �������ʼ��ַ
    nmemb�� ����Ԫ�صĸ��������鳤�ȣ�
    size�� ����Ԫ�صĴ�С sizeof(�������������)
    compar: �ص������ĵ�ַ
*/

int compdesc(const void *p1, const void *p2)
{
    return  *((int*)p2)-*((int*)p1);
}

int main(void)
{
    int a[8] = {4,2,7,5,8,6,1,3};

    qsort(a,sizeof(a)/sizeof(int),sizeof(int),compasc); // ������a����

    for(int i=0;i<8;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    cout<<endl;
    qsort(a,sizeof(a)/sizeof(int),sizeof(int),compdesc); // ������a����

    for(int i=0;i<8;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
    return 0;
}