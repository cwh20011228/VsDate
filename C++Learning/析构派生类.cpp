#include <iostream>
using namespace std;

// delete��ָ���ǿ��Եģ��� deleteҰָ����ܻᵼ�³���ı���
class AA {
public:
	AA() { cout << "�����˻����Ĭ�Ϲ��캯��AA()" << endl; }
	virtual void func() { cout << "�����˻����func()" << endl; }
	virtual ~AA() { cout << "�����˻������������~AA()" << endl;  }
	//virtual ~AA(){}
};

class BB :public AA {
public:
	BB() { cout << "�������������Ĭ�Ϲ��캯��BB()" << endl; }
	void func() { cout << "������������ĺ���func()" << endl; }
	~BB() { cout<< "���������������������~BB()" << endl; }
};


int main(void)
{
	AA *b=new BB;
	
	delete b;

	
	return 0;
}