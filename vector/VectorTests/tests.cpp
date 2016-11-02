#include "stdafx.h"
#include "../vector/vectorFunctions.h"

namespace
{
	DoubleVector emptyVector = {};
	DoubleVector singleElementVector = {2};
	DoubleVector testVectorWithValues = { 9, 1, -2, -10, 0, 9, 5, -11 };
	void VerifyGetAverageOfPositiveElements(DoubleVector & vector, double expectedValue)
	{
		BOOST_CHECK(GetAverageOfPositiveElements(vector) == expectedValue);
	}

	void VerifyAddToAllElements(DoubleVector vector, double valToAdd, DoubleVector & expectedElements)
	{ 
		AddToAllElements(vector, valToAdd);
		BOOST_CHECK(vector == expectedElements);
	}

	void VerifyProcessVector(DoubleVector vector, const DoubleVector & expectedVector)
	{
		ProcessVector(vector);
		BOOST_CHECK(vector == expectedVector);
	}
}

BOOST_AUTO_TEST_SUITE(GetAverageOfPositiveElements_function)
    BOOST_AUTO_TEST_CASE(must_count_average_of_all_positive_values_in_vector)
    {
	    VerifyGetAverageOfPositiveElements(testVectorWithValues, 6.0);
    }

    BOOST_AUTO_TEST_CASE(must_return_zero_if_vector_is_empty)
    {
	    VerifyGetAverageOfPositiveElements(emptyVector, 0);
    }

    BOOST_AUTO_TEST_CASE(must_return_value_of_single_element_of_vector)
    {
	    VerifyGetAverageOfPositiveElements(singleElementVector, 2);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(AddToAllElements_function)
    BOOST_AUTO_TEST_CASE(must_add_to_all_vector_elements_the_same_value)
    {
	    DoubleVector expectedVector = { 11, 3, 0, -8, 2, 11, 7, -9 };
	    VerifyAddToAllElements(testVectorWithValues, 2, expectedVector);
    }

    BOOST_AUTO_TEST_CASE(must_convert_empty_vector_to_empty_vector)
    {
	    DoubleVector expectedVector = {};
	    VerifyAddToAllElements(emptyVector, 2, expectedVector);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ProcessVector_function)
	BOOST_AUTO_TEST_CASE(must_convert_empty_vector_to_empty_vector)
    {
	    DoubleVector expectedVector = {};
	    VerifyProcessVector(emptyVector, expectedVector);
    }
    
    BOOST_AUTO_TEST_CASE(must_convert_single_element_vector_to_the_same_single_element_vector)
    {
	    DoubleVector expectedVector = {2};
	    VerifyProcessVector(singleElementVector, expectedVector);
    }

    BOOST_AUTO_TEST_CASE(must_add_to_all_elements_average_of_all_positive_elements_of_vector)
    {
		DoubleVector expectedVector = { 15, 7, 4, -4, 6, 15, 11, -5 };
	    VerifyProcessVector(testVectorWithValues, expectedVector);
    }
BOOST_AUTO_TEST_SUITE_END();