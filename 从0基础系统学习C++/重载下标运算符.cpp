#include <iostream>
using namespace std;

// C++中，字符串本质是封装了字符数组的类，类名是string。字符串的最后一位是空字符
//  下标运算符[]必须用成员函数版本重载

class CGirl
{
private:
    string m_boys[3];
public:
    string m_name;
    void show();
    CGirl();
    ~CGirl();
    // string& Boys(int ii);
    //TODO: 重载下标运算符，
    string& operator[](int ii);                 // first, []不仅可以访问数组元素，还可以修改数组元素
    const string& operator[](int ii) const;     // second ,[]只能访问而不能修改数组元素
    CGirl(const CGirl& g3);     //  copy constructor
};

CGirl::CGirl()
{
    m_boys[0]="子都";
    m_boys[1]="潘安";
    m_boys[2]="宋玉";
    cout<<"The CGirl() constructor was called."<<endl;
}

CGirl::CGirl(const CGirl& g3)
{
    m_boys[0]=g3.m_boys[0];
    m_boys[1]=g3.m_boys[1];
    m_boys[2]=g3.m_boys[2];
    m_name=g3.m_name;
    cout<<"The CGril(const CGirl& g3) copy constructor was called."<<endl;
}

CGirl::~CGirl()
{
    cout<<"The ~CGirl() destructor was called."<<endl;
}

void CGirl::show()
{
    cout<<m_boys[0]<<" , "<<m_boys[1]<<" , "<<m_boys[2]<<endl;
}

// string& CGirl::Boys(int ii)
// {
//     return m_boys[ii];
// }
// 如果Boys返回的是引用的话，可以将函数调用的表达式当作变量来使用。返回的引用就是m_boy[ii]的别名。就可实现   g.Boys(1)="Jack";

string& CGirl::operator[](int ii)
{
    return m_boys[ii];
}

const string& CGirl::operator[](int ii) const
{
    return m_boys[ii];
}


int main(void)
{
/*    string a = "abcd";
    cout<<"a=   "<<a<<endl;
    cout<<"a[0]="<<a[0]<<endl;
    cout<<"a[1]="<<a[1]<<endl;
    cout<<"a[2]="<<a[2]<<endl;
    cout<<"a[3]="<<a[3]<<endl;
    cout<<"a[4]="<<a[4]<<endl;
    cout<<"a[5]="<<a[5]<<endl; // 越界  */
    CGirl g;
    // g.Boys(1)="Jack";
    // cout<<"第一任男朋友："<<g.Boys(1)<<endl;
    g[1]="Jack";
    cout<<"第一任男朋友："<<g[1]<<endl;
    g.show();

    const CGirl g1 = g; //TODO： 常对象只能访问常函数，即 const约束的对象只能访问 const约束的成员函数
    cout<<"第一任男朋友："<<g1[1]<<endl;

    return 0;
}