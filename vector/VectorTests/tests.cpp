#include "stdafx.h"
#include "../vector/vectorFunctions.h"

namespace
{
	void VerifyGetAverageOfPositiveElements(DoubleVector & vector, double &expectedValue)
	{
		BOOST_CHECK(GetAverageOfPositiveElements(vector) == expectedValue);
	}

	void VerifyAddToAllElements(DoubleVector vector, double valToAdd, DoubleVector & expectedElements)
	{ 
		AddToAllElements(vector, valToAdd);
		BOOST_CHECK(vector == expectedElements);
	}
}

BOOST_AUTO_TEST_SUITE(GetAverageOfPositiveElements_function)
BOOST_AUTO_TEST_CASE(must_count_average_of_all_positive_values_in_vector)
{

	DoubleVector testVector = { 9, 1, -2, -10, 0, 9, 5, -11 };
	double expectedValue = 6;
	VerifyGetAverageOfPositiveElements(testVector, expectedValue);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(AddToAllElements_function)
BOOST_AUTO_TEST_CASE(must_add_to_all_vector_elements_the_same_value)
{

	DoubleVector testVector = { 9, 1, -2, -10, 0, 9, 5, -11 };
	DoubleVector expectedVector = { 11, 3, 0, -8, 2, 11, 7, -9 };
	double valToAdd = 2;
	VerifyAddToAllElements(testVector, valToAdd, expectedVector);
}
BOOST_AUTO_TEST_SUITE_END()