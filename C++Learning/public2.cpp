#include "public2.h"
#include <iostream>
using namespace std;


namespace aa
{
	int ab = 1;

	void func1()
	{
		cout << "������aa::func1()����" << endl;
	}
}

namespace bb 
{
	int ab = 2;

	void func1()
	{
		cout << "������bb::func1()����" << endl;
	}

	void A1::show()
	{
		cout << "������bb::A1::show()����" << endl;
	}

}
