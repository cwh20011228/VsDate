#include <iostream>
using namespace std;

void  func(void* ptr)
{
	//TODO: (2)��ָ�루���ã�ת��Ϊ���ͱ�����������ָ��ռ�õ��ֽ�������һ�£�����ת��������ʧ����
	long long a = reinterpret_cast<long long>(ptr);
	cout << "a=" << a << endl;
}




int main(int argc,char* argv[])
{
	
	long long ii = 3;
	int aa = 10;

	//TODO: Ӧ�ó�������1��reinterpret_cast�ı�ָ������õ�����
	double* pd1 = reinterpret_cast<double*>(&aa);

	
	//TODO: (3) ��һ�����ͱ���ת��Ϊָ�루���ã�
	func(reinterpret_cast<void*>(ii));
}
