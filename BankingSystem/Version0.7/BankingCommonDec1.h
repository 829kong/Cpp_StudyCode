#pragma once
#include <iostream>
#include <string>
using namespace std;
const int Name_len = 10;
const double Percent = 0.01;

enum Choice
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	ALLSHOW,
	EXIT,
};

namespace Credit_Grade
{
	enum { Grade_A = 7, Grade_B = 4, Grade_C = 2, };
}
