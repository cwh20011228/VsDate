#include <iostream>
using namespace std;

int main(void)
{
	struct st_girl {
		int bh;
		char name[30];
		bool yz;
		double weight;
		string memo;
	}girl;

	cout << "超女结构体的大小：" << sizeof(st_girl) << endl;

	string buffer;	// 创建一个长度为0的string容器buffer

	// 生成10名超女的信息，存入buffer中
	for (int ii = 1; ii <= 10; ii++)
	{
		// 对超女对象进行赋值
		memset(&girl, 0, sizeof(girl));
		girl.bh = ii;
		sprintf(girl.name, "西施%02d", ii);
		girl.yz = true;
		girl.weight = 48.5 + ii;
		girl.memo = "中国历史第一美女";

		// 把超女结构追加到buffer
		buffer.append((char*)&girl, sizeof(st_girl));
	}

	cout << "buffer.capacity()=" << buffer.capacity() << endl;	// 显示容量
	cout << "buffer.size()=" << buffer.size() << endl;		// 显示实际大小

	// 用一个循环，把buffer容器中的全部数据取出来
	for  (int ii = 0; ii < buffer.size()/sizeof(st_girl);  ii++)
	{
		memset(&girl, 0, sizeof(st_girl));

		// 把容器中的数据复制到找女结构体
		//memcpy(&girl, buffer.data()+ii*sizeof(st_girl), sizeof(st_girl));
		buffer.copy(reinterpret_cast<char*>(&girl), sizeof(st_girl), ii * sizeof(st_girl));
		//显示超女结构体成员的值
		cout << "bh=" << girl.bh << "   name=" << girl.name << "   yz=" << girl.yz 
			 << "   weight=" << girl.weight << "   memo=" << girl.memo << endl;
	}
}