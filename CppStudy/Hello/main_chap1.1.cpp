#include <iostream>
#include <chrono>
#include "Simple.h"
using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;
	std::chrono::time_point<clock_t>start_time = clock_t::now();

public:
	void elaped()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();
		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};

int main()
{
	/* 3 5 2 1 4 */
	const int length = 10;
	int num_arr[length] = { 10,7,3,8,5,9,2,1,6,4 };
	

	Timer timer1;
	sortingArray(num_arr, length);
	printArray(num_arr, length);
	timer1.elaped();
	//sortingArray(num_arr, length);
	Timer timer2;
	BubbulesortArray(num_arr, length);
	printArray(num_arr, length);
	timer2.elaped();

	return 0;
}



