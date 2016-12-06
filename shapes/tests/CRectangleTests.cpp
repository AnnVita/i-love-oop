#include "stdafx.h"
#include "TestFunctions.h"
#include "../shapes/CRectangle.h"

struct RectangleFixture_
{
    CRectangle rectangle;
    RectangleFixture_()
        :rectangle({ 20.2f, 100 }, 100, 20, "#f255ff", "#00001f")
    {}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle, RectangleFixture_)
	BOOST_AUTO_TEST_CASE(has_vertex)
	{
		VerifyPoint(rectangle.GetLeftTop(), 20.2f, 100);
	}

    BOOST_AUTO_TEST_CASE(has_a_perimeter)
    {
        BOOST_CHECK_EQUAL(rectangle.GetPerimeter(), 240);
    }

    BOOST_AUTO_TEST_CASE(has_an_area)
    {
        BOOST_CHECK_EQUAL(rectangle.GetArea(), 2000);
    }

    BOOST_AUTO_TEST_CASE(has_fill_color)
    {
        BOOST_CHECK_EQUAL(rectangle.GetFillColor(), "#00001f");
    }

    BOOST_AUTO_TEST_CASE(has_outline_color)
    {
        BOOST_CHECK_EQUAL(rectangle.GetOutlineColor(), "#f255ff");
    }

    BOOST_AUTO_TEST_CASE(rectangle_to_string)
    {
        BOOST_CHECK_EQUAL(rectangle.ToString(), "Rectangle: Area = 2000 Perimeter = 240 OutlineColor = #f255ff Width = 100 Height = 20 FillColor = #00001f");
    }

BOOST_AUTO_TEST_SUITE_END()