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
		VerifyPoint(triangle.GetVertex(CTriangle::Vertices::first), 0, 0);
		VerifyPoint(triangle.GetVertex(CTriangle::Vertices::second), 0, 3);
		VerifyPoint(triangle.GetVertex(CTriangle::Vertices::third), 4, 3);
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
	BOOST_AUTO_TEST_CASE(can_be_read_from_istream_by_shared_ptr)
	{
		{
			std::shared_ptr<CTriangle> triangle;

			std::istringstream input("22.2 30 100 42 200 12 #2030ff #00000a");
			input >> triangle;
			BOOST_CHECK(!input.fail());
		}
		{
			std::shared_ptr<CTriangle> triangle;

			std::istringstream input("22.2 30 100 42 #00000a");
			input >> triangle;
			BOOST_CHECK(input.fail());
		}
		{
			std::shared_ptr<CTriangle> triangle;

			std::istringstream input("invalid string");
			input >> triangle;
			BOOST_CHECK(input.fail());
		}
	}
BOOST_AUTO_TEST_SUITE_END()