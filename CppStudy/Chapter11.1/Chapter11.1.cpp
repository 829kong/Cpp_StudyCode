#include <iostream>
using namespace std;

class Mother
{
private:
	int m_i;

public:
	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue() const
	{
		return m_i;
	}

	friend ostream& operator <<(ostream& out, const Mother& mother)
	{
		out << mother.m_i << endl;
		return out;
	}
};

class Child : public Mother
{
private:
	 double m_d;

public:
	void setValue(const double& d_in)
	{
		  m_i = d_in;
	}

	double getValue() const
	{
		return m_d;
	}

};

int main()
{
	Mother mother;
	mother.setValue(1024);
	cout << mother << endl;

	Child child;
	child.setValue(128);
	cout << child << endl;

	return 0;
}