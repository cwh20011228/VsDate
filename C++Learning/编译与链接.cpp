#include "tools.h"
#include "girls.h"

// 只有源文件才能编译，
// 链接：将编译后的目标文件，以及库文件链接在一起，形成可执行程序
// c++编译的时候，只检查名称是否合法,不检查名称的定义（实体）是否存在，链接的时候才会寻找名称的定义，如果找不到，就报错了
int main(void)
{
	cout << "max(5,8)="<<max(5, 8) << endl;
	cout << "min(5,8)=" << min(5, 8) << endl;

	print(3, "我是一只傻傻鸟");

	
	cout << "aa=" << aa << endl;
	cout << "bb=" << bb << endl;
	cout << "cc=" << cc << endl;

	return 0;
}