#include <iostream>
using namespace  std;

void func(int* no,string *str);
void func1(int a,int b,int c,int* min,int* max);

int main(void)
{
    int bh = 3;
    string message = "����һֻɵɵ��";
    func(&bh,&message);
    cout<<"�װ���"<<bh<<"�ţ�"<<message<<endl;
    int a=180,b=175,c=170,m,n;
    func1(a,c,b,&m,&n);
    cout<<"MAX="<<m<<"\n"<<"MIN="<<n<<endl;
    return 0;
}

void func(int *no,string *str)
{
    cout<<"�װ���"<<*no<<"�ţ�"<<*str<<endl;
    *no = 8;
    *str = "����һֻСС��";
}

void func1(int a,int b,int c,int* min,int* max)
{
    *max = (a>b) ? ((a>c)?a:c) :((b>c)?b:c);
    *min  = (a<b) ? ((a<c)?a:c): ((b<c)?b:c);
}