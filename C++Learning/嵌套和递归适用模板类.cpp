#include <iostream>
using namespace std;

//! 嵌套和递归适用模板类：（1）容器中有容器 （2） 数组中的元素可以是栈 （3） 栈中的元素可以是数组

//// 定长数组
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
	T* items; // 栈数组
	int stacksize; // 栈实际大小
	int top; // 栈顶指针（位置指针）
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


	Stack& operator=(const Stack& v)	// 重载赋值运算符，实现深拷贝
	{
		if (this == &v) {
			return *this;
		}
		this->stacksize = v.stacksize;		// 栈的实际大小
		this->top = v.top;		// 栈顶指针
		if (v.items == nullptr) {	// 如果源对象的指针为空，则清空目标对象的指针
			delete[] items;
			items = nullptr;
		}
		else {
			delete[] items;		// 释放原内存
			items = new T[stacksize];	// 重新分配数组
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

// 变长数组
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
			T* tmp = new T[size];	// 分配更大的空间
			for (int i = 0; i < len; i++) {
				tmp[i] = items[i];	// 把原来数组的元素复制到新数组
				// 如果复制的是类，并且类中使用了堆区内存，就存在浅拷贝问题。
				// 应该用深拷贝，因此要给Stack类重写拷贝构造函数和赋值函数
			}
			delete[] items;	// 释放原来的数组
			items = tmp;	// 将指针指向新创建的数组
			len = size;		// 更新数组长度
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
		if (this == &vv) {	// 如果源对象与目标对象是同一个，直接返回目标对象
			return *this;
		}
		this->len = vv.len;
		if (vv.items == nullptr) {	// 如果源对象的指针为nullptr，则清空目标对象的指针
			delete[] items;
			items = nullptr;
		}
		else {
			delete[] items;	// 释放原数组内存
			items = new T[len];	// 重新分配数组
			for (int i = 0; i < len; i++) {
				items[i] = vv.items[i];		// 一一复制数组中的元素
			}
			// 用memcpy
		}
		return *this;


	}
};


int main(void)
{
	// Vector容器的缺省值是2，Stack容器的缺省值是3

	//TODO: 数组容器中有 栈容器 ,容器中的容器就是二维容器
	//（1) 创建Vector容器，容器中的元素用Stack 
	Vector<Stack<string>> vs;  // C++11 之前， >> 之间加空格
	//Stack<string> vs1[2]; // 栈数组
	//string vs2[2][3];   // 栈本身又是一个字符串数组，因此可以理解为 一个二维数组

	//(2)手动的往容器中插入数据 
	vs[0].push("西施1"); vs[0].push("西施2"); vs[0].push("西施3");// vs容器中的第一个栈
	vs[1].push("西瓜1"); vs[1].push("西瓜2"); vs[1].push("西瓜3");	//  vs容器中的第二个栈
	vs[2].push("张三1"); vs[2].push("张三2"); vs[2].push("张三3");

	//(3) 用嵌套的循环，把容器中的数据显示出来
	for (int i = 0; i < vs.size(); i++)	// 遍历Vector容器
	{
		while(vs[i].isempty() == false) {	// 遍历Stack容器
				string item;
				vs[i].pop(item);
				cout << item << endl;
			}
	}

	cout << "-------------------------------------------------------" << endl;
	//TODO: 创建Stack容器， 容器中的元素用Vector<string>
	Stack<Vector<string>> sv;

	Vector<string> tmp;	// 栈的元素，临时Vector<string> 容器
	// 第一个栈元素
	tmp[0] = "西施1";
	tmp[1] = "西施2";
	sv.push(tmp);

	// 第二个栈元素
	tmp[0] = "西瓜1";
	tmp[1] = "西瓜2";
	sv.push(tmp);

	// 第三个栈元素
	tmp[0] = "王五1";
	tmp[1] = "王五2";
	tmp[2] = "王五3";
	tmp[3] = "王五4";
	sv.push(tmp);	// 将tmp入栈

	//用嵌套的循环，把sv容器中的数据显示出来
	while (sv.isempty() == false) {
		sv.pop(tmp);	// 出栈一个元素，放在临时容器中
		for (int i = 0; i < tmp.size(); i++) {		// 遍历临时Vector<string>容器，显示容器中的每个元素的值
			cout << tmp[i] << "\t";
		}
		cout << endl;
	}

	cout << "-----------------------递归使用模板类--------------------------------" << endl;
	//TODO: 创建Vector容器，容器中的元素是 Vector<string>
	Vector<Vector<string>> vv;	// 递归使用模板类

	vv[0][0] = "西施1"; vv[0][1] = "西施2"; vv[0][2] = "西施3";
	vv[1][0] = "西瓜1"; vv[1][1] = "西瓜2";
	vv[2][0] = "冰冰1"; vv[2][1] = "冰冰2"; vv[2][2] = "冰冰3"; vv[2][3] = "冰冰4";

	// 用嵌套的循环，把vv容器中的数据显示出来
	for (int i = 0; i < vv.size(); i++)
	{
		for(int j=0;j < vv[i].size();j++){
			cout << vv[i][j] << "  ";
		}
		cout << endl;
	}


	return 0;
}
