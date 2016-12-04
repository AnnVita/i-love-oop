#include "stdafx.h"
#include "CPoint.h"

CPoint::CPoint(float x, float y)
	: x(x)
	, y(y)
{
}

std::string CPoint::ToString() const
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}