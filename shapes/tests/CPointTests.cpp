#include "stdafx.h"
#include "..\shapes\CPoint.h"

void VerifyPoint(CPoint const & point, float expectedX, float expectedY)
{
	BOOST_CHECK_CLOSE_FRACTION(point.x, expectedX, 0.0001);
	BOOST_CHECK_CLOSE_FRACTION(point.y, expectedY, 0.0001);
}

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
		CPoint point(11.5f, 12.3);
		BOOST_CHECK_EQUAL(point.ToString(), "(11.500000, 12.300000)");
	}

BOOST_AUTO_TEST_SUITE_END()