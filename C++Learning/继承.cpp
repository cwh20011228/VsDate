#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

class CAllComers          // 海选报名者类
{
public:
    string    m_name;    // 姓名
    string    m_tel;         // 联系电话
protected:
    int m_a;
private:
    int m_b;
public:
    // 构造函数。
    CAllComers() { m_name = "某女"; m_tel = "不详"; }
    // 报名时需要唱一首歌。
    void sing() { cout << "我是一只小小鸟。\n"; }
    // 设置姓名。
    void setname(const string& name) { m_name = name; m_b = 0;  cout << "m_b= " << m_b << endl; }
    // 设置电话号码。
    void settel(const string& tel) { m_tel = tel; }
};

class CGirl :protected CAllComers        // 超女类
{
public:
    int m_bh;          // 编号。
    CGirl() { m_bh = 8; }
    void show() { 
        setname("西施");
        cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系电话：" << m_tel << endl;

        sing();
    }
    using CAllComers::setname;

};

int main()
{
    CGirl g;
    g.setname("jj");

    g.show();
}
