#include <iostream>
using namespace std;

class Student
{
public:
    int &GetAge()
    {
        return m_age;
    }

    const int& GetAgeConst() // ���ص���const ���ε�int&���ͣ������޸ģ�
    {
        return m_age;
    }

    // void SetAgeConst(int age) const{    // !error ,const���εĳ�Ա�����������޸ĳ�Ա������
    //     m_age = age;
    // }

    void SetAge(int age) {
        m_age = age;
    }

    void ShowAge()
    {
        cout<<"Age: "<<m_age<<endl;
    }

private:
    int m_age = 0;
};

int main()
{
    Student stu;
    stu.ShowAge();

    stu.GetAge() = 5;
    stu.ShowAge();

    // stu.GetAgeConst = 8;   // !error
    // stu.ShowAge();

    stu.SetAge(6);
    stu.ShowAge();

    // stu.SetAgeConst(15);    // !error
    // stu.ShowAge();

    return 0;
}