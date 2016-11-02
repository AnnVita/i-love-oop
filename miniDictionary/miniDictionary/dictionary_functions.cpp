#include "stdafx.h"
#include "dictionary_functions.h"

void ProcessProgramLoop(Dictionary & dictionary, std::istream & input, std::ostream & output)
{
	std::string userEntries = "";

	output << ">";

	while (getline(input, userEntries) && userEntries != EXIT_STRING)
	{
		ProcessUserEntries(dictionary, userEntries, input, output);
		output << ">";
	}
}

void ProcessUserEntries(Dictionary & dictionary, const std::string & userEntries, std::istream & input, std::ostream & output)
{
	std::string translation = GetTranslationOf(userEntries, dictionary);
	if (!translation.empty())
	{
		output << GetTranslationOf(userEntries, dictionary) << std::endl;
	}
	else
	{
		output << "Неизвестное слово '" << userEntries << "'. Пожалуйста, введите перевод или пустую строку для отказа:" << std::endl << ">";
		getline(std::cin, translation);
		if (!translation.empty())
		{
			InsertNewWordIntoDictionary(userEntries, translation, dictionary);
			output << "Слово '" << userEntries << "' сохранено как '" << translation << "'." << std::endl;
		}
		else
		{
			output << "Слово '" << userEntries << "' проигнорировано." << std::endl;
		}
	}
}

bool GetDictionaryFromFile(const std::string & fileName, Dictionary & newDictionary)
{
	std::ifstream input(fileName);
	if (input.is_open())
	{
		FillDictionaryFrom(input, newDictionary);
		input.close();
		return true;
	}
	return false;
}

void FillDictionaryFrom(std::istream & input, Dictionary & newDictionary)
{
	std::string word, translation;
	while (getline(input, word) && getline(input, translation))
	{
		newDictionary.insert(make_pair(word, translation));
	}
}

std::string GetTranslationOf(const std::string & word, const Dictionary & dictionary)
{
	auto result = dictionary.find(word);
	return (result != dictionary.end()) ? result->second : "";
}

void InsertNewWordIntoDictionary(const std::string & word, const std::string & translation, Dictionary & dictionary)
{
	if (!word.empty() && !translation.empty())
		dictionary.insert(std::make_pair(word, translation));
}


void ProcessDictionaryRetention(Dictionary & dictionary, const std::string & fileName, std::istream & input, std::ostream & output)
{
	char userAnswer;
	output << "Сохранить изменения словаря? (Y/y)" << std::endl;
	input >> userAnswer;
	if ((userAnswer == 'Y') || (userAnswer == 'y'))
	{
		std::ofstream destination(fileName);
		SaveDictionaryTo(destination, dictionary);
		output << "Изменения сохранены." << std::endl;
	}
	else
	{
		output << "Изменения словаря не сохранены." << std::endl;
	}
}

void SaveDictionaryTo(std::ostream & destination, Dictionary & dictionary)
{
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		destination << it->first << std::endl << it->second << std::endl;
	}
}