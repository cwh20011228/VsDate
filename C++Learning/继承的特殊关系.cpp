//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	int m_a = 0;
//private:
//	int m_b = 0;
//public:
//	void show() { cout << "A::show() m_a=" << m_a << "  m_b=" << m_b << endl; }
//	void setb(int b) { m_b = b; }
//};
//
//class B :public A {
//public:
//	int m_c = 0;
//	void show() { cout << "B::show() m_c=" << m_c << endl; }
//};
//
//
//int main(void)
//{
//	//A a;
//	B b;
//	A &a=b;
//	b.m_a = 10;
//	b.setb(20);
//	b.m_c = 30;
//	a.show();
//	//a = b;	// 派生类对象赋值给基类对象，就会舍弃了非基类的成员变量
//	b.show();
//
//	a.m_a = 21;
//	a.setb(22);
//	a.show();
//	return 0;
//}

#include <iostream>
#include <cstring>
using namespace std;
struct pet
{
	char name[21];
	char type[21];
	/*pet(const char* n, const char* t) {
		strncpy(name, n, sizeof(n)/sizeof(char));
		strncpy(type, t, sizeof(t) / sizeof(char));
	}*/

};

//char* strcpy(char* _Dest,const char* _Source);
//char *strncpy(char* _Dest,const char* _Source,size_t _Count)

struct girl
{
	char name[21];
	int age;
	double weight;
	char sex;
	bool yz;
	struct pet PET;
	/*girl(const char* n, int a, double w, char s, bool y, const char* pn, const char* pt)
		: age(a), weight(w), sex(s), yz(y), PET(pn, pt) {
		strncpy(name, n, sizeof(n) / sizeof(char));
	}*/
};

int main(void)
{
	girl Girl = { "西施",23,50.5,'X',true,{"贝贝","鸭子"} };
	Girl.PET = { "小白","狗" };
	cout << "姓名:" << Girl.name << "的宠物是一只" << Girl.PET.type << endl;
}