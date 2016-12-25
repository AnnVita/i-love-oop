#include "stdafx.h"
#include "CSolidShape.h"

CSolidShape::CSolidShape(std::string const & type, std::string const & outlineColor, std::string const & fillColor)
	: CShape(type, outlineColor),
	m_fillColor(fillColor)
{
}

void CSolidShape::AppendProperties(std::ostream & strm) const
{
	strm << " FillColor = " << GetFillColor();
}

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}