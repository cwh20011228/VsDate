#pragma once
#include <iostream>
using namespace std;

void Swap(int a, int b);

template <typename T>		// ����ģ��
void Swap(T a, T b)
{
	cout << "ʹ���˺���ģ��" << endl;
}

template<>
void Swap(int a, int b);  // ���廯����ģ�������
