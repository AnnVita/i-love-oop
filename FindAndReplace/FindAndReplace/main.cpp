#include "stdafx.h"
#include "FindAndReplace.h"

static const size_t NECESSARY_NUMBER_OF_ARGUMENTS = 3;

int main(int argc, char * argv[])
{
	if (argc != NECESSARY_NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: FindAndReplace.exe <search-string> <replace-string>\n";
		return EXIT_FAILURE;
	}

	if (strlen(argv[1]) == 0)
	{
		std::cout << "Searching string cannot be empty!\n";
		return EXIT_FAILURE;
	}

	const std::string searchString = argv[1];
	const std::string replaceString = argv[2];
	std::string stringToChange;

	getline(std::cin, stringToChange);

	stringToChange = FindAndReplace(stringToChange, searchString, replaceString);

	std::cout << stringToChange << '\n';
	
	return EXIT_SUCCESS;
}