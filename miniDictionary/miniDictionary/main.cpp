#include "stdafx.h"
#include "dictionary_functions.h"

static const size_t NECESSARY_NUMBER_OF_ARGUMENTS = 2;
static const std::string EXIT_STRING = "...";

int main(int argc, char *argv[])
{
	if (argc == NECESSARY_NUMBER_OF_ARGUMENTS)
	{
		std::cout << "Invalid arguments count\n"
			<< "Usage: mini_dictionary.exe <dictionary file>\n";
		return EXIT_FAILURE;
	}
	std::string fileName = argv[1];

	Dictionary dictionary = GetDictionaryFrom(fileName);
	bool exit = false;
	std::string userEntries = "";

	std::cout << ">";

	while (getline(std::cin, userEntries) && userEntries != EXIT_STRING)
	{
		if (DictionaryContainsTranslationOf(userEntries, dictionary))
		{
			std::cout << GetTranslationOf(userEntries, dictionary);
		}
		else
		{
			std::cout << "Неизвестное слово" << userEntries << "Пожалуйста, введите перевод или пустую строку для отказа: /n" << ">";
			getline(std::cin, userEntries);
			if (!userEntries.empty())
			{
				InsertNewWordInto(userEntries, dictionary);
			}
			else
			{
				std::cout << "Слово "<< userEntries << "проигнорировано." << ">";
			}
		}
	} 

	return 0;
}

