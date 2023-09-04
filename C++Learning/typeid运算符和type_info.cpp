#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

// typeid��������ڻ�ȡ�������͵���Ϣ��
// typeid(��������)   typeid(����������ʽ) 
// typeid���������type_info���������ã�type_info����<typeinfo>ͷ�ļ��ж��壩
// type_info������name()��Ա����������ֵ��һ���ַ�����ͨ��������
// type_info���ʵ������������죬

class AA {
public:
	AA() {}
};


int main(void)
{
	// typeid �����Զ������������
	/*int ii = 3;
	int* pii = &ii;
	int& rii = ii;
	cout << "typeid(int)= " << typeid(int).name() << endl;
	cout << "typeid(ii)= " << typeid(ii).name() << endl;
	cout << "typeid(int*)= " << typeid(int*).name() << endl;
	cout << "typeid(pii)= " << typeid(pii).name() << endl;
	cout << "typeid(int&)= " << typeid(int &).name() << endl;
	cout << "typeid(rii)= " << typeid(rii).name() << endl;*/

	// typeid �����Զ������������
	AA aa;
	AA* paa = &aa;
	AA& raa = aa;
	cout << "typeid(AA)= " << typeid(AA).name() << endl;
	cout << "typeid(aa)= " << typeid(aa).name() << endl;
	cout << "typeid(AA*)= " << typeid(AA*).name() << endl;
	cout << "typeid(paa)= " << typeid(paa).name() << endl;
	cout << "typeid(AA&)= " << typeid(AA&).name() << endl;
	cout << "typeid(raa)= " << typeid(raa).name() << endl;

	// type_info������== �� != ����������ڶ����ͽ��бȽ�
	if (typeid(AA) == typeid(aa)) {
		cout << "ok1" << endl;
	}

	if (typeid(AA*) == typeid(paa)) {
		cout << "ok2" << endl;
	
	}

	if (typeid(AA) == typeid(raa)) {
		cout << "ok3" << endl;
	}

	if (typeid(AA) == typeid(*paa)) {
		cout << "ok4" << endl;
	}
	return 0;
}