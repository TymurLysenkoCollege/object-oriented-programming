// Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int** createMatrix(const unsigned int height, const unsigned int width)
{
	
	int** matrix = new int*[height];

	for (int i = 0; i < height; ++i)
	{
		int* arr = new int[width];

		for (int j = 0; j < width; ++j)
		{
			std::cout << "matrix[" << i << "][" << j << "] = ";
			std::cin >> arr[j];
		}

		matrix[i] = arr;
	}

	return matrix;
}

void outputMatrix(const int** matrix
                , const unsigned int height, const unsigned int width)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << matrix[i][j] << "\t";
		}

		std::cout << "\n";
	}
}

void swapLines(int** matrix, const unsigned int i, const unsigned int k
              , const unsigned int height)
{
  if (i >= height || k >= height)
  {
    std::cout << "Unable to swap " << i << " and " << k << " lines\n";
    return;
  }

  int* tempArr = matrix[i];

  matrix[i] = matrix[k];
  matrix[k] = tempArr;
}

void swapColumns(int** matrix, const unsigned int l, const unsigned int j
               , const unsigned int height, const unsigned int width)
{
  if (l >= width || j >= width)
  {
    std::cout << "Unable to swap " << l << " and " << j << " columns\n";
    return;
  }

  int* tempCol = new int[height];

  for (int i = 0; i < height; i++)
  {
    tempCol[i] = matrix[i][l];
    matrix[i][l] = matrix[i][j];
    matrix[i][j] = tempCol[i];
  }
}

int main()
{
	unsigned int height = 0, width = 0;
	std::cout << "Enter array's size:\n";
	std::cin >> height >> width;

	int** matrix = createMatrix(height, width);
	std::cout << "\nSource matrix:\n";
	outputMatrix((const int**)(matrix), height, width); // TODO: Can't pass matrix due to cast

	unsigned int i = 0, k = 0;
	std::cout << "Enter line numbers you want to swap:\n";
  std::cin >> i >> k;
  swapLines(matrix, i, k, height);
  std::cout << "\nMatrix with swapped " << i
            << " and " << k << " lines:\n";
  outputMatrix((const int**)(matrix), height, width);

  std::cout << "Enter column numbers you want to swap:\n";
  std::cin >> i >> k;
  swapColumns(matrix, i, k, height, width);
  std::cout << "\nMatrix with swapped " << i
    << " and " << k << " columns:\n";
  outputMatrix((const int**)(matrix), height, width);

	system("pause");
    return 0;
}
