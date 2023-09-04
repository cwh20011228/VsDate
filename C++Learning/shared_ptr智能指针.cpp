#include <iostream>
#include <memory>
using namespace std;

class AA {
public:
	string m_name;
	AA(){ cout << "调用了构造函数AA()" << endl; }
	AA(const string& name):m_name(name)
	{ 
		cout << "调用了构造函数AA(const string& name):" << m_name << endl; 
	
	}
	~AA(){ cout << "调用了析构函数~AA()：" << m_name << endl; }
};

int main(void)
{
	shared_ptr<AA> pa0 = make_shared<AA>("西施a"); // 初始化西施a
	
	shared_ptr<AA> pa1 = pa0;	// 用已存在的shared_ptr拷贝构造，计数加1
	shared_ptr<AA> pa2 = pa0;	// 用已存在的shared_ptr拷贝构造，计数加1
	cout << "pa0.use_count()=" << pa0.use_count() << endl;	//值为3

	cout << endl;
	shared_ptr<AA> pb0 = make_shared<AA>("西施b");	// 初始化西施b
	shared_ptr<AA> pb1 = pb0;	// 用已存在的shared_ptr拷贝构造，计数加1
	shared_ptr<AA> pb2 = pb0;	// 用已存在的shared_ptr拷贝构造，计数加1
	cout << "pb0.use_count()=" << pb0.use_count() << endl;	// 值为3
	cout << endl;

	pb2 = pa2;	// 赋值，将pb2也指向了西施a,所以指向西施a的shared_ptr对象加1，指向西施b的shared_ptr对象减1
	/*pb1 = pa2;
	pb0 = pa2; //! pb0指向西施a后，西施b没有 shared_ptr与之关联， 则释放西施b这个资源 */

	//TODO: 指向资源的指针多了一个，引用计数就加1；指向资源的指针少了一个，引用计数就减1；如果引用计数为0了，就释放该资源。
	cout << "pa0.use_count()=" << pa0.use_count() << endl;	//值为4
	cout << "pb0.use_count()=" << pb0.use_count() << endl;	//值为2
	cout << endl;

}