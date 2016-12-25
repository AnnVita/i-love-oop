#include "stdafx.h"
#include "CPoint.h"

CPoint::CPoint(float x, float y)
	: x(abs(x))
	, y(abs(y))
{
}

std::string CPoint::ToString() const
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

bool operator >> (std::istream & input, CPoint & point)
{
	if (input >> point.x && input >> point.y)
	{
		return true;
	}
	return false;
}