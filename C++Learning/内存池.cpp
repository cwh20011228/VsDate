#include <iostream>
using namespace std;

/*	����new��delete��Ŀ����ʵ���ڴ��
*/

class CGirl {
public:
	int m_bh;
	int m_xw;

	static char* m_pool; // �ڴ�ص���ʼ��ַ

	static bool initpool(); // ��ʼ���ڴ�صĺ���
	static void freepool(); // �ͷ��ڴ��
	CGirl(int bh,int xw);
	CGirl();
	~CGirl();
	void show();
	static void* operator new(size_t size);
	static void operator delete(void* ptr);
};

bool CGirl::initpool()
{
	m_pool = (char*)malloc(18); // ��ϵͳ����18�ֽڵ��ڴ�,��18�ֽڵ��ڴ��
	if (m_pool == 0) return false;
	memset(m_pool, 0, 18);
	cout << "�ڴ�ص���ʼ��ַ��" << (void*)m_pool << endl;
	return true;
}

void CGirl::freepool()
{
	if (m_pool == 0) return;  // ����ڴ��Ϊ�գ�����Ҫ�ͷţ�ֱ�ӷ���
	free(m_pool);
	cout << "�ڴ�����ͷ�" << endl;
}

CGirl::CGirl(int bh, int xw) :m_bh{ bh }, m_xw{ xw }
{
	cout << "�����˹��캯��CGirl(int bh, int xw)" << endl;
}

CGirl::CGirl() :m_bh{ 10 }, m_xw{ 87 }
{
	cout << "�����˹��캯��CGirl()" << endl;
}

CGirl::~CGirl()
{
	cout << "��������������~CGirl()" << endl;
}

void CGirl::show()
{
	cout << "���=" << m_bh << "  XW=" << m_xw << endl;
}

// ���ص�new ��delete����Ĭ���Ǿ�̬��Ա��������ֻ̬�ܷ��ʾ�̬��
void* CGirl::operator new(size_t size)
{
	if (m_pool[0] == 0) {	// �жϵ�һ��λ���Ƿ����
		cout << "�����˵�һ���ڴ棺" << (void*)(m_pool + 1) << endl;
		m_pool[0] = 1; // �ѵ�һ��λ�ñ��Ϊ�ѷ��䣬����һ��λ������������õ�
		return m_pool + 1; // ���ص�һ�����ڴ�ŵĵ�ַ
	}

	if (m_pool[9] == 0) {	// �жϵ�2��λ���Ƿ����
		cout << "�����˵ڶ����ڴ棺" << (void*)(m_pool + 9) << endl;
		m_pool[9] = 1; // �ѵ�9��λ�ñ��Ϊ�ѷ��䣬����һ��λ������������õ�
		return m_pool + 9; // ���ص�һ�����ڴ�ŵĵ�ַ
	}
	// �����������λ�ò����ã���ֱ����ϵͳ�����ڴ�
	void* ptr = malloc(size);
	cout << "���뵽��ϵͳ�ڴ�ĵ�ַ�ǣ�" << ptr << endl;
	return ptr;
}
//����ڴ�������ˣ����ֽ��������
//��1����չ�ڴ��
//��2��ֱ����ϵͳ�����ڴ�
//��3�����ؿյ�ַ

void CGirl::operator delete(void* ptr)
{
	if (ptr == 0) return; // ����������ĵ�ַΪ�գ�ֱ�ӷ���
	if (ptr == m_pool + 1) {	// ����������ĵ�ַ���ڴ���еĵ�һ��λ��
		cout << "�ͷ��˵�һ���ڴ�" << endl;
		m_pool[0] = 0;	// ����һ��λ����0����ʾ��һ���ڴ����
		return;
	}
	if (ptr == m_pool + 9) {	// ����������ĵ�ַ���ڴ�صĵڶ���λ��
		cout << "�ͷ��˵ڶ����ڴ�" << endl;
		m_pool[9] = 0;	// ����9��λ����0����ʾ��2���ڴ����
		return;
	}
	// ����������ĵ�ַ�������ڴ�أ������黹��ϵͳ
	free(ptr);
}

char* CGirl::m_pool = nullptr;

int main(void)
{
	// ��ʼ���ڴ��
	if (CGirl::initpool() == false) {
		cout << "��ʼ���ڴ��ʧ�ܡ�" << endl;
		return -1;
	}

	CGirl* g1 = new CGirl{ 20,87 };	//�����ڴ���еĵ�һ���ַ
	cout << "g1�ĵ�ַ��" << g1 <<"   ��ţ�"<<g1->m_bh<<"  xw="<<g1->m_xw << endl;

	CGirl* g2 = new CGirl{ 20,87 };		//�����ڴ���еĵ�2���ַ
	cout << "g2�ĵ�ַ��" << g2 << "   ��ţ�" << g2->m_bh << "  xw=" << g2->m_xw << endl;

	CGirl* g3 = new CGirl{ 20,87 };		//����ϵͳ�еĵ�ַ
	cout << "g3�ĵ�ַ��" << g3 << "   ��ţ�" << g3->m_bh << "  xw=" << g3->m_xw << endl;


	delete g1;	// �ͷ��ڴ�ص�һ���ַ

	CGirl* g4 = new CGirl{ 20,87 };		//�����ڴ���еĵ�һ���ַ
	cout << "g1�ĵ�ַ��" << g4 << "   ��ţ�" << g4->m_bh << "  xw=" << g4->m_xw << endl;

	delete g2;
	delete g3;
	delete g4;

	CGirl::freepool(); // �ͷ��ڴ��
}