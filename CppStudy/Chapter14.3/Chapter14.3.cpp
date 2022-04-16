#include <iostream>
#include <exception>
#include <string>
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};


int main()
{
	try
	{
		std::string s;
		s.resize(-1);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}