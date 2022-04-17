#include <iostream>
using namespace std;

class First
{
public:
	void firstFunc() { cout << "FirstFunc" << endl; }
	virtual void simpleFunc() { cout << "First's simpleFunc()" << endl; }
};

class Second : public First
{
public:
	void secondFunc() { cout << "SecondFunc" << endl; }
	virtual void simpleFunc() { cout << "Second's simpleFunc" << endl; }
};

class Third : public Second
{
public:
	void thirdFunc() { cout << "ThirdFunc" << endl; }
	virtual void simpleFunc() { cout << "Third's simpleFunc" << endl; }
};

int main() 
{
	Third obj;
	obj.firstFunc();
	obj.secondFunc();
	obj.thirdFunc();
	obj.simpleFunc();

	Second& sref = obj;
	sref.firstFunc();
	sref.secondFunc();
	sref.simpleFunc();

	First& fref = obj;
	fref.firstFunc();
	fref.simpleFunc();
	return 0;
}