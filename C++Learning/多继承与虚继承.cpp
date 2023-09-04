#include <iostream>
using namespace std;

//class A1 {
//public:
//	int m_a = 10;
//};
//
//class A2 {
//public:
//	int m_a = 20;
//};
//
//class B :public A1, public A2 {
//public:
//	int m_a=30;
//};
//
//
//int main(void)
//{
//	B b;
//	cout << "m_a=" << b.m_a << endl;
//	cout << "A1::m_a=" << b.A1::m_a << endl;
//	cout << "A2::m_a=" << b.A2::m_a << endl;
//
//	return 0;
//}

class A {
public:
	int m_a = 10;
};
// A类被虚继承后，就成了虚基类
// vbptr虚基类指针指向虚基类表，vbtable   虚基类表存放了成员的相对位置
class B :virtual public A {

};

class C :virtual public A {

};

class D :public B, public C{

};

int main(void)
{
	D d;
	d.m_a = 80;
	d.B::m_a = 20;
	d.C::m_a = 30;
	cout << "B::&m_a= " << &d.B::m_a <<"  B::m_a= "<<d.B::m_a << "\nC::&m_a= " << &d.C::m_a<<"  C::m_a= " << d.C::m_a  << endl;
}