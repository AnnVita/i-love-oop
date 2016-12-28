#include "stdafx.h"
#include "../lab_7/Max.h"
#include "Athlete.h"

std::vector<Athlete> empty;

Athlete SugarRayLeonard("Sugar Ray Leonard", 177.0f, 172.0f);
Athlete MuhammadAli("Muhammad Ali", 191.0f, 107.0f);
Athlete HenryArmstrong("Henry Armstrong", 166.0f, 64.0f);
Athlete JosephLouisBarrow("Joseph Louis Barrow", 188.0f, 97.f);
std::vector<Athlete> athletes = { SugarRayLeonard, MuhammadAli, HenryArmstrong, JosephLouisBarrow};
Athlete maxAthlete;

BOOST_AUTO_TEST_SUITE(FindMaxEx_)

	BOOST_AUTO_TEST_CASE(can_find_max_athlet_by_height)
	{
		BOOST_CHECK(FindMaxEx(athletes, maxAthlete, LessHeight));
		BOOST_CHECK_EQUAL(maxAthlete.height, 191.0f);
		BOOST_CHECK_EQUAL(maxAthlete.name, "Muhammad Ali");
	}

	BOOST_AUTO_TEST_CASE(can_find_max_athlet_by_weight)
	{
		BOOST_CHECK(FindMaxEx(athletes, maxAthlete, LessWeight));
		BOOST_CHECK_EQUAL(maxAthlete.weight, 172.0f);
		BOOST_CHECK_EQUAL(maxAthlete.name, "Sugar Ray Leonard");
	}

	BOOST_AUTO_TEST_CASE(returns_false_if_vector_is_empty)
	{
		BOOST_CHECK(empty.empty());
		BOOST_CHECK(!FindMaxEx(empty, maxAthlete, LessHeight));
		BOOST_CHECK(!FindMaxEx(empty, maxAthlete, LessWeight));
	}

	BOOST_AUTO_TEST_CASE(can_find_max_by_default_way_of_comparison)
	{
		std::vector<std::string> strVector = {"1", "2", "3"};
		std::string max;
		BOOST_CHECK(FindMaxEx(strVector, max));
		BOOST_CHECK_EQUAL(max, "3");
	}
BOOST_AUTO_TEST_SUITE_END()