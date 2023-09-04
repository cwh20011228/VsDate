#pragma once
#include <iostream>
using namespace std;

void Swap(int a, int b);

template <typename T>		// 函数模板
void Swap(T a, T b)
{
	cout << "使用了函数模板" << endl;
}

template<>
void Swap(int a, int b);  // 具体化函数模板的声明
