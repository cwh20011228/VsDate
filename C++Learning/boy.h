#pragma once
#ifndef __BOY__
#define __BOY__
#include <iostream>
using namespace std;

#include "girl.h"

class CGirl;

class CBoy {
public:
	string m_name;
	CGirl* boy;
};

#endif
