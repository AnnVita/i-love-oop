#include "stdafx.h"
#include "../shapes/CLineSegment.h"
#include "TestFunctions.h"

struct LineSegmentFixture
{
	CLineSegment line;
	LineSegmentFixture()
		:line({ 0, 15 }, { 15, 7 }, "#000012")
	{}
};

BOOST_FIXTURE_TEST_SUITE(LineSegment, LineSegmentFixture)

	BOOST_AUTO_TEST_CASE(has_outline_color)
	{
		BOOST_CHECK_EQUAL(line.GetOutlineColor(), "#000012");
	}
	BOOST_AUTO_TEST_CASE(has_zero_area)
	{
		BOOST_CHECK_EQUAL(line.GetArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		BOOST_CHECK_EQUAL(line.GetPerimeter(), 17);
	}
	BOOST_AUTO_TEST_CASE(has_start_point)
	{
		VerifyPoint(line.GetStartPoint(), 0, 15);
	}
	BOOST_AUTO_TEST_CASE(has_end_point)
	{
		VerifyPoint(line.GetEndPoint(), 15, 7);
	}
	BOOST_AUTO_TEST_CASE(can_return_info_about_itself)
	{
		BOOST_CHECK_EQUAL(line.ToString(), "Line: Area = 0 Perimeter = 17 OutlineColor = #000012 Start point = (0.000000, 15.000000) End point = (15.000000, 7.000000)");
	}

BOOST_AUTO_TEST_SUITE_END()