#include <iostream>
using namespace std;

int main(void)
{
	double* ptr=nullptr;

	// ����һ����ڴ�
	//try {
	//	ptr = new double[10000000000];
	//	// new�����ڴ�ʧ�ܣ����׳��쳣�����������û�д������׳����쳣���������� abort() ������ֹ
	//}
	//
	//catch (bad_alloc& e)
	//{
	//	cout << "�����ڴ�ʧ��" << endl;
	//}

	ptr = new(std::nothrow) double[10000000000];
	if (ptr == nullptr) cout << "�����ڴ�ʧ��" << endl;
	if (ptr != nullptr)
	{
		delete[] ptr;
	}
}