#pragma once

#include "Helper.h"

#include <unordered_map>

/*
*  2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

ANSWER: 232792560
*/

namespace Problem5
{
	int getSmallestMultiple(const std::vector<uint64_t>& numbers);

	int run()
	{
		/* NEW SOLUTION */
		std::vector<uint64_t> numbers;
		for (int i = 1; i <= 20; i++)
		{
			numbers.push_back(i);
		}

		return getSmallestMultiple(numbers);
		
		/* ORIGINAL SOLUTION */

		int start = 2520;

		while (true)
		{
			if ((start % 20 == 0)
				&& (start % 19 == 0)
				&& (start % 18 == 0)
				&& (start % 17 == 0)
				&& (start % 16 == 0)
				&& (start % 15 == 0)
				&& (start % 14 == 0)
				&& (start % 13 == 0)
				&& (start % 12 == 0)
				&& (start % 11 == 0))
			{
				break;
			}
			else
			{
				start += 2; // this could be 20 instead of 2?
			}
		}

		return start;
	};

	int getSmallestMultiple(const std::vector<uint64_t>& numbers)
	{
		printf("hello there from get smallest multiple\n");
		std::unordered_map<uint64_t, uint64_t> primeFactors;

		for (auto& it1 : numbers)
		{
			std::vector<uint64_t> factors =	Helper::getPrimeFactors(it1);

			std::unordered_map<uint64_t, uint64_t> currentPrimeFactors;


			// puts the factors of the number into an undordered map with the number of factors
			for (auto& it2 : factors)
			{
				if (currentPrimeFactors.find(it2) == currentPrimeFactors.end())
				{
					// it doesn't exist
					currentPrimeFactors.insert({ it2, 1 });
				}
				else
				{
					currentPrimeFactors.at(it2) = currentPrimeFactors.at(it2) + 1;
				}
			}

			for (auto& it3 : currentPrimeFactors)
			{
				if (primeFactors.find(it3.first) == primeFactors.end())
				{
					// it doesn't exist
					primeFactors.insert({ it3.first, it3.second });
				}
				else
				{
					if (it3.second > primeFactors.at(it3.first))
					{
						primeFactors.at(it3.first) = it3.second;
					}
				}
			}
		}

		uint64_t sum = 1;
		for (auto& it4 : primeFactors)
		{
			sum *= std::pow(it4.first, it4.second);
		}
		return sum;
	}
}

/*
* what numbers do we need to check?
* 20 -> rules out 2, 4, 5, 10
* 19 > prime
* 18 -> rules out 9, 3, 6
* 17 -> prime
* 16 -> rules out 4, 8, 2
* 15 -> rules out 5, 3
* 14- > rules out 7, 2
* 13 -> prime
* 12 -> 6, 2
* 11 -> prime

*/

/* BETTER SOLUTION
* To find the smallest multiple of a set of numbers, you're essentially calculating the **Least Common Multiple (LCM)** of those numbers. Here’s how you can do it:

### Steps to Calculate the LCM:
1. **List the Prime Factors:**
   - Find the prime factorization of each number in the set.

2. **Take the Highest Powers:**
   - For each prime number that appears in any of the factorizations, take the highest power of that prime from all the numbers.

3. **Multiply Them Together:**
   - Multiply these prime powers to get the LCM.

### Example:
For the numbers **12** and **18**:
- Prime factorization of 12 = \( 2^2 \times 3 \)
- Prime factorization of 18 = \( 2 \times 3^2 \)
- Take the highest powers: \( 2^2 \) and \( 3^2 \)
- Multiply them: \( 4 \times 9 = 36 \)

So, the LCM of 12 and 18 is **36**.

### Shortcut for Two Numbers:
For just two numbers, you can use the relationship:
\[
\text{LCM}(a, b) = \frac{|a \times b|}{\text{GCD}(a, b)}
\]
Where **GCD** is the greatest common divisor of the two numbers.

Want to explore an example or apply this to a specific set of numbers? Let me know!
*/