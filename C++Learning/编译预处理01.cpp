#include <iostream>
using namespace std;

// 头文件只需包含一次

#include "boy.h"
#include "girl.h"

int main(void)
{
	CGirl g;
	CBoy b;
	b.m_name = "张三";
	g.m_name = "西施";

	return 0;
}