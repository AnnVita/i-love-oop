#include "stdafx.h"
#include "CRectangle.h"
#include "CSolidShape.h"
#include "CPoint.h"

CRectangle::CRectangle(CPoint const & leftTop, float width, float height, const std::string & outlineColor, const std::string & fillColor)
	:CSolidShape("Rectangle", outlineColor, fillColor),
	m_leftTop(leftTop),
	m_height(abs(height)),
	m_width(abs(width))
{
}

float CRectangle::GetWidth() const
{
	return m_width;
};

float CRectangle::GetHeight() const
{
	return m_height;
};


CPoint const & CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

float CRectangle::GetArea() const
{
	return m_width * m_height;
};

float CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
};

void CRectangle::AppendProperties(std::ostream & strm) const
{
	strm << " Width = " << m_width
		<< " Height = " << m_height
		<< " FillColor = " << GetFillColor();
}

bool operator >> (std::istream & input, std::shared_ptr<CRectangle> & rectangle)
{
	CPoint leftTop;
	float width;
	float height;
	std::string outlineColor;
	std::string fillColor;

	if (input >> leftTop && input >> width && input >> height && input >> outlineColor && input >> fillColor)
	{
		rectangle = std::make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
		return true;
	}
	return false;
}