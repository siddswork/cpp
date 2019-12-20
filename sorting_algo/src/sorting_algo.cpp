/*
 * sorting_algo.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: sidd
 */

#include <iostream>
#include <chrono>
#include <random>

using namespace std;

const int SIZE = 100;

void fillArrayRandomly(int array1[], int array2[])
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	minstd_rand0 generator (seed); // minstd_rand0 is a standard linear_congruential_engine
	cout << "Filling Array with random number between " << generator.min() << " and " << 10000 << endl;
	for(int i = 0 ; i < SIZE; i++)
	{
		array1[i] = generator()%10000;
		array2[i] = array1[i];
	}
}

void printArray(int array[], string prefix)
{
	cout << prefix << " [";
	for(int i = 0; i < SIZE; i++)
	{
		if(i%10) cout << ", ";
		else cout << endl << "\t";
		cout << array[i];
	}
	cout << " ]" << endl;
}

void bubbleSort(int array [])
{
	unsigned start = std::chrono::system_clock::now().time_since_epoch().count();
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE - i - 1; j++)
		{
			if(array[j] < array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	unsigned end = std::chrono::system_clock::now().time_since_epoch().count();
	cout << "Time taken to complete bubble sort : " << end - start << endl;
}
int main()
{
	int array1[SIZE];
	int array2[SIZE];
	fillArrayRandomly(array1, array2);
	printArray(array1, "Unsorted array");
	printArray(array2, "Unsorted array");

	bubbleSort(array1);
	printArray(array1, "Sorted array");

	printArray(array2, "Unsorted array");
}


