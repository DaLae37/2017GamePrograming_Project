#pragma once
#include<Windows.h>
#include<stdio.h>
#include <utility>
using namespace std;

class Mouse
{
public:
	pair<int, int> CheckMouse();
	Mouse();
	~Mouse();
};

