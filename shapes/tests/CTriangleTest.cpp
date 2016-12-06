#include "stdafx.h"
#include "TestFunctions.h"
#include "../shapes/CTriangle.h"


struct TriangleFixture_
{
    CTriangle triangle;
    TriangleFixture_()
        :triangle({ 0, 0 }, { 0, 3 }, { 4, 3 }, "#ff00ff", "#0000ff")
    {}
};

BOOST_FIXTURE_TEST_SUITE(Triangle, TriangleFixture_)

	BOOST_AUTO_TEST_CASE(get_three_vertices)
	{
		VerifyPoint(triangle.GetVertex1(), 0, 0);
		VerifyPoint(triangle.GetVertex2(), 0, 3);
		VerifyPoint(triangle.GetVertex3(), 4, 3);
	}

    BOOST_AUTO_TEST_CASE(has_a_perimeter)
    {
        BOOST_CHECK_EQUAL(triangle.GetPerimeter(), 12);
    }

    BOOST_AUTO_TEST_CASE(has_an_area)
    {
        BOOST_CHECK_EQUAL(triangle.GetArea(), 3 * 4 *0.5);
    }

    BOOST_AUTO_TEST_CASE(has_fill_color)
    {
        BOOST_CHECK_EQUAL(triangle.GetFillColor(), "#0000ff");
    }

    BOOST_AUTO_TEST_CASE(has_outline_color)
    {
        BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), "#ff00ff");
    }

    BOOST_AUTO_TEST_CASE(can_return_info_about_itself)
    {
        BOOST_CHECK_EQUAL(triangle.ToString(), "Triangle: Area = 6 Perimeter = 12 OutlineColor = #ff00ff FillColor = #0000ff");
    }

BOOST_AUTO_TEST_SUITE_END()