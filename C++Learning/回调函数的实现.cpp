#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>	// ��������
#include <deque>	// ˫�˶�������
#include <string>
#include <functional>
using namespace std;

// ���Ҫ��ص�����ֻ����һ����������Ҫ�����������string����
void show(const string& message)	// ����ҵ�����ͨ����
{
	cout << "�������ݣ�" << message << endl;
}

struct BB {	// ����ҵ�����
	void show(const string& message)	
	{
		cout << "���������ݣ�" << message << endl;
	}
};
class AA {
private:
	mutex m_mutex;	// ����������
	condition_variable m_cond;	//��������
	queue<string,deque<string>> m_q;	// ���Ӷ���
	function<void(const string&)> m_callback;	// �ص���������
 public:
	 // ע��ص��������ص�����ֻ��һ�������������߽��յ������ݣ�
	 template<typename Fn,typename ...Args>
	 void callback(Fn&& fn, Args&& ...args)
	 {
		 m_callback = bind(forward<Fn>(fn), forward<Args>(args)...,std::placeholders::_1); // �󶨻ص�����
		// ����������Ŀɵ��ö����ǳ�Ա��������Ҫ�Ѷ����thisָ�봫������˭���ó�Ա������thisָ���ָ��˭������thisָ���Ƕ���ĵ�ַ &cc�����ɱ�������н���һ������
		// ����������Ŀɵ��ö����ǳ�Ա��������ô�ɱ�������о�û�в�����
		// ������������ռλ������Ϊ����ڵ��ûص�������ʱ�򣬻�����ݴ�����
	 }

	void incache(int num)	// �������ݣ�numָ�����ݵĸ���
	{
		lock_guard<mutex> lock(m_mutex);	// �������
		for (int ii = 1; ii <= num; ii++) {
			static int bh = 1;
			string message = to_string(bh++) + "�ų�Ů";
			m_q.push(message);	// ���������������
		}
		m_cond.notify_all();	// ���ѱ���ǰ���������������߳�
	}

	void outcache()
	{
		while (true) {
			string message;
			{
				unique_lock<mutex> lock(m_mutex);	// ��mutexת��Ϊunique_lock
				while (m_q.empty()) {
					m_cond.wait(lock);
				}

				// ���ݳ���
				message = m_q.front();
				m_q.pop();
				cout << "�߳�" << this_thread::get_id() << ", " << message << endl;
			}
			// ��������
			this_thread::sleep_for(chrono::milliseconds(1));
			if (m_callback) m_callback(message);	// �ص����������յ������ݴ�����
			// ���ע���˻ص���������ô�͵��������ѳ��ӵ�����message���������ûص�����ȥ����ҵ��
		}
	}

};

int main(void)
{
	AA aa;
	// �ڴ����߳�֮ǰ����ע��ص�����
	//aa.callback(show);	// �ص���������ͨ����
	BB bb;
	aa.callback(&BB::show, &bb);	// �ص���������ĳ�Ա����

	thread t1(&AA::outcache, &aa);
	thread t2(&AA::outcache, &aa);
	thread t3(&AA::outcache, &aa);

	this_thread::sleep_for(chrono::seconds(2));
	aa.incache(2);

	this_thread::sleep_for(chrono::seconds(3));
	aa.incache(5);

	t1.join();
	t2.join();
	t3.join();
}