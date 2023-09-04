#include <iostream>
using namespace std;

int main(void)
{
	char cc[8];		// 在栈上分配8字节的内存空间

	// 把cc的内存空间用于字符串
	strcpy(cc, "hello");
	cout << "cc=" << cc << endl << endl;

	// 把cc的内存空间用于int整型
	int* a, * b;
	a = (int*)cc;	// 前四个字节用于整数a
	b = (int*)cc + 4;	// 后四个字节用于整数b
	*a = 12345;
	*b = 54321;
	cout << "*a=" << *a << endl << "*b=" << *b << endl << endl;;


	//把cc的内存空间用于double
	double* c;
	c = (double*)cc;
	*c = 12345.6;
	cout << "*c=" << *c << endl << endl;

	// 把cc的内存空间用于结构体
	struct stt {
		int a;
		char b[4];
	}* st;
	st = (stt*)cc;
	st->a = 38;
	strcpy(st->b, "abc");
	cout << "st->a= " << st->a << endl << "st->b= " << st->b << endl << endl;


	// void* malloc(size_t size);
	char* cc1 = (char*)malloc(8);
	return 0;
}