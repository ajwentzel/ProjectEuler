#include "Helper.h"

#include <iostream>

bool Helper::isPrime(int64_t number)
{
	if (number == 1) return true;

	int64_t half = sqrt(number);

	for (int64_t i = 2; i < half + 1; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

std::vector<uint64_t> Helper::getPrimeFactors(uint64_t number)
{
	std::cout << "THE NUMBER TO GET THE PRIME FACTORS IS: " << number << std::endl;
	std::vector<uint64_t> factors;

	if (number <= 1)
	{
		factors.push_back(number);
		return factors;
	}

	

	int64_t start = 2;
	int64_t currentFactor = start;

	bool finished = false;


	while (!finished)
	{
		if (!(number % currentFactor))
		{
			factors.emplace_back(currentFactor);
			number = number / currentFactor;
			currentFactor = start;

			if (isPrime(number))
			{
				finished = true;
				factors.emplace_back(number);
			}

		}
		else
		{
			currentFactor++;
		}
	}

	return factors;
}
