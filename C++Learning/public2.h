#pragma once
#ifndef __PUBLIC2__
#define __PUBLIC2__

namespace aa
{
	extern int ab;		//全局变量

	void func1();		// 全局函数的声明
}

namespace bb
{
	extern int ab;		//全局变量

	void func1();		// 全局函数的声明

	class A1
	{
	public:
		void show();	// 类的成员函数
	};

	
}

#endif