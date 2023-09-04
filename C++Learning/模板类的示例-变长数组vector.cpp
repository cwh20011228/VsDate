#include <iostream>
using namespace std;

template <class T>
class Vector {
private:
	int m_len;	//数组元素的个数
	T* items;	// 数组元素
public:
	Vector(int len=10);
	~Vector();
	T& operator[](int ii);
	const T& operator[](int ii) const;
	void resize(int size); // 扩展数组的内存空间
	int size() const;	// 获取数组长度
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
	if (ii >= m_len) {	// 如果访问数组的下标超出了数组长度，就扩充数组
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
		T* tmp = new T[size];	// 分配更大的内存空间
		for (int i = 0; i < size; i++) {
			tmp[i] = items[i];		// 把原来数组复制到新数组
		}
		delete[] items;	// 释放原来的数组
		items = tmp; // 让数组指针指向新数组
		m_len = size; // 数组长度更新
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
	/*a1[0] = "西施";
	a1[1] = "西瓜";
	a1[2] = "张三";
	a1[3] = "李四";
	a1[4] = "王五";*/

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