#include <iostream>
using namespace std;

// ���������ֻ������ĳ�Ա��������
// ��������������������ഴ���Ķ���Ҳ�к��������º���
void show(string str)
{
	cout << "��ͨ������" << str << endl;
}

class CGirl {
public:
	void operator()(string str);
};

void CGirl::operator()(string str)
{
	cout<< "���غ�����" << str << endl;
}

int main(void)
{
	CGirl show;
	show("����һֻɵɵ��");
	
	::show("����һֻɵɵ��"); // ���õ���ȫ�ֺ���   ::show()

	return 0;
}