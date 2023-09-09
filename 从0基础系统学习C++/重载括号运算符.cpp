#include <iostream>
using namespace std;

class CGirl
{
public:
    void operator()(string str)
    {
        cout<<"重载函数："<<str<<endl;
    }
};

void show(string str)
{
    cout<<"普通函数："<<str<<endl;
}

// TODO：用重载了括号运算符的类创建的对象也叫函数对象，或者仿函数
int main(void)
{
    show("李四");

    CGirl show;
    show("西施");   //TODO: 可以把对象名当作函数名来使用，
    show("张三");   // show调用的是重载函数， 如果要调用全局函数,形式应该为 ::show("张三")
    ::show("张三"); //show调用的是普通函数
    return 0;
}