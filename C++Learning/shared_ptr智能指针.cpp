#include <iostream>
#include <memory>
using namespace std;

class AA {
public:
	string m_name;
	AA(){ cout << "�����˹��캯��AA()" << endl; }
	AA(const string& name):m_name(name)
	{ 
		cout << "�����˹��캯��AA(const string& name):" << m_name << endl; 
	
	}
	~AA(){ cout << "��������������~AA()��" << m_name << endl; }
};

int main(void)
{
	shared_ptr<AA> pa0 = make_shared<AA>("��ʩa"); // ��ʼ����ʩa
	
	shared_ptr<AA> pa1 = pa0;	// ���Ѵ��ڵ�shared_ptr�������죬������1
	shared_ptr<AA> pa2 = pa0;	// ���Ѵ��ڵ�shared_ptr�������죬������1
	cout << "pa0.use_count()=" << pa0.use_count() << endl;	//ֵΪ3

	cout << endl;
	shared_ptr<AA> pb0 = make_shared<AA>("��ʩb");	// ��ʼ����ʩb
	shared_ptr<AA> pb1 = pb0;	// ���Ѵ��ڵ�shared_ptr�������죬������1
	shared_ptr<AA> pb2 = pb0;	// ���Ѵ��ڵ�shared_ptr�������죬������1
	cout << "pb0.use_count()=" << pb0.use_count() << endl;	// ֵΪ3
	cout << endl;

	pb2 = pa2;	// ��ֵ����pb2Ҳָ������ʩa,����ָ����ʩa��shared_ptr�����1��ָ����ʩb��shared_ptr�����1
	/*pb1 = pa2;
	pb0 = pa2; //! pb0ָ����ʩa����ʩbû�� shared_ptr��֮������ ���ͷ���ʩb�����Դ */

	//TODO: ָ����Դ��ָ�����һ�������ü����ͼ�1��ָ����Դ��ָ������һ�������ü����ͼ�1��������ü���Ϊ0�ˣ����ͷŸ���Դ��
	cout << "pa0.use_count()=" << pa0.use_count() << endl;	//ֵΪ4
	cout << "pb0.use_count()=" << pb0.use_count() << endl;	//ֵΪ2
	cout << endl;

}