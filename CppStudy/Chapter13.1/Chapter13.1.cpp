#include <iostream>

template <typename T>

T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


int main() 
{
	std::cout << getMax(1.2, 2.3) << std::endl;
	return 0;
}