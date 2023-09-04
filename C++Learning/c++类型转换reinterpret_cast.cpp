#include <iostream>
using namespace std;

void  func(void* ptr)
{
	//TODO: (2)将指针（引用）转换为整型变量。整型与指针占用的字节数必须一致，否则转换可能损失精度
	long long a = reinterpret_cast<long long>(ptr);
	cout << "a=" << a << endl;
}




int main(int argc,char* argv[])
{
	
	long long ii = 3;
	int aa = 10;

	//TODO: 应用场景：（1）reinterpret_cast改变指针或引用的类型
	double* pd1 = reinterpret_cast<double*>(&aa);

	
	//TODO: (3) 将一个整型变量转换为指针（引用）
	func(reinterpret_cast<void*>(ii));
}
