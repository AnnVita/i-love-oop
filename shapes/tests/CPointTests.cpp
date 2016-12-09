#include "stdafx.h"
#include "TestFunctions.h"
#include "..\shapes\CPoint.h"

BOOST_AUTO_TEST_SUITE(Point_class)

	BOOST_AUTO_TEST_CASE(has_zero_values_by_default)
	{
		CPoint point;
		VerifyPoint(point, 0.0, 0.0);
	}

    BOOST_AUTO_TEST_CASE(can_be_filled_by_init_point)
    {
        CPoint point = { 11.4f, 30.8f };
        VerifyPoint(point, 11.4f, 30.8f);
    }
    BOOST_AUTO_TEST_CASE(can_init_point_via_constructor)
    {
        CPoint point(11.4f, 30.8f);
        VerifyPoint(point, 11.4f, 30.8f);
    }
    BOOST_AUTO_TEST_CASE(can_init_point_via_fields)
    {
        CPoint point;
        point.x = 11.4f;
        point.y = 30.8f;
        VerifyPoint(point, 11.4f, 30.8f);
    }
	BOOST_AUTO_TEST_CASE(can_return_info_about_itself)
	{
		CPoint point(11.5f, 12.3f);
		BOOST_CHECK_EQUAL(point.ToString(), "(11.500000, 12.300000)");
	}
	BOOST_AUTO_TEST_CASE(can_be_read_from_istream)
	{
		{
			CPoint point;

			std::istringstream input("12 11.1");
			input >> point;
			BOOST_CHECK(!input.fail());
		}
		{
			CPoint point;

			std::istringstream input("something wrong");
			input >> point;
			BOOST_CHECK(input.fail());
		}
		{
			CPoint point;

			std::istringstream input("42");
			input >> point;
			BOOST_CHECK(input.fail());
		}
	}

BOOST_AUTO_TEST_SUITE_END()