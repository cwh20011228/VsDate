#include <iostream>
#include <queue>
#include <deque>
#include <list>
using namespace std;

class CGirl {
public:
	int m_bh;
	string m_name;
	CGirl(const int& bh,const string& name):m_bh(bh),m_name(name){ }
};

int main(void)
{
	queue<CGirl, list<CGirl>> q; // ����ṹΪ����
	//queue<CGirl, deque<CGirl>> q; // ����ṹΪ����
	//queue<CGirl> q; // ����ṹΪ����
	//queue<CGirl, vector<CGirl>> q; // ����ṹ�����飬��֧��

	q.push(CGirl(3, "��ʩ"));
	q.emplace(8,"����");
	q.push(CGirl(5,"����"));
	q.push(CGirl(2,"����"));

	while (q.empty() == false) {
		cout << "��ţ�" << q.front().m_bh << " ,������" << q.front().m_name << endl;
		q.pop();
	}
	{

	}
	return 0;
}