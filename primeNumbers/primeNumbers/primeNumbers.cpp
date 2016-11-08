#include "stdafx.h"
#include "stdafx.h"
#include <iostream>

const unsigned NECESSARY_NUMBER_OF_ARGUMENTS = 2;
const unsigned MAX_BOUND_VALUE = 100000000;;

bool InsideValidRange(int upperBound)
{
	return ((upperBound > 1) && (upperBound < MAX_BOUND_VALUE));
}

int main(int argc, char * argv[])
{
	if (argc != NECESSARY_NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Invalid arguments count" << std::endl
			<< "Usage: primeNumbers.exe <upperBound>" << std::endl;
		return EXIT_FAILURE;
	}

	int upperBound = atoi(argv[1]);

	if (!InsideValidRange(upperBound))
	{
		std::cout << "Invalid argument" << std::endl
			<< "Upper bound in [2, " << MAX_BOUND_VALUE << "]" << std::endl;
	}

    return EXIT_SUCCESS;
}

