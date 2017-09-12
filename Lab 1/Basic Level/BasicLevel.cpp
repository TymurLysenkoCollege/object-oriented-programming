// BasicLevel.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

int* getNewArr(unsigned int size)
{
	int* tempArr = new int[size];

	for (int i = 0; i < size; ++i)
	{
		tempArr[i] = (rand() % 201) - 100;
	}

	return tempArr;
}

void outputArray(int* arr, unsigned int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n";
}

int minOf(int* arr, unsigned int size)
{
	int min = arr[0];

	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

void multiplyByMin(int* arr, unsigned int size)
{
	int min = minOf(arr, size);

	for (int i = 0; i < size; ++i)
	{
		arr[i] *= min;
	}
}

int main()
{
	srand(time(0));
	constexpr unsigned int arrSize = 5;

	std::cout << "Source arrays:\n";

	std::cout << "a:\n";
	int* a = getNewArr(arrSize);
	outputArray(a, arrSize);
	std::cout << "a length = " << arrSize << "\n";

	std::cout << "b:\n";
	int* b = getNewArr(arrSize);
	outputArray(b, arrSize);
	std::cout << "b length = " << arrSize << "\n";


	std::cout << "\nProcessed arrays:\n";
	
	std::cout << "a:\n";
	multiplyByMin(a, arrSize);
	outputArray(a, arrSize);

	std::cout << "b:\n";
	multiplyByMin(b, arrSize);
	outputArray(b, arrSize);

	delete[] a;
	delete[] b;
	system("pause");
    return 0;
}
