#include <iostream>
using namespace std;

int main(void)
{
	char cc[8];		// ��ջ�Ϸ���8�ֽڵ��ڴ�ռ�

	// ��cc���ڴ�ռ������ַ���
	strcpy(cc, "hello");
	cout << "cc=" << cc << endl << endl;

	// ��cc���ڴ�ռ�����int����
	int* a, * b;
	a = (int*)cc;	// ǰ�ĸ��ֽ���������a
	b = (int*)cc + 4;	// ���ĸ��ֽ���������b
	*a = 12345;
	*b = 54321;
	cout << "*a=" << *a << endl << "*b=" << *b << endl << endl;;


	//��cc���ڴ�ռ�����double
	double* c;
	c = (double*)cc;
	*c = 12345.6;
	cout << "*c=" << *c << endl << endl;

	// ��cc���ڴ�ռ����ڽṹ��
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