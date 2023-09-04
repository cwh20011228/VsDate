#include <iostream>
using namespace std;

// ���н׶�����ʶ��(RTTI  RunTime Type Identification),Ϊ���������н׶�ȷ����������ͣ�ֻ�����ڰ����麯�����࣬
// ��̬��˼�룺����ָ��ָ��������������֪������ָ��ָ�����������������󣿣�������������еķ��麯����
// dynamic_cast �������ָ������ָ���������������ָ��

class Hero {
public:
	int viablity;
	int attack;
	virtual void skill1() { cout << "Ӣ���ͷ���һ����." << endl; }
	virtual void skill2() { cout << "Ӣ���ͷ��˶�����." << endl; }
	virtual void skill3() { cout << "Ӣ���ͷ��˴���." << endl; }
	Hero() :viablity{ 0 }, attack{ 0 } {  }
};

class XS :public Hero {
public:

	void skill1() { cout << "��ʩ�ͷ���һ����." << endl; }
	void skill2() { cout << "��ʩ�ͷ��˶�����." << endl; }
	void skill3() { cout << "��ʩ�ͷ��˴���." << endl; }
	void show()  { cout << "�������µ�һ��Ů" << endl; }
};

class HX :public Hero {
public:
	void skill1() { cout << "�����ͷ���һ����." << endl; }
	void skill2() { cout << "�����ͷ��˶�����." << endl; }
	void skill3() { cout << "�����ͷ��˴���." << endl; }
};

class LB :public Hero {
public:
	void skill1() { cout << "����ͷ���һ����." << endl; }
	void skill2() { cout << "����ͷ��˶�����." << endl; }
	void skill3() { cout << "����ͷ��˴���." << endl; }
};

int main(void)
{
	int id = 0;
	cout << "�����id:  ";
	cin >> id;

	Hero* ptr = nullptr;
	if (id == 1) {
		ptr = new XS;
	}
	else if (id == 2) {
		ptr = new HX;
	}
	else if (id == 3) {
		ptr = new LB;
	}

	if (ptr != nullptr) {
		ptr->skill1();
		ptr->skill2();
		ptr->skill3();
		// �������ָ��ָ��Ķ�������ʩ����ô�͵�����ʩ��show()����
		// ��Ҫ������������ʩshow()����������ѻ���ָ��ת��Ϊ��������ʩ��ָ��

		//! typeid() �������ڶ�̬�ĳ��������������н׶�ʶ����������ģ��
		// ptr�ǻ���ָ�룬��Ȼ��ָ����XS���󣬵�������������Heroָ��,����typeid(ptr)==typeid(XS*)������
		XS* xsptr = nullptr;
		if (typeid(ptr)==typeid(XS*) ){
			xsptr = dynamic_cast<XS*>(ptr);
		}

		// ���ﲻ����ָ���ж��������ͣ�Ӧ����ָ��ָ��Ķ������ж�
		if (typeid(*ptr) == typeid(XS) )  {
			xsptr = dynamic_cast<XS*>(ptr);
		}

		// ���ת���ɹ������ض���ĵ�ַ�����򣬷���nullptr;
		if (xsptr != nullptr) {
			xsptr->show();
		}
		delete ptr;
	}
	// ʹ��dynamic_cast��ʱ����Ҫ�����麯����������Ƕ�̬���ͣ�����͹���ȥ

	return 0;
}