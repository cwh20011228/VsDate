#include <iostream>
using namespace std;


void func1(const int no,const string str) //传值
{
    cout<<"亲爱的"<<no<<"号:"<<str<<endl;
}

void func2(const int *no,const string *str) //传指针
{
    
    cout<<"亲爱的"<<*no<<"号:"<<*str<<endl;
}

void func3(const int &no,const string &str) //传引用
{
    
    cout<<"亲爱的"<<no<<"号:"<<str<<endl;
}

int main(void)
{
    const int &bh = 3;  //TODO: const int &rh=3;   相当于   int tmp =3;  const int &rh = tmp; 
    string message = "我是一只傻傻鸟.";
    //error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int' (int &bh = 3;)
    //TODO:  can bind const lvalue reference of type 'const int &' to an rvalue of type 'int'
    //TODO: 如果引用为const ,C++会创建临时变量，让引用指向临时变量。如果不为const,就不会创建临时变量
    func1(3,"我是一只傻傻鸟.");
    func2(&bh,&message);
    func3('X',"我是一只傻傻鸟.");
    func3(bh,message);
    cout<<"亲爱的"<<bh<<"号:"<<message<<endl;

    return 0;
}