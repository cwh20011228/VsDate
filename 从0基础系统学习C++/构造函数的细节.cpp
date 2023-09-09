#include <iostream>
#include <cstring>
using namespace std;

class CGirl{
    public:
        void show();
        void setvalue(string name,int age,int sex);
        CGirl();
        CGirl(string name);
        CGirl(string name,int age);
        ~CGirl();
        string m_name;
    private:
        int m_age=38;
        int m_sex;  // 1-girl ,2-boy
        enum{girl=1,boy=2}; // 匿名枚举
        // int *m_ptr;


};

CGirl::CGirl()
{
    m_name.clear(); 
    m_age = 0;
    m_sex=1;
    // m_ptr=nullptr;
    cout<<"调用了CGirl()构造函数."<<endl;
}

CGirl::CGirl(string name)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    cout<<"调用了CGirl(string name)构造函数."<<endl;
}

CGirl::CGirl(string name,int age)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    // cout<<"aaa\n";
    // CGirl(); // 这里想调用了default constructor ,用来初始化。实际上，这是一个匿名对象，调用后，马上被销毁
    // cout<<"bbb\n";
    cout<<"调用了CGirl(string name,int age)构造函数."<<endl;

}

CGirl::~CGirl()
{
    // if(m_ptr!=nullptr) delete m_ptr;
    cout<<"调用了~CGirl()"<<endl;
}

// void CGirl::setvalue(string name,int age,int sex)
// {
//     m_age=age;
//     m_name=name;
//     m_sex=sex;
// }

void CGirl::show()
{
    cout<<"姓名:"<<m_name<<"  年龄:"<<m_age;
    if(m_sex==girl){ cout<<"  女孩"<<endl;}
    else if(m_sex==boy) cout<<"  男孩"<<endl;
}




int main(void)
{
    // CGirl girl = CGirl("Smith",23);
    /*CGirl girl;
    girl = CGirl("Smith",23);*/
    // CGirl girl("Smith",23);
    // CGirl girl;
    // girl.show();
    // girl.~CGirl();
    // CGirl *girl = new CGirl;  // new 创建对象时调用constructor
    /*CGirl *girl = new CGirl("Smith",23);
    girl->show();
    delete girl;   // delete 销毁对象时，调用destructor
    */
    // CGirl girl = {"Smith",23};
    // CGirl girl{"Smith",23};
    CGirl *girl = new CGirl{"Smith",23};
    delete girl;
    return 0;
}