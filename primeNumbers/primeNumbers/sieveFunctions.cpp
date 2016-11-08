#include "stdafx.h"
#include "sieveFunctions.h"

bool InsideValidRange(int upperBound)
{
	return ((upperBound >= MIN_PRIME) && (upperBound < MAX_BOUND_VALUE));
}

std::vector<bool> FillSieveVector(unsigned int upperBound)
{
	if (!InsideValidRange(upperBound))
		return {};

	std::vector<bool> sieve(++upperBound, true);
	sieve[0] = sieve[1] = false;
	for (unsigned int i = MIN_PRIME; i * i <= upperBound; ++i)
	{
		if (sieve[i])
		{
			for (unsigned int j = i * i; j <= upperBound; j += i)
			{
				sieve[j] = false;
			}
		}
	}
	return sieve;
}

std::set<int> GenerateSetOfPrimes(unsigned int upperBound)
{
	if (!InsideValidRange(upperBound))
		return {};

	std::vector<bool> sieve = FillSieveVector(upperBound);
	std::set<int> resultSetOfPrimes;
	resultSetOfPrimes.emplace_hint(resultSetOfPrimes.end(), MIN_PRIME);
	for (unsigned int i = MIN_PRIME + 1; i <= upperBound; i += MIN_PRIME)
	{
		if (sieve[i])
		{
			resultSetOfPrimes.emplace_hint(resultSetOfPrimes.end(), i);
		}
	}
	return resultSetOfPrimes;
}