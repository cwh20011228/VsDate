#include <iostream>
using namespace std;

//! const_cast���Զ���ָ������õ�const��volitale����


void func(int* ptr)
{

}

int main(int argc,char* argv[])
{
	const int* aa=nullptr;
	int* bb=(int*)aa;		// c���ǿ��ת��������const�޶���
	int* cc = const_cast<int*>(aa); // c++���ǿ��ת��������const�޶���
	

	func(const_cast<int*>(aa));
	return 0;

}