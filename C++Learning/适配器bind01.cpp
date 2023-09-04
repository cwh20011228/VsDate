#include <iostream>
#include <functional>
using namespace std;

// ��ͨ����
void show(int bh, const string& message)
{
	cout << "�װ���" << bh << "�ţ�" << message << endl;
}

// ��ľ�̬��Ա����
struct AA {
	static void show(int bh, const string& message)
	{
		cout << "�װ���" << bh << "�ţ�" << message << endl;
	}
};

// �º���
struct BB {
	void operator()(int bh, const string& message)
	{
		cout << "�װ���" << bh << "�ţ�" << message << endl;
	}
};

//��������ͨ��Ա����
struct CC {
	void show(int bh, const string& message)
	{
		cout << "�װ���" << bh << "�ţ�" << message << endl;
	}
};

//�ɱ�ת��Ϊ��ͨ����ָ�����
struct DD {
	using Fun = void(*)(int, const string&);	// ����ָ��ı���
	operator Fun() {
		return show;	// ������ͨ����show�ĵ�ַ
	}
};


int main(void)
{
	//��ͨ����
	//function<void(int, const string&)> fn1 = bind(show, placeholders::_1, placeholders::_2);	// ��bind()����ͨ������function����fn1
	auto fn1 = bind(show, placeholders::_1, placeholders::_2);	// bind���ص���function����
	fn1(1, "����һֻɵɵ��");	//��function���������ͨȫ�ֺ���show

	//��ľ�̬��Ա����
	function<void(int, const string&)> fn2 = bind(AA::show, placeholders::_1, placeholders::_2);
	fn2(2, "����һֻɵɵ��");	// ��function���������ľ�̬��Ա����

	// �º���
	function<void(int, const string&) > fn3 = bind(BB(), placeholders::_1, placeholders::_2);
	fn3(3, "����һֻɵɵ��");	// ��function������÷º���

	// ����Lambda����
	auto lb = [](int bh, const string& message)
	{
		cout << "�װ���" << bh << "�ţ�" << message << endl;
	};

	function<void(int, const string&)> fn4 = bind(lb, placeholders::_1, placeholders::_2);
	fn4(4, "����һֻɵɵ��");	// ��function�������lambda����

	// ��ת��Ϊ����ָ�������󣬱�����º���һ��
	DD dd;
	function<void(int, const string&)> fn6 = bind(dd, placeholders::_1, placeholders::_2);
	fn6(6, "����һֻɵɵ��");

	// ��ķǾ�̬��Ա����
	CC cc;
	function<void(CC&, int, const string&)> fn5 = bind(&CC::show, placeholders::_1, placeholders::_2, placeholders::_3);	// �����б��һ������Ҫ������������
	fn5(cc, 5, "����һֻɵɵ��");	//��function������ó�Ա����

	// ��ʵ�ʿ����У�������ķǾ�̬��Ա��������function������õ�ʱ�򣬲�ϣ���Ѷ��󴫽�ȥ����Ϊ������������ģ��
	// Ϊ�˽��������⣬���԰Ѷ���cc��ǰ��
	function<void(int, const string&)> fn7 = bind(&CC::show,&cc, placeholders::_1, placeholders::_2);	// �����б��һ������Ҫ������������
	fn7(5, "����һֻɵɵ��");	//��function������ó�Ա����,����Ҫ������cc�ˣ�������ģ�壩

}

// ͨ��bind�����������ǰ����ֿɵ��ö���Ĵ���ͳһ��