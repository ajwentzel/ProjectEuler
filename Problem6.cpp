#include "Problem6.h"

#include <math.h>
#include <iostream>

uint64_t Problem6::run(int64_t start, int64_t end)
{
	int32_t difference = (int32_t)end - (int32_t)start;
	if (difference <= 0)
	{
		return 0;
	}

	int64_t sumOfSquares = 0;
	int64_t squareOfSums = 0;

	for (int64_t i = start; i <= end; i++)
	{
		sumOfSquares += pow(i, 2);
		squareOfSums += i;
	}

	std::cout << "sum: " << squareOfSums << std::endl;

	squareOfSums = pow(squareOfSums, 2);

	std::cout << "sqaure of sum: " << squareOfSums << std::endl;
	std::cout << "sum of squares: " << sumOfSquares << std::endl;

	return abs(sumOfSquares - squareOfSums);
}

