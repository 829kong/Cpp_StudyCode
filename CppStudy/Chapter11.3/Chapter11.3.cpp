#include <iostream>
using namespace std;

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		:m_value(value)
	{
	}

	void print()
	{
		cout << "I am Base" << endl;
	}

	friend std::ostream operator <<(std::ostream& out, const Base& b)
	{

	}
};

class Derived :public Base
{
public:
	Derived(int value)
		:Base(value)
	{
	}
	void print()
	{
		cout << "I am Derived" << endl;
	}
	
};

int main()
{
	Base base(5);
	Derived derived(7);
	base.print();
	derived.print();


	return 0;
}