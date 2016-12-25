#include "stdafx.h"
#include "CCircle.h"
#include "CSolidShape.h"
#include "CPoint.h"

CCircle::CCircle(CPoint const & center, float radius, const std::string & outlineColor, const std::string & fillColor)
	:CSolidShape("Circle", outlineColor, fillColor),
	m_center(center),
	m_radius(abs(radius))
{
}

CPoint const & CCircle::GetCenter() const
{
	return m_center;
}

float CCircle::GetRadius() const
{
	return m_radius;
}

float CCircle::GetPerimeter() const
{
	return 2.0f * m_radius * static_cast<float>(M_PI);
};

float CCircle::GetArea() const
{
	return m_radius * m_radius * static_cast<float>(M_PI);
};

void CCircle::AppendProperties(std::ostream & strm) const
{
	strm << " Radius = " << m_radius
		<< " FillColor = " << GetFillColor();
}

bool operator >> (std::istream & input, std::shared_ptr<CCircle> & circle)
{
	CPoint center;
	float radius;
	std::string outlineColor;
	std::string fillColor;

	if (input >> center && input >> radius && input >> outlineColor && input >> fillColor)
	{
		circle = std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
		return true;
	}
	return false;
}