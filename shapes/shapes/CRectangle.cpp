#include "stdafx.h"
#include "CRectangle.h"
#include "ISolidShape.h"
#include "CPoint.h"

CRectangle::CRectangle(CPoint const & leftTop, float width, float height, std::string const & outlineColor, std::string const & fillColor)
	:ISolidShape("Rectangle"),
	m_leftTop(leftTop),
	m_height(height),
	m_width(width),
	m_fillColor(fillColor),
	m_outlineColor(outlineColor)
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

std::string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
};

std::string CRectangle::GetFillColor() const
{
	return m_fillColor;
};

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