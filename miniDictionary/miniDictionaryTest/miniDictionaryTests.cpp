#include "stdafx.h"
#include "../miniDictionary/dictionary_functions.h"
#include <sstream>

namespace
{
	std::string singleValueStr = "single value \n";
	Dictionary emptyDictionary = {};
	Dictionary filledDictionary = { {"dog", "собака"},
	                                {"cat", "кот"},
									{"database", "база данных"} };
	
	std::stringstream(emptySource);

	void VerifyFillDictionaryFrom(std::stringstream & source, const Dictionary & expectedDictionary)
	{
		Dictionary receiveDictionary;
		FillDictionaryFrom(source, receiveDictionary);
		BOOST_CHECK(receiveDictionary == expectedDictionary);
	}

	void VerifyGetTranslationOf(Dictionary & dictionary, const std::string & word, const std::string & expectedWord)
	{
		BOOST_CHECK(GetTranslationOf(word, dictionary) == expectedWord);
	}

	void VerifyInsertNewWordIntoDictionary(const std::string & word, const std::string & translation, const Dictionary & expectedDictionary)
	{
		Dictionary receiveDictionary;
		InsertNewWordIntoDictionary(word, translation, receiveDictionary);
		BOOST_CHECK(receiveDictionary == expectedDictionary);
	}
}

BOOST_AUTO_TEST_SUITE(FillDictionaryFrom_function)
    BOOST_AUTO_TEST_CASE(must_return_empty_map_if_input_is_empty)
    {
		VerifyFillDictionaryFrom(emptySource, emptyDictionary);
    }

	BOOST_AUTO_TEST_CASE(must_return_empty_map_if_input_contains_single_value)
	{
		std::stringstream singleValueSource;
		singleValueSource << "single value \n";
		VerifyFillDictionaryFrom(singleValueSource, emptyDictionary);
	}

	BOOST_AUTO_TEST_CASE(must_return_map_with_dictionary)
	{
		std::stringstream source;
		source << "dog" << std::endl << "собака" << std::endl << "cat" << std::endl << "кот" << std::endl << "database" << std::endl << "база данных" << std::endl;
		VerifyFillDictionaryFrom(source, filledDictionary);
	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(GetTranslationOf_function)
	BOOST_AUTO_TEST_CASE(must_return_empty_string_if_the_word_not_found)
	{
		VerifyGetTranslationOf(filledDictionary, "not in dictionary", "");
	}

    BOOST_AUTO_TEST_CASE(must_return_word_if_the_translation_exists)
	{
		VerifyGetTranslationOf(filledDictionary, "database", "база данных");
	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(InsertNewWordIntoDictionary_function)
	BOOST_AUTO_TEST_CASE(must_return_dictionary_with_new_filed)
	{
		Dictionary expectedDictionary = { {"moose", "лось"} };
		VerifyInsertNewWordIntoDictionary("moose", "лось", expectedDictionary);
	}
	BOOST_AUTO_TEST_CASE(must_ignore_empty_values)
	{
		Dictionary expectedDictionary = {};
		VerifyInsertNewWordIntoDictionary("", "", expectedDictionary);
	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(ProcessUserEntries_function)
BOOST_AUTO_TEST_CASE(must_print_translation_if_it_exists)
{
	std::stringstream expectedOutput, input, output;
	expectedOutput << ">собака";
	ProcessUserEntries(filledDictionary, "dog", input, output);
	BOOST_CHECK(output == expectedOutput);
}
BOOST_AUTO_TEST_CASE(must_ask_about_translation_if_it_not_found_and_insert_new_value_to_dictionary)
{

}
BOOST_AUTO_TEST_CASE(must_ask_about_translation_if_it_not_found_and_ignore_empty_string)
{

}
BOOST_AUTO_TEST_SUITE_END();