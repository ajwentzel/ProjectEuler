#pragma once

#include <vector>

/*

**The prime factors of 13195 are 5, 7, 13, and 29.**

**What is the largest prime factor of the number 600851475143?**
*/

namespace Problem3
{
	bool isPrime(int64_t number);


	int run()
	{
		int64_t number = 600851475143;

		int64_t start = 2;
		int64_t currentFactor = start;
		std::vector<int64_t> factors;

		bool finished = false;
		

		while (!finished)
		{
			int64_t result = number % currentFactor;

			if (!result)
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

		/*
		* get the max number of factors
		*/
		auto maxFactor = *std::max_element(factors.begin(), factors.end());
		return maxFactor;


	}

	bool isPrime(int64_t number)
	{
		if (number == 1) return true;

		int64_t half = sqrt(number);
		//printf("THE SQRT OF %i is %i\n", number, half);

		for (int64_t i = 2; i < half+ 1; i++)
		{
			if (number % i == 0)
			{
				return false;
			}
		}

		return true;
	}
}

/*
* create a vector of factors
* starting at 2, divide the main number until it works
* save that factor
* start at 2 again with the result
* sort the resulting vector until we get the biggest factor
*/