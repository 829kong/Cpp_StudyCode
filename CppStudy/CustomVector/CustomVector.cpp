#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
using namespace std;

class CustomVector
{
public:
	unsigned n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;
		init(_n_data, _init);
	}

	CustomVector(CustomVector& l_input)
	{
		cout << "Copy constructor" << endl;
		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector&& r_input)
	{
		cout << "Move constructor" << endl;
		
		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}

	void init(const unsigned& _n_data, const int& _init=0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

int main()
{
	CustomVector my_vec(10, 1024);
	CustomVector temp(my_vec);

	cout << my_vec.n_data << endl;
}