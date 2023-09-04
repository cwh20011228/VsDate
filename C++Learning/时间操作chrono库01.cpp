#define _CRT_SECURE_NO_WARNINGS  // localtime()��Ҫ����ꡣ
#include <iostream>
#include <chrono>
#include <iomanip>   // put_time()������Ҫ������ͷ�ļ���
#include <sstream>
using namespace std;

int main(void)
{
	//(1) ��̬��Ա����chrono::system_clock::now()���ڻ�ȡϵͳʱ�䣨C++ʱ�䣩
	//chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
	auto now = chrono::system_clock::now();
	
	// (2) ��̬��Ա����chrono::system_clock::to_time_t()��ʱ��ת��Ϊtiem_t��(UTCʱ��)
	//time_t t_now = chrono::system_clock::to_time_t(now);
	auto t_now = chrono::system_clock::to_time_t(now);
	
	//TODO: ʱ���ƫ��(���϶�Ӧ����)
	t_now = t_now + 24 * 60 * 60;	// �ѵ�ǰ��ʱ���1��
	//t_now = t_now + (-1 * 60 * 60);	// �ѵ�ǰʱ���1��
	//t_now = t_now + 120;	// ��ǰʱ���120��

	// (3) std::localtime()������time_tת��Ϊ����ʱ�䣨����ʱ�䣩
	// localtime()�����̰߳�ȫ�ģ�VS��localtime_s���棬Linux��localtime_r����
	//tm* tm_now = std::localtime(&t_now);
	auto tm_now = std::localtime(&t_now);

	// (4����ʽ���������ʱ��
	std::cout << std::put_time(tm_now, "%Y-%m-%d %H:%M:%S")<<std::endl;	
	// Y-�� m-�� d-�� H-Сʱ M-���� S-��
	std::cout << std::put_time(tm_now, "%Y-%m-%d") << std::endl;
	std::cout << std::put_time(tm_now, "%H:%M:%S") << std::endl;
	std::cout << std::put_time(tm_now, "%Y%m%d%H%M%S") << std::endl;

	// ʵ�ʿ����У���ȡϵͳʱ��󣬲�һ��Ҫ��ʾ������
	stringstream ss; //  ����stringstream������Ҫ����ͷ�ļ� <sstream>
	ss << std::put_time(tm_now, "%Y-%m-%d");	// ��ʱ�����������ss��
	string timestr = ss.str();	// ��ssת����string����
	cout << timestr << endl;
}