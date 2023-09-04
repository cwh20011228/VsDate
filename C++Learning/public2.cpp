#include "public2.h"
#include <iostream>
using namespace std;


namespace aa
{
	int ab = 1;

	void func1()
	{
		cout << "调用了aa::func1()函数" << endl;
	}
}

namespace bb 
{
	int ab = 2;

	void func1()
	{
		cout << "调用了bb::func1()函数" << endl;
	}

	void A1::show()
	{
		cout << "调用了bb::A1::show()函数" << endl;
	}

}
