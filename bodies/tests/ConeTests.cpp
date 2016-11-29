#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../bodies/Cone.h"
#include <math.h>

struct Cone_
{
	const double expectedRadius = 42.8;
	const double expectedHeight = 8.1;
	const double expectedDensity = 22.1;
	const double expectedVolume = M_PI * expectedRadius * expectedRadius * expectedHeight / 3;
	const CCone cone;
	Cone_()
		: cone(expectedDensity, expectedRadius, expectedHeight)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cone));
	}

	BOOST_AUTO_TEST_CASE(has_a_base_radius)
	{
		BOOST_CHECK_EQUAL(cone.GetBaseRadius(), expectedRadius);
	}

	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
	}

	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(cone.GetDensity(), expectedDensity);
	}

	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(cone.GetVolume(), expectedVolume, 1e-7);
	}

	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(cone.GetMass(), expectedVolume * expectedDensity, 1e-7);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Cone:
	density = 22.1
	volume = 15538.21673
	mass = 343394.5898
	base radius = 42.8
	height = 8.1
)";

		BOOST_CHECK_EQUAL(cone.ToString(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()