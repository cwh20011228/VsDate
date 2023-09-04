#include <iostream>
using namespace std;

class CGirl
{
public:
	int m_bh;
	char m_name[3];
	static int m_age;

	CGirl();
	~CGirl();
	void ShowName();
	void ShowAge();
};

CGirl::CGirl()
{
	memset(m_name, 0, sizeof(m_name));
	m_age = 0;
}

CGirl::~CGirl()
{

}

void CGirl::ShowAge()
{
	cout << "ÄêÁä£º" << m_age << endl;
}

void CGirl::ShowName()
{
	if (this == nullptr) return;
	cout << "ÐÕÃû£º" << this->m_name << endl;
}

int CGirl::m_age = 20;
int a{ 2 };
void func(){}


int main(void)
{
	CGirl g1;
	cout << "sizeof(g1)= " << sizeof(g1) << endl;
	cout << "&g1.m_bh= " << &g1.m_bh << endl;
	cout << "&g1= " << &g1 << endl;
	cout << "&g1.m_name= " << &g1.m_name << endl;
	cout << "&g1.m_age= " << &g1.m_age << endl;
	cout << "&a= " << &a << endl;


	cout << endl;

	printf("&ShowName= %p\n", &CGirl::ShowName);
	printf("&ShowAge= %p\n", &CGirl::ShowAge);
	printf("&func= %p\n", func);

	CGirl* g2=nullptr;
	g2->ShowName();
	
}