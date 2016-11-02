#include "stdafx.h"
#include "dictionary_functions.h"
#include <Windows.h>

static const size_t NECESSARY_NUMBER_OF_ARGUMENTS = 2;

int main(int argc, char *argv[])
{
	if (argc != NECESSARY_NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: mini_dictionary.exe <dictionary file>\n";
		return EXIT_FAILURE;
	}

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fileName = argv[1];

	Dictionary dictionary;
	if (!GetDictionaryFromFile(fileName, dictionary))
	{
		std::cout << "Unable to open input file" << std::endl;
		return EXIT_FAILURE;
	}

	ProcessProgramLoop(dictionary, std::cin, std::cout);
	ProcessDictionaryRetention(dictionary, fileName, std::cin, std::cout);

	return 0;
}

