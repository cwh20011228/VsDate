#include <iostream>
using namespace std;


int* func()
{
	int a = 3;
	cout << "&a=" << &a << " a=" << a << endl;
	return &a;
}

int main()
{
	/*int* p =new int{3};*/
	int* p = func();
	cout << "p=" << p << " *p=" << *p << endl;
	/*delete p;
	cout << "p=" << p << " *p=" << *p << endl;*/
}