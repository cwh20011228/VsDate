#include <iostream>
using namespace std;

template <class T>
class Vector {
private:
	int m_len;	//����Ԫ�صĸ���
	T* items;	// ����Ԫ��
public:
	Vector(int len=10);
	~Vector();
	T& operator[](int ii);
	const T& operator[](int ii) const;
	void resize(int size); // ��չ������ڴ�ռ�
	int size() const;	// ��ȡ���鳤��
};

template <class T>
Vector<T>::Vector(int len):m_len{len}
{
	items = new T[m_len];
}

template <class T>
Vector<T>::~Vector()
{
	delete[] items;
	items = nullptr;
}

template <class T>
T& Vector<T>::operator[](int ii)
{
	if (ii >= m_len) {	// �������������±곬�������鳤�ȣ�����������
		resize(ii+10);
	}
	return items[ii];
}

template <class T>
const T& Vector<T>::operator[](int ii) const
{
	return items[ii];
}

template <class T>
void Vector<T>::resize(int size)
{
	if (size <= m_len) {
		return;
	}
	else {
		T* tmp = new T[size];	// ���������ڴ�ռ�
		for (int i = 0; i < size; i++) {
			tmp[i] = items[i];		// ��ԭ�����鸴�Ƶ�������
		}
		delete[] items;	// �ͷ�ԭ��������
		items = tmp; // ������ָ��ָ��������
		m_len = size; // ���鳤�ȸ���
	}
}

template <class T>
int Vector<T>::size() const
{
	return m_len;
}


int main(void)
{
	Vector<int> a1(5);
	/*a1[0] = "��ʩ";
	a1[1] = "����";
	a1[2] = "����";
	a1[3] = "����";
	a1[4] = "����";*/

	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;
	a1[4] = 5;
	for (int i = 0; i < 5; i++)
	{
		cout << a1[i] << endl;
	}
	return 0;
}