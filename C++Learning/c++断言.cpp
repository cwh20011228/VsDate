#include <iostream>
#include <cassert>		// ����assert����Ҫ������ͷ�ļ�
using namespace std;

void copydata(void* ptr1, void* ptr2)	// ��ptr2�е����ݸ��Ƶ�ptr1��
{
	assert(ptr1 && ptr2);		// ����ptr1��ptr2������Ϊ��
	cout << "����ִ�и������ݵĴ���" << endl;
}

int main(void)
{
	const int ii = 0,jj = 0;

	static_assert(ii, "ii��ֵ���Ϸ�");
	/*copydata(nullptr , &jj);*/
	return 0;
}