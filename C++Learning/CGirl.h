#pragma once

#include <iostream>
using namespace std;

class CGirl {
public:
	void show();
	void SetValue(string name, int age, int sex);
	CGirl();
	CGirl(string name);
	CGirl(string name, int age);
	~CGirl();
	int GetAge();
	void SetAge(int age);
	void InitData();
	string m_name;
private:
	int m_age = 3;
	int m_sex=girl;
	enum{girl=1,boy=2};
};
