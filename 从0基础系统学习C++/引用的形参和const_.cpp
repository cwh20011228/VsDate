#include <iostream>
using namespace std;


void func1(const int no,const string str) //��ֵ
{
    cout<<"�װ���"<<no<<"��:"<<str<<endl;
}

void func2(const int *no,const string *str) //��ָ��
{
    
    cout<<"�װ���"<<*no<<"��:"<<*str<<endl;
}

void func3(const int &no,const string &str) //������
{
    
    cout<<"�װ���"<<no<<"��:"<<str<<endl;
}

int main(void)
{
    const int &bh = 3;  //TODO: const int &rh=3;   �൱��   int tmp =3;  const int &rh = tmp; 
    string message = "����һֻɵɵ��.";
    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int' (int &bh = 3;)
    //TODO:  can bind const lvalue reference of type 'const int &' to an rvalue of type 'int'
    //TODO: �������Ϊconst ,C++�ᴴ����ʱ������������ָ����ʱ�����������Ϊconst,�Ͳ��ᴴ����ʱ����
    func1(3,"����һֻɵɵ��.");
    func2(&bh,&message);
    func3('X',"����һֻɵɵ��.");
    func3(bh,message);
    cout<<"�װ���"<<bh<<"��:"<<message<<endl;

    return 0;
}