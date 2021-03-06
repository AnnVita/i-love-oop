#include "stdafx.h"
#include <iostream>
#include "sieveFunctions.h"

const unsigned NECESSARY_NUMBER_OF_ARGUMENTS = 2;

int main(int argc, char * argv[])
{
	if (argc != NECESSARY_NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Invalid arguments count" << std::endl
			<< "Usage: primeNumbers.exe <upperBound>" << std::endl;
		return EXIT_FAILURE;
	}

	int upperBound = atoi(argv[1]);

	if (!IsUpperBoundValid(upperBound))
	{
		std::cout << "Invalid argument" << std::endl
			<< "Upper bound in [" << MIN_PRIME << ", " << MAX_BOUND_VALUE << "]" << std::endl;
		return EXIT_FAILURE;
	}

	std::set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

	for (std::set<int>::iterator it = primeNumbers.begin(); it != primeNumbers.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

    return EXIT_SUCCESS;
}

