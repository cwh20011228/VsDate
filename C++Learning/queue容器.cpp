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
	queue<CGirl, list<CGirl>> q; // 物理结构为链表
	//queue<CGirl, deque<CGirl>> q; // 物理结构为数组
	//queue<CGirl> q; // 物理结构为数组
	//queue<CGirl, vector<CGirl>> q; // 物理结构是数组，不支持

	q.push(CGirl(3, "西施"));
	q.emplace(8,"冰冰");
	q.push(CGirl(5,"蜜蜜"));
	q.push(CGirl(2,"西瓜"));

	while (q.empty() == false) {
		cout << "编号：" << q.front().m_bh << " ,姓名：" << q.front().m_name << endl;
		q.pop();
	}
	{

	}
	return 0;
}