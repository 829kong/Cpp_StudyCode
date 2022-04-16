#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Mystruct
{

};

void func(Mystruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(Mystruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

void func(Mystruct s)
{
	cout << "Pass by Value" << endl;
}

template<typename T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));
}

int main()
{
	Mystruct s;
	func(s);
	func(Mystruct());
	//return 0;
}