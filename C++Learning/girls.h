#pragma once
#ifndef __GIRLS__
#define __GIRLS__

#include <iostream>
#include "tools.h"
using namespace std;

extern int aa;	// 全局变量的声明
const int cc = 6; // 全局的const常量在头文件中定义，（const常量只在单个文件有效）

void print(int no, string str);

#endif
