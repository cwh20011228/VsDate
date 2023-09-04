#include <iostream>
#include <string>
using namespace std;


int main(void)
{
//	cout << "npos=" << string::npos << endl;

	//TODO: 1��string(); // ����һ������Ϊ0��string����Ĭ�Ϲ��캯������

	string s1;
	cout << "s1=" << s1 << endl;
	cout << "s1.capacity()=" << s1.capacity() << endl;	// ���ص�ǰ���������Դ���ַ�������
	cout << "s1.size()=" << s1.size() << endl;	// �������������ݵĴ�С
	cout << "������̬������׵�ַ=" << (void*)s1.c_str() << endl;
	s1 = "xxxxxxxxxxxxxxxxxxxxxxxxxx";	//! string����չ������ʱ���ȷ������Ŀռ䣬Ȼ������ݸ��Ƶ��µĿռ䣬�ͷŵ���ǰ�Ŀռ�
	cout << "s1.capacity()=" << s1.capacity() << endl;	// ���ص�ǰ���������Դ���ַ�������
	cout << "s1.size()=" << s1.size() << endl;	// �������������ݵĴ�С
	cout << "������̬������׵�ַ=" << (void*)s1.c_str() << endl;
	cout << "-------------------" << endl;

	//TODO: 2��string(const char* s); // ��string�����ʼ��Ϊsָ���NBTS��ת����������
	string s2("hello world");
	cout << "s2=" << s2 << endl;
	string s3 = "hello world";
	cout << "s3=" << s3 << endl;
	cout << "-------------------" << endl;


	//TODO: 3��string(const string & str); // ��string�����ʼ��Ϊstr���������캯������
	//! string������һ��ָ��̬�����ָ�룬�������캯�������
	string s4(s3);
	cout << "s4=" << s4 << endl;
	string s5 = s3;
	cout << "s5=" << s5 << endl;
	cout << "-------------------" << endl;


	//TODO: 4��string(const char* s, size_t n); 
	// ��string�����ʼ��Ϊsָ��ĵ�ַ��n�ֽڵ����ݡ������ж�str�Ľ�β��־
	string s6("hello world", 5);
	cout << "s6=" << s6 << endl;
	cout << "s6.capacity()=" << s6.capacity() << endl;
	cout << "s6.size()=" << s6.size() << endl;
	string s7("hello world", 50);
	cout << "s7=" << s7 << endl;
	cout << "s7.capacity()=" << s7.capacity() << endl;
	cout << "s7.size()=" << s7.size() << endl;
	cout << "-------------------" << endl;

	//TODO: 5��string(const string & str, size_t pos = 0, size_t n = npos); 
	// ��sring�����ʼ��Ϊstr��λ��pos��ʼ����β���ַ������λ��pos��ʼ��n���ַ��������ж�str�Ľ�β��־
	string s8(s3, 3,5);
	cout << "s8=" << s8 << endl;
	string s9(s3, 3);	// ��s3�ĵ�����λ�ÿ�ʼ����ȡ������������
	cout << "s9=" << s9 << endl;
	cout << "s9.capacity()=" << s9.capacity() << endl;	// ���ص�ǰ���������Դ���ַ�������
	cout << "s9.size()=" << s9.size() << endl;	// �������������ݵĴ�С

	string s10("hello world", 3, 5);  
	cout << "s10=" << s10 << endl;
	string s11("hello world", 3);	// ���õ��ǹ��캯�� 4��string(const char* s, size_t n); 
	cout << "s11=" << s11 << endl;
	cout << "-------------------" << endl;


	//TODO: 6��template<class T> string(T begin, T end);
	// ��string�����ʼ��Ϊ����[begin,end]�ڵ��ַ�������begin��end����Ϊ����ָ�룬����ָ��λ�ã���Χ����begin���ڣ���������end��
	
	//7��string(size_t n, char c); // ����һ����n���ַ�c��ɵ�string����
	string s12(8, 'a');
	cout << "s12=" << s12 << endl;
	cout << "s12.capacity()=" << s12.capacity() << endl;
	cout << "s12.size()=" << s12.size() << endl;
	string s13(30, 0);
	cout << "s13=" << s13 << endl;
	cout << "s13.capacity()=" << s13.capacity() << endl;
	cout << "s13.size()=" << s13.size() << endl;


}