#include <iostream>
using namespace std;

void show()
{
	cout << "������show()����" << endl;
}

class BB		// ��ͨ��
{
public:
	void operator()()
	{
		cout << "������BB��ķº���" << endl;
	}
};

// ����ģ�壬�����ͷ���ֵ���������ͣ�֧����ͨ���ģ������������ͣ�

template <typename T>
void func(T tt)
{
	tt();
}


int main(void)
{
	//BB b;
	func(show);

	return 0;
}