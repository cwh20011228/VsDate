#include "CGirl.h"

int main(void)
{
	CGirl girl;
	girl.SetValue("Smith", 28, 2);
	//CGirl girl("Smith",28);
	girl.show();
	//girl.~CGirl();
	return 0;
}
