#include <iostream>
#include <functional>
using namespace std;

void show(int bh,const string& message)
{
	cout << "�װ���" << bh << "�ţ�" << message << endl;
}

// ��ͨ����show()�ĺ���������function����Ҫ�����������ͬ��

int main(void)
{
	function<void(int, const string&)> fn1=show;  // ����һ��function��Ķ���
	function<void(int, const string&)> fn2=bind(show,placeholders::_1,placeholders::_2);		// ��bind()��һ���ɵ��ö����function����fn2
	// placeholders::_n �ǲ���ռλ���� placeholders::_1 ��ʾfunction����ĵ�һ�����������λ�ã� placeholders::_2 ��ʾfunction����ĵ�2�����������λ�ã�

	fn1(1, "����һֻɵɵ��");
	fn2(1, "����һֻɵɵ��");

	// ����function��Ķ���fn3,����������void �� �����б��� const string&, int
	function<void(const string&, int)> fn3 = bind(show,placeholders::_2,placeholders::_1);
	fn3("����һֻɵɵ��",1);


	int bh = 3;
	// ����function��Ķ��󣬷��������� void �������б��� const string&
	//function<void(const string&)> fn4 = bind(show, bh, placeholders::_1);	// ��ǰ�󶨵�ȱʡ��ֵ����
	function<void(const string&)> fn4 = bind(show, std::ref(bh), placeholders::_1);	// ��ǰ�󶨵������ô���

	// function����ֻ��Ҫһ������������show()�����������������Ļ������԰�function������Ҫ���Ǹ�����(���bh)��ǰ��
	// ��bind()��ǰ�󶨲�������һ��ϸ��Ҫע�⣺���󶨵Ĳ���ȱʡ��ֵ����
	bh = 8;
	fn4("����һֻɵɵ��");

	function<void(int, const string&, int)> fn5 = bind(show, placeholders::_1, placeholders::_2);
	fn5(1, "����һֻɵɵ��", 2);
}