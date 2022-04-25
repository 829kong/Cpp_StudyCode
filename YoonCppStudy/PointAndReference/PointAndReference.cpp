#include <iostream>
using namespace std;

class A
{
private:
	int m_num;
public:
	A(int num)
		:m_num(num)
	{}
	void printA()
	{
		cout << "Class A狼 林家: " << this << endl;
	}

	A* returnA()
	{
		return this;
	}
};

int main()
{
	A a(1);
	cout << "a狼 林家蔼: " << &a << endl;
	a.printA();
	cout << "a.returnA(): " << a.returnA() << endl;

	int num1 = 1;
	int* p = &num1;
	int& ref1 = *p;
	int *(& ref2) = p;

	cout << &num1 << endl;
	cout << *p << endl;
	cout << p << endl;
	cout << ref2 << endl;
	cout << &ref2 << endl;
	return 0;
}