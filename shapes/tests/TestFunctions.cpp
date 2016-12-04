#include "stdafx.h"
#include "TestFunctions.h"
#include "..\shapes\CPoint.h"

void VerifyPoint(CPoint const & point, float expectedX, float expectedY)
{
	BOOST_CHECK_CLOSE_FRACTION(point.x, expectedX, 0.0001);
	BOOST_CHECK_CLOSE_FRACTION(point.y, expectedY, 0.0001);
}