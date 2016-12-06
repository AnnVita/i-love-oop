#include "stdafx.h"
#include "TestFunctions.h"
#include "../shapes/CCircle.h"

struct CircleFixture_
{
    CCircle circle;
    CircleFixture_()
        :circle({ 40, 11 }, 24, "#2244fa", "#111111")
    {}
};

BOOST_FIXTURE_TEST_SUITE(Circle, CircleFixture_)
	BOOST_AUTO_TEST_CASE(has_center_point)
	{
		VerifyPoint(circle.GetCenter(), 40, 11);
	}

	BOOST_AUTO_TEST_CASE(has_radius)
	{
		BOOST_CHECK_EQUAL(circle.GetRadius(), 24.0f);
	}

	BOOST_AUTO_TEST_CASE(has_an_area)
    {
		BOOST_CHECK_CLOSE_FRACTION(circle.GetArea(), M_PI * 24 * 24, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(has_a_perimeter)
    {
		BOOST_CHECK_CLOSE_FRACTION(circle.GetPerimeter(), 2 * M_PI * 24, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(has_fill_color)
    {
		BOOST_CHECK_EQUAL(circle.GetFillColor(), "#111111");
    }

    BOOST_AUTO_TEST_CASE(has_outline_color)
    {
		BOOST_CHECK_EQUAL(circle.GetOutlineColor(), "#2244fa");
    }

    BOOST_AUTO_TEST_CASE(can_return_info_about_itself)
    {
        BOOST_CHECK_EQUAL(circle.ToString(), "Circle: Area = 1809.56 Perimeter = 150.796 OutlineColor = #2244fa Radius = 24 FillColor = #111111");
    }
BOOST_AUTO_TEST_SUITE_END()