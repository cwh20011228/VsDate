#include <iostream>
using namespace std;

//!定长数组容器 array
// 非通用数据类型参数可以有缺省值
// 模板中不能修改非通用类型参数的值

template <class T,int len=5>
class Array {
private:
	T items[len];	//数组元素
public:
	Array() { /*memset(items, 0, sizeof(items));*/ }	// 默认构造函数，初始化数组
	~Array() { }
	T& operator[](int ii) { return items[ii]; }	// 重载操作符[] ,可以修改数组中的元素
	const T& operator[](int ii) const { return items[ii]; }	// 重载操作符[] ，不能修改数组中的元素
};

//! string是类，里面有一个指向堆区内存的指针，

// 用类模板创建对象的时候，需要指定非通用类型参数的值

int main(void)
{
	Array<string,5> a1;
	Array<string, 6> a2;
	Array<string, 7> a3;
	//! Array<string,5>  Array<string, 6>  Array<string, 7>  这是三个类，程序的二进制代码会更大，运行的时候，占用的内存空间更多
	
	a1[0] = "西施"; 
	a1[1] = "西瓜";
	a1[2] = "张三";
	a1[3] = "李四";
	a1[4] = "王五";

	for (int i = 0; i < 5; i++)
	{
		cout << a1[i] << endl;
	}

	return 0;
}