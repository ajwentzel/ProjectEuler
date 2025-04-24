#pragma once

#include "../../Helper.h"

namespace Problem7
{
	int run()
	{
		int i = 0;
		int j = 0;
		int prime = 0;
		while (i < 10001)
		{
			if (Helper::isPrime(j++))
			{
				prime = j - 1;
				std::cout << "PRIME NUMBER " << i << " IS " << prime << std::endl;
				i++;
			}
		}

		return prime;
	}
}