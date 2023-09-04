#include <iostream>
#include <string>
#include <thread>	// �߳���ͷ�ļ�
#include <mutex>	// ���������ͷ�ļ�
#include <deque>	// deque����ͷ�ļ���˫�˶���
#include <queue>	// queue������ͷ�ļ�������
#include <condition_variable>	// ����������ͷ�ļ�
using namespace std;

// ������/�����ߵ�ʵ��д��һ�����У����ǱȽϱ�׼������
class AA {
private:
	timed_mutex m_mutex;	// ����ʱ���ƵĻ�����
	condition_variable_any m_cond;	// ��������
	queue<string, deque<string>> m_q;	// ������У��ײ�������deque
public:
	//TODO: �������̵߳�������
	void incache(int num)	// �������ݣ�numָ�����ݵĸ���
	{
		lock_guard<timed_mutex> lock(m_mutex);	// �������(�뿪�������ʱ��lock_guard���Զ��ͷ���)
		for (int ii = 0; ii < num; ii++) {
			static int bh = 1;	// ��Ů���
			string message = to_string(bh++) + "�ų�Ů";	// ƴ�ӳ�һ������
			m_q.push(message);	// �������������������
		}
		//m_cond.notify_one();	// �����������̷߳���֪ͨ����������������Ҫ��������һ������ǰ ���������������߳�
		m_cond.notify_all();	// ֪ͨ���еȴ����߳�
	}
	// �����������������������̻߳��γ�һ���ȴ����У���������
	// ����������������ͬʱ�ж�����ݣ���ô��Ӧ��ֻ��һ���������߳�ȥ����������������ö���߳�ͬʱ����������Ч�ʲŸ��ߡ�
	
	//TODO: �������̵߳�������
	void outcache()
	{
		while (true) {
			string message;
			{
				// �ѻ�����ת��Ϊ unique_lock<mutex> ,������������뿪�������ʱ��unique_lock���Զ��ͷ�����
				unique_lock<timed_mutex> lock(m_mutex);	// �������

				//TODO: ֻ���ڼ����ɹ�������£����л�������������������wait()�����С�
				//TODO: �������������߳�һ�����У���ô��ֻ����һ���߳���������ɹ��������������̶߳������������뻥��������
				 
				//? ֻ��һ���߳�������wait()�����У��������̶߳��������������������
				// ���������û�����ݣ����ѭ��������ֹ
				
				//while (m_q.empty()) {	//�������Ϊ�գ�����ѭ����������в�Ϊ�գ�������ѭ����ֱ�Ӵ������ݡ�������ѭ����������if
				//	m_cond.wait(lock);	// �ȴ������ߵĻ����źţ�֪ͨ�������û��֪ͨ����ǰ�̻߳�һֱ����
				//}
				m_cond.wait(lock, [this] {return !m_q.empty();} );

				// ����Ԫ�س���
				message = m_q.front();	// ���ض�ͷ��Ԫ��
				m_q.pop();	// �ٽ�Ԫ��ɾ�������ӣ�
				cout << "�߳�:" << this_thread::get_id() << ", " << message << endl;
				//! �뿪�������ʱ��unique_lock���Զ��ͷ���
				//lock.unlock();	// �ֹ�����
			}
				
			
			// ������ӵ����ݣ����������ѵ���
			this_thread::sleep_for(chrono::microseconds(1));	// ���账��������Ҫ1����
			
		}
	}
};

//TODO: ʹ������һ��ԭ�򣺳�������ʱ��Խ�̣�Ч��Խ��
//! �����������߳���˵�������ݴӶ������ó����ˣ���Ӧ�������ͷ������������ݵ�ʱ���Ѿ�����Ҫ����


int main(void)
{
	AA aa;
	// outcache()��Ա�����Ĵ����߼�����ѭ�������ԣ��������̴߳����ˣ���һֱ���ڣ������˳�
	thread t1(&AA::outcache, &aa);	// �����������߳�t1
	thread t2(&AA::outcache, &aa);	// �����������߳�t2
	thread t3(&AA::outcache, &aa);	// �����������߳�t3

	// incache()��Ա����ֻ�����������ݣ����������ݣ������ͷ�����
	this_thread::sleep_for(chrono::seconds(2));	// ����2��
	aa.incache(2);	//����3������

	this_thread::sleep_for(chrono::seconds(3));	// ����3��
	aa.incache(5);	// ����5������

	t1.join();	// �������̵߳���Դ
	t2.join();
	t3.join();
}

// m_cond.notify_one(); 2��֮�������������߳��е�һ���̱߳����ѣ�����3�����ݡ�5��֮����һ���̱߳����ѣ�����5�����ݡ���Ϊ�������߳�һֱ�����У����Գ��򲻻��˳�
// m_cond.notify_all(); ÿ����һ�����ݺ������̶߳���ȥ�������ǣ���������е����ݸպ�����������ôÿ���߳�����һ����
// ��������������5�����ݣ���ô�е��߳�����3�����е��߳�����1����

//TODO: ���ۣ��������������ֻ��һ������ notify_one()�ȽϺ��ʣ���������������ж������ notify_all()�ȽϺ���