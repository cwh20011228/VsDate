#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class girl {
public:
	T m_yz;
	int m_count;	// ����������Ԫ�ظ���
	girl(const T yz):m_yz(yz),m_count(0) { }

	void operator()(const T& yz) {
		if (yz == m_yz) {
			m_count++;
		}
	}
};


int main(void)
{
	vector<int> vv = { 1,3,2,4,1,2,3,1,4,3 };

	girl<int> g = for_each(vv.begin(),vv.end(),girl<int>(1));	// ����ֵͳ�Ƴ�Ů����
	// �����������󣬰�yz����ȥ��m_yz=1 ��ͳ��m_yz=1�ĸ�������󷵻ض���

	cout << "g.m_count=" << g.m_count << endl;
}