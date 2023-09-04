#include <iostream>
using namespace std;

// delete空指针是可以的，， delete野指针可能会导致程序的奔溃
class AA {
public:
	AA() { cout << "调用了基类的默认构造函数AA()" << endl; }
	virtual void func() { cout << "调用了基类的func()" << endl; }
	virtual ~AA() { cout << "调用了基类的析构函数~AA()" << endl;  }
	//virtual ~AA(){}
};

class BB :public AA {
public:
	BB() { cout << "调用了派生类的默认构造函数BB()" << endl; }
	void func() { cout << "调用了派生类的函数func()" << endl; }
	~BB() { cout<< "调用了派生类的析构函数~BB()" << endl; }
};


int main(void)
{
	AA *b=new BB;
	
	delete b;

	
	return 0;
}