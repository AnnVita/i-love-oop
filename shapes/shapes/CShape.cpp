#include "stdafx.h"
#include "CShape.h"

CShape::CShape(std::string const & type, std::string const & outlineColor)
	: m_type(type),
	m_outlineColor(outlineColor)
{
}

std::string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CShape::ToString() const
{
	std::ostringstream strm;
	strm << m_type + ": "
		<< "Area = " << GetArea()
		<< " Perimeter = " << GetPerimeter()
		<< " OutlineColor = " << GetOutlineColor();
	AppendProperties(strm);
	return strm.str();
}