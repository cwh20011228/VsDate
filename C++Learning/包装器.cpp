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
	using fun = void(int, const string&);	// ��ͨ����show���͵ı���
	fun* fp1 = show;	//��������ָ�룬ָ����ͨ����
	fp1(1, "����һֻɵɵ��");	// �ú���ָ�������ͨ����

	//TODO: �ð�װ��
	function<void(int, const string&)> fn1 = show;	// ��װ��ͨȫ�ֶ���,�ɶ��Ը���
	//function<fun> fn1 = show;   // functionģ���������ͨ�������͵ı���
	fn1(1, "����һֻɵɵ��");	//��function���������ͨȫ�ֺ���show

	//��ľ�̬��Ա����
	using sun = void(int, const string&);	// ��ͨ�������͵ı���
	sun& sp1 = AA::show;	// �����������ã�������ľ�̬��Ա����
	sp1(2, "����һֻɵɵ��");	//�ú������õ�����ľ�̬��Ա����

	//TODO: ��װ��ľ�̬��Ա����
	function<void(int, const string&)> fn2 = AA::show;	// ��װ��ľ�̬��Ա����
	fn2(2, "����һֻɵɵ��");	// ��function���������ľ�̬��Ա����

	// �º���
	BB bb;
	bb(3, "����һֻɵɵ��");	// �÷º���������÷º���

	// TODO: ��װ�º���
	//function<void(int, const string&) > fn3 = bb;	// ��װ�º���
	function<void(int, const string&) > fn3 = BB();	// ����������
	fn3(3, "����һֻɵɵ��");	// ��function������÷º���

	// ����Lambda����
	auto lb = [](int bh, const string& message)
	{
		cout << "�װ���" << bh << "�ţ�" << message << endl;
	};
	lb(4, "����һֻɵɵ��");	// lambda�����ı����Ƿº������º����ı�������

	//TODO: ��װlambda����
	function<void(int, const string&)> fn4 = lb;
	/*function<void(int, const string&)> fn4 = [](int bh, const string& message)
	{
		cout << "�װ���" << bh << "�ţ�" << message << endl;
	};	// lambda��һ��������	*/
	fn4(4, "����һֻɵɵ��");	// ��function�������lambda����


	// ��ķǾ�̬��Ա����
	CC cc;
	using cfun = void(CC::*)(int, const string&);	//���Ա������ָ������
	cfun cpf = &CC::show;	// ��ĳ�Ա����ָ��ָ����ĳ�Ա����
	(cc.*cpf)(5, "����һֻɵɵ��");	// ��ĳ�Ա����ָ����ó�Ա����

	//TODO: ��װ��ķǾ�̬��Ա����,���Ա������������Ķ��������ܵ���
	function<void(CC&, int, const string&)> fn5 = &CC::show;	// �����б��һ������Ҫ������������
	fn5(cc, 5, "����һֻɵɵ��");	//��function������ó�Ա����

	// ��ת��Ϊ����ָ�������󣬱�����º���һ��
	DD dd;
	dd(6, "����һֻɵɵ��");	// �ÿ��Ա�ת��Ϊ����ָ�������������ͨ����

	//TODO: ��װ��ת��Ϊ����ָ��������
	function<void(int, const string&)> fn6 = dd;
	fn6(6, "����һֻɵɵ��");
}