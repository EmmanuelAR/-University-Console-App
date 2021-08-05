#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class hora
{

private:
	int inicio;
	int final;
	string amPm;
public:
	hora(int, int, string);
	~hora();
};

