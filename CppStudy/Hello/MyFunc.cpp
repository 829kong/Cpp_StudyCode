#include <iostream>
#include <chrono>
using namespace std;



void printArray(const int array[], const int length)
{
	for (int i = 0; i < length; ++i)
		cout << array[i] << " ";
	cout << endl;
}

void sortingArray(int array[], const int length)
{
	for (int startIndex = 0; startIndex<length-1;++startIndex)
	{
		int smallestIndex = startIndex;
		 
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[smallestIndex] > array[currentIndex])
			{
				smallestIndex = currentIndex;
			}
		}
		{
			int temp = array[smallestIndex];
			array[smallestIndex] = array[startIndex];
			array[startIndex] = temp;
		}
	}
}

void BubbulesortArray(int array[], const int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			int swap = 0;
			int next = j + 1;
			if ((array[j] > array[next]) && next != length)
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
		}
	}
}