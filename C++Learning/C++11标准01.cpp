#include <iostream>
using namespace std;

class CGirl {
private:
	int m_bh=20;
	string m_name="��ʩ";
	char m_xb = 'X';
public:
	CGirl() = default;		// ����Ĭ�Ϲ��캯��
	CGirl(int bh,string name,char xb):m_bh(bh),m_name(name),m_xb(xb) { }
	CGirl(const CGirl& g) = delete;		// ɾ���������캯��
	void show() { cout << "bh=" << m_bh << ",m_name=" << m_name << endl; }
	//~CGirl() = delete;	// ɾ����������
};

// ��������ṩ�˹��캯������ô�������Ͳ����ṩĬ�Ϲ��캯��


int main(void)
{
	CGirl g1;
	g1.show();
	CGirl g2 = g1;
	return 0;
}