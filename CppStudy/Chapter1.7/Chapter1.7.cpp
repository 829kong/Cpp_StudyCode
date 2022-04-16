#include <iostream>
using namespace std;

int doSomething(int x)
{
	x = 123;
	cout << x << endl;
	return x;
}

int main() 
{
	int x = 0;

	cout << x << endl;
	int y = doSomething(x);
	cout << y << endl;

	return 0;
}