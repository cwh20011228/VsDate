#include <iostream>
using namespace std;

#define BH 3
#define MESSAGE "����һֻɵɵ��"

int main(void)
{
	/*cout << "�װ���" << BH << "�ţ�" << MESSAGE << endl;
	cout << __FILE__ << endl;
	cout << __FUNCTION__ << endl;
	cout << __LINE__ << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __TIMESTAMP__ << endl;
	cout << __cplusplus << endl;*/

//TODO: ��VS�У�long��32λ��long long ��64λ��  linux�� long ��64λ
	// ��ͬ����ϵͳ�ĺ꣺  __linux__   _WIN32

//��#ifdef  #else #endif   ������������ָ�����������㣬��������δ��룬����δ��������롣������������㣬�Ͳ�������δ��룬���������ڣ�Ҳ���������
#ifdef _WIN32
	cout << "����windowsϵͳ" << endl;
	typedef long long int64;
#else
	cout << "�ⲻ��windowsϵͳ" << endl;
	typedef long int64;
#endif

	int64 a = 10;
	cout << "a=" << a << endl;

	return 0;
}