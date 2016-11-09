#include "stdafx.h"
#include "../miniDictionary/dictionary_functions.h"
#include <sstream>

namespace
{
	Dictionary emptyDictionary = {};
	Dictionary filledDictionary = { {"dog", "������"},
	                                {"cat", "���"},
									{"database", "���� ������"} };

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
		std::stringstream emptySource;
		VerifyFillDictionaryFrom(emptySource, emptyDictionary);
    }

	BOOST_AUTO_TEST_CASE(must_return_empty_map_if_input_contains_single_value)
	{
		std::stringstream singleValueSource;
		singleValueSource << "single value" << std::endl;
		VerifyFillDictionaryFrom(singleValueSource, emptyDictionary);
	}

	BOOST_AUTO_TEST_CASE(must_return_map_with_dictionary)
	{
		std::stringstream source;
		source << "dog" << std::endl << "������" << std::endl << "cat" << std::endl << "���" << std::endl << "database" << std::endl << "���� ������" << std::endl;
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
		VerifyGetTranslationOf(filledDictionary, "database", "���� ������");
	}
BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(InsertNewWordIntoDictionary_function)
	BOOST_AUTO_TEST_CASE(must_return_dictionary_with_new_filed)//����������� ����
	{
		Dictionary expectedDictionary = { {"moose", "����"} };
		VerifyInsertNewWordIntoDictionary("moose", "����", expectedDictionary);
	}
	BOOST_AUTO_TEST_CASE(must_ignore_empty_values)
	{
		Dictionary expectedDictionary = {};
		VerifyInsertNewWordIntoDictionary("", "", expectedDictionary);
	}//�������� ����� � ����� ����������
BOOST_AUTO_TEST_SUITE_END();
