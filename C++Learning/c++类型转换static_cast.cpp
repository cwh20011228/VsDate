#include <iostream>
using namespace std;
//! static_cast���ܶ���ָ������õ�const��volitale����
void func(void* ptr)	//������õĺ�����Ҫת��ָ�룬���԰������β����Ϊvoid*  
{	//! ��������ָ��  ->  void* ָ��  ->  ��������ָ��
	double* pp = static_cast<double*>(ptr);
}

int main(int argc, char* argv[])
{
	//TODO: static_cast ����������������֮���ת��
	//int ii = 3;
	//long ll = ii;	// ���԰�ȫ��������ʽת����������־���

	//double dd = 1.23;
	//long ll1 = dd;	// ������ʽת�������ǣ�����ֿ��ܶ�ʧ���ݵľ���
	//long ll2 = (long)dd;	// c�����ʾת����������־���
	//long ll3 = static_cast<long>(dd);  // c++�����ʾת����������־���
	//cout << "ll1" <<ll1 <<"  ll2=" << ll2 << "  ll3=" << ll3 << endl;

	//TODO: static_cast ����ָ��֮���ת��
	int ii = 10;
	// double* pd1 = &ii;	// ���󣬲�����ʽת��
	double* pd2 = (double*)&ii;		// c���ǿ��ת��
	//double* pd3 = static_cast<double*>(&ii);	// ����static_cast��֧�ֲ�ͬ����ָ���ת��

	void* pv = &ii;		// �κ����͵�ָ�붼������ʽת��Ϊvoid*
	double* pd4 = static_cast<double*>(pv);		// static_cast ���԰�void* ת��Ϊ�������͵�ָ��

	func(&ii);

}
