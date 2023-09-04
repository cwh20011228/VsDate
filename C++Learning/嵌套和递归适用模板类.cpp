#include <iostream>
using namespace std;

//! Ƕ�׺͵ݹ�����ģ���ࣺ��1�������������� ��2�� �����е�Ԫ�ؿ�����ջ ��3�� ջ�е�Ԫ�ؿ���������

//// ��������
//template <class T,int len>
//class Array {
//private:
//	T items[len];
//public:
//	Array(){ }
//	~Array(){ }
//	T& operator[](int ii) { return items[ii]; }
//	const T& operator[](int ii) const { return items[ii]; }
//};

template <class T>
class Stack {
private:
	T* items; // ջ����
	int stacksize; // ջʵ�ʴ�С
	int top; // ջ��ָ�루λ��ָ�룩
public:
	Stack(int size=3):stacksize{size},top{0}
	{
		items = new T[size];
	}

	~Stack()
	{
		delete[] items;
		items = nullptr;
	}


	Stack& operator=(const Stack& v)	// ���ظ�ֵ�������ʵ�����
	{
		if (this == &v) {
			return *this;
		}
		this->stacksize = v.stacksize;		// ջ��ʵ�ʴ�С
		this->top = v.top;		// ջ��ָ��
		if (v.items == nullptr) {	// ���Դ�����ָ��Ϊ�գ������Ŀ������ָ��
			delete[] items;
			items = nullptr;
		}
		else {
			delete[] items;		// �ͷ�ԭ�ڴ�
			items = new T[stacksize];	// ���·�������
			for (int ii = 0; ii < stacksize; ii++) {
				items[ii] = v.items[ii];
			}
		}
		return *this;
	}

	bool isempty()
	{
		if (top == 0){
			return true;
		}
		else {
			return false;
		}
	}

	bool isfull()
	{
		if (top == stacksize) {
			return true;
		}
		else {
			return false;
		}
	}

	bool push(const T& item)
	{
		if (top < stacksize) {
			items[top] = item;
			top = top + 1;
			return true;
		}
		else {
			return false;
		}
	}

	bool pop(T& item)
	{
		if (isempty() == false) {
			top = top - 1;
			item = items[top];
			return true;
		}
		else {
			return false;
		}

	}
};

// �䳤����
template <class T>
class Vector {
private:
	int len;
	T* items;
public:
	Vector(int llen=2):len{llen} 
	{
		items = new T[llen];
	}

	~Vector()
	{
		delete[] items;
		items = nullptr;
	}

	int size(void) const
	{
		return len;
	}

	void resize(int size)
	{
		if (size < len) {
			return;
		}
		else {
			T* tmp = new T[size];	// �������Ŀռ�
			for (int i = 0; i < len; i++) {
				tmp[i] = items[i];	// ��ԭ�������Ԫ�ظ��Ƶ�������
				// ������Ƶ����࣬��������ʹ���˶����ڴ棬�ʹ���ǳ�������⡣
				// Ӧ������������Ҫ��Stack����д�������캯���͸�ֵ����
			}
			delete[] items;	// �ͷ�ԭ��������
			items = tmp;	// ��ָ��ָ���´���������
			len = size;		// �������鳤��
		}
	}

	T& operator[](int ii)
	{
		if (ii >= len) {
			resize(ii + 10);
		}
		return items[ii];
	}

	const T& operator[](int ii) const
	{
		return items[ii];
	}

	Vector& operator=(const Vector& vv)
	{
		if (this == &vv) {	// ���Դ������Ŀ�������ͬһ����ֱ�ӷ���Ŀ�����
			return *this;
		}
		this->len = vv.len;
		if (vv.items == nullptr) {	// ���Դ�����ָ��Ϊnullptr�������Ŀ������ָ��
			delete[] items;
			items = nullptr;
		}
		else {
			delete[] items;	// �ͷ�ԭ�����ڴ�
			items = new T[len];	// ���·�������
			for (int i = 0; i < len; i++) {
				items[i] = vv.items[i];		// һһ���������е�Ԫ��
			}
			// ��memcpy
		}
		return *this;


	}
};


int main(void)
{
	// Vector������ȱʡֵ��2��Stack������ȱʡֵ��3

	//TODO: ������������ ջ���� ,�����е��������Ƕ�ά����
	//��1) ����Vector�����������е�Ԫ����Stack 
	Vector<Stack<string>> vs;  // C++11 ֮ǰ�� >> ֮��ӿո�
	//Stack<string> vs1[2]; // ջ����
	//string vs2[2][3];   // ջ��������һ���ַ������飬��˿������Ϊ һ����ά����

	//(2)�ֶ����������в������� 
	vs[0].push("��ʩ1"); vs[0].push("��ʩ2"); vs[0].push("��ʩ3");// vs�����еĵ�һ��ջ
	vs[1].push("����1"); vs[1].push("����2"); vs[1].push("����3");	//  vs�����еĵڶ���ջ
	vs[2].push("����1"); vs[2].push("����2"); vs[2].push("����3");

	//(3) ��Ƕ�׵�ѭ�����������е�������ʾ����
	for (int i = 0; i < vs.size(); i++)	// ����Vector����
	{
		while(vs[i].isempty() == false) {	// ����Stack����
				string item;
				vs[i].pop(item);
				cout << item << endl;
			}
	}

	cout << "-------------------------------------------------------" << endl;
	//TODO: ����Stack������ �����е�Ԫ����Vector<string>
	Stack<Vector<string>> sv;

	Vector<string> tmp;	// ջ��Ԫ�أ���ʱVector<string> ����
	// ��һ��ջԪ��
	tmp[0] = "��ʩ1";
	tmp[1] = "��ʩ2";
	sv.push(tmp);

	// �ڶ���ջԪ��
	tmp[0] = "����1";
	tmp[1] = "����2";
	sv.push(tmp);

	// ������ջԪ��
	tmp[0] = "����1";
	tmp[1] = "����2";
	tmp[2] = "����3";
	tmp[3] = "����4";
	sv.push(tmp);	// ��tmp��ջ

	//��Ƕ�׵�ѭ������sv�����е�������ʾ����
	while (sv.isempty() == false) {
		sv.pop(tmp);	// ��ջһ��Ԫ�أ�������ʱ������
		for (int i = 0; i < tmp.size(); i++) {		// ������ʱVector<string>��������ʾ�����е�ÿ��Ԫ�ص�ֵ
			cout << tmp[i] << "\t";
		}
		cout << endl;
	}

	cout << "-----------------------�ݹ�ʹ��ģ����--------------------------------" << endl;
	//TODO: ����Vector�����������е�Ԫ���� Vector<string>
	Vector<Vector<string>> vv;	// �ݹ�ʹ��ģ����

	vv[0][0] = "��ʩ1"; vv[0][1] = "��ʩ2"; vv[0][2] = "��ʩ3";
	vv[1][0] = "����1"; vv[1][1] = "����2";
	vv[2][0] = "����1"; vv[2][1] = "����2"; vv[2][2] = "����3"; vv[2][3] = "����4";

	// ��Ƕ�׵�ѭ������vv�����е�������ʾ����
	for (int i = 0; i < vv.size(); i++)
	{
		for(int j=0;j < vv[i].size();j++){
			cout << vv[i][j] << "  ";
		}
		cout << endl;
	}


	return 0;
}
