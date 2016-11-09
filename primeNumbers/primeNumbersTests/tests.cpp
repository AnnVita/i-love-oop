#include "stdafx.h"
#include "..\primeNumbers\sieveFunctions.h"

BOOST_AUTO_TEST_SUITE(FillSieveVector_function)

	BOOST_AUTO_TEST_CASE(must_make_empty_vector_if_upperBound_is_unavalid)
	{
		std::vector<bool> expectedResult{};
		std::vector<bool> result = FillSieveVector(0);

		BOOST_CHECK(result == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(must_make_vector_of_primes_in_first_seven_numbers)
	{
		std::vector<bool> expectedResult{ 0, 0, 1, 1, 0, 1, 0, 1};
		std::vector<bool> result = FillSieveVector(7);

		BOOST_CHECK(result == expectedResult);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)
	BOOST_AUTO_TEST_CASE(must_make_empty_set)
	{
		std::set<int> expectedResult{};
		std::set<int> result = GeneratePrimeNumbersSet(1);

		BOOST_CHECK(result == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(must_make_single_value_set_when_upperBound_is_2)
	{
		std::set<int> expectedResult{ 2 };
		std::set<int> result = GeneratePrimeNumbersSet(2);

		BOOST_CHECK(result == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(must_make_set_when_upperBound_is_3)
	{
		std::set<int> expectedResult{ 2, 3 };
		std::set<int> result = GeneratePrimeNumbersSet(3);

		BOOST_CHECK(result == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(must_make_empty_set_when_upperBound_more_than_max_value)
	{
		std::set<int> expectedResult{};
		std::set<int> result = GeneratePrimeNumbersSet(100000001);

		BOOST_CHECK(result == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(must_make_set_of_46_primes)
	{
		size_t expectedResult = 46;
		std::set<int> result = GeneratePrimeNumbersSet(200);

		BOOST_CHECK(result.size() == expectedResult);
	}

	#ifndef _DEBUG
	BOOST_AUTO_TEST_CASE(must_generate_max_size_set)
	{
		auto expectedResult = 5761455;
		auto result = GeneratePrimeNumbersSet(100000000);

		BOOST_CHECK(result.size() == expectedResult);
	}
	#endif

BOOST_AUTO_TEST_SUITE_END()