#include "stdafx.h"
#include "../FindAndReplace/FindAndReplace.h"

namespace
{
	void VerifyFindAndReplace(const std::string &subject, const std::string &search, const std::string &replace, const std::string &expectedTrimmedString)
	{
		BOOST_CHECK(FindAndReplace(subject, search, replace) == expectedTrimmedString);
	}
}

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)
    BOOST_AUTO_TEST_CASE(must_convert_empty_string_to_empty_string)
    {
	    VerifyFindAndReplace("", "", "", "");
    }

	BOOST_AUTO_TEST_CASE(if_in_input_an_empty_string_must_return_empty_string)
	{
		VerifyFindAndReplace("", "smth", "empty", "");
	}

	BOOST_AUTO_TEST_CASE(must_replace_word_by_empty_string)
	{
		VerifyFindAndReplace("input string", "string", "", "input ");
	}

	BOOST_AUTO_TEST_CASE(must_replace_symbol_by_another_symbol)
	{
		VerifyFindAndReplace("input string", "i", "l", "lnput strlng");
	}

	BOOST_AUTO_TEST_CASE(must_replace_substring_by_another_string)
	{
		VerifyFindAndReplace("input string", "input", "output", "output string");
	}

	BOOST_AUTO_TEST_CASE(must_replace_substring_by_another_string5)
	{
		VerifyFindAndReplace("ma", "ma", "mama", "mama");
	}

	BOOST_AUTO_TEST_CASE(must_replace_substring_by_another_string4)
	{
		VerifyFindAndReplace("mama", "ma", "mama", "mamamama");
	}

	BOOST_AUTO_TEST_CASE(must_replace_substring_by_another_string3)
	{
		VerifyFindAndReplace("mam", "ma", "mama", "mamam");
	}

	BOOST_AUTO_TEST_CASE(must_replace_substring_by_another_string2)
	{
		VerifyFindAndReplace("maa", "ma", "m", "ma");
	}

BOOST_AUTO_TEST_SUITE_END()
