#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(void)
{
	list<int> l1;	//����һ���յ�list����
	cout << "l1.size()=" << l1.size() << endl;
	cout << "-------------------------" << endl;

	list<int> l2{ 1,2,3,4,5,6,7,8,9,10 };		//ʹ��ͳһ��ʼ���б�
	//list<int> l2({ 1,2,3,4,5,6,7,8,9,10 });
	//list<int> l2 = { 1,2,3,4,5,6,7,8,9,10 };
	/*for (auto it = l2.begin(); it != l2.end(); ++it)*/
	for(auto val:l2)
	{
		cout << val << "  ";
	}
	cout <<endl<< "-------------------------" << endl;


	list<int> l3{ l2 };		//ʹ�ÿ������캯��
	for (auto val : l3) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;


	list<int> l4(l3.begin(),l3.end());		// �õ���������List����
	for (auto val : l4) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;

	vector<int> v1{ 1,2,3,4,5,6,7,8,9,10 };		// ����vector����
	list<int> l5(v1.begin()+2, v1.end()-3);		// ��vector�����ĵ�����
	for (auto val : l5) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;

	int a1[]= { 1,2,3,4,5,6,7,8,9,10 };
	list<int> l6(a1 + 2, a1 + 10 - 3);	//�������ָ����Ϊ����������list����,
	//�����ָ������Ȼ��������ʵ�������֧�ֵ������Ĳ���������֧�ֵ���������Щ����begin,end ...
	for (auto val : l6) {
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;

	char str[] = "hello world";
	string s1(str + 1, str + 7);	// �ַ������ָ�룬��������ʵ�����
	for (auto val : s1) {
		cout << val << "  ";
	}
	cout << endl <<s1<<endl<< "-------------------------" << endl;


	vector<int> v2(l3.begin(), l3.end());	//��list�����ĵ���������vector����
	for (auto val : v2)
	{
		cout << val << "  ";
	}
	cout << endl << "-------------------------" << endl;
}