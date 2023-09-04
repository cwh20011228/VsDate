#include <iostream>
#include <thread>
#include <functional>
using namespace std;

void show0() 
{
	cout << "�װ��ģ�����һֻСС��" << endl;
}

void show1(const string& message)
{
	cout << "�װ��ģ�" << message << endl;
}

struct CC {
	void show2(int bh, const string& message) {
		cout << "�װ���" << bh << "�ţ�����һֻСС��" << endl;
	}
};

template <typename Fn,typename ...Args>		
auto show(Fn&& fn, Args&& ...args)	// auto��Ϊ��������ֵ����C++14���﷨ ��T&& ���Խ�����ֵ����ֵ��
//auto show(Fn&& fn, Args&& ...args)-> decltype(bind(forward<Fn>(fn), forward<Args>(args)...))
{
	cout << "���ǰ��׼������..." << endl;
	auto f= bind(forward<Fn>(fn), forward<Args>(args)...);	// bind()����ҲҪ����ת��
	f();
	cout << "������" << endl;
	return f;
}

int main(void)
{
	show(show0);
	show(show1, "����һֻɵɵ��");
	CC cc;
	auto f=show(&CC::show2, &cc, 3, "����һֻɵɵ��");
	f();
}