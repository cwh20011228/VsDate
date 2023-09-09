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
        enum{girl=1,boy=2}; // ����ö��
        // int *m_ptr;


};

CGirl::CGirl()
{
    m_name.clear(); 
    m_age = 0;
    m_sex=1;
    // m_ptr=nullptr;
    cout<<"������CGirl()���캯��."<<endl;
}

CGirl::CGirl(string name)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    cout<<"������CGirl(string name)���캯��."<<endl;
}

CGirl::CGirl(string name,int age)
{
    m_name=name; 
    m_age = 0;
    m_sex=1;
    // cout<<"aaa\n";
    // CGirl(); // �����������default constructor ,������ʼ����ʵ���ϣ�����һ���������󣬵��ú����ϱ�����
    // cout<<"bbb\n";
    cout<<"������CGirl(string name,int age)���캯��."<<endl;

}

CGirl::~CGirl()
{
    // if(m_ptr!=nullptr) delete m_ptr;
    cout<<"������~CGirl()"<<endl;
}

// void CGirl::setvalue(string name,int age,int sex)
// {
//     m_age=age;
//     m_name=name;
//     m_sex=sex;
// }

void CGirl::show()
{
    cout<<"����:"<<m_name<<"  ����:"<<m_age;
    if(m_sex==girl){ cout<<"  Ů��"<<endl;}
    else if(m_sex==boy) cout<<"  �к�"<<endl;
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
    // CGirl *girl = new CGirl;  // new ��������ʱ����constructor
    /*CGirl *girl = new CGirl("Smith",23);
    girl->show();
    delete girl;   // delete ���ٶ���ʱ������destructor
    */
    // CGirl girl = {"Smith",23};
    // CGirl girl{"Smith",23};
    CGirl *girl = new CGirl{"Smith",23};
    delete girl;
    return 0;
}