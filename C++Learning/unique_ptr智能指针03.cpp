#include <iostream>
#include <memory>
using namespace std;

// ��̬��Ӧ�ó����������еĳ�Ա����(�麯��)ʵ�ֻ������ܣ����������ض����麯���������书��
// ����ͨ�̳���˵����Ա�����ĵ�ַ�Ǿ�̬�ģ�����������ڴ�ģ����

// �������û���麯���������ʱ�򣬱�����ֱ�ӽ���Ա�����ĵ�ַ���ӵ��������ļ��С�
// ����������麯���������ʱ�򣬱�����������麯���ĵ�ַ���ӵ��������ļ��У�
// �����麯�������У�����һ������ĳ�Ա�����麯��ָ�루vfptr��,���������еĹ����У�
// ��������˶��󣬳��˸�����ĳ�Ա�����ڴ棬���ᴴ��һ���麯����vftable��,
// ���麯��ָ��ָ���麯����
/*
* �ڳ����У�������õ�����ͨ��Ա����������������Ա������ַ���ӵ��������ļ��У�ֱ��ִ�к���
* ������õ����麯����Ҫ�Ȳ����麯�����õ������ĵ�ַ����ִ�к���
*/

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
	//void skill3() { cout << "��ʩ�ͷ��˴���." << endl; }
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
		// ��������ָ�룬����ָ�������࣬�û���ָ�����������ĳ�Ա����
		int id = 0;
		cout << "������Ӣ��(1:��ʩ  2������ 3�����)��";
		cin >> id;
		// 1:��ʩ  2������ 3�����
		unique_ptr<Hero> ptr;
	
		if (id == 1) {	
			ptr = unique_ptr<XS>(new XS);
		}
		else if (id == 2) {
			ptr = unique_ptr<HX>(new HX);
		}
		else if (id == 3) {
			//ptr=new LB;
			ptr = unique_ptr<LB>(new LB);
		}

		if (ptr != nullptr) {
			ptr->skill1();
			ptr->skill2();
			ptr->skill3();

		}
		
		return 0;
}