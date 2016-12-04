#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(const CPoint & start, const CPoint & end, const std::string & outlineColor)
	:m_begin(start)
	, m_end(end)
	, m_outlineColor(outlineColor)
	, IShape("Line")
{
}

float CLineSegment::GetArea() const
{
	return 0;
}

float CLineSegment::GetPerimeter() const
{
	return std::hypot(m_end.x - m_begin.x, m_end.y - m_begin.y);
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_begin;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_end;
}

std::string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

void CLineSegment::AppendProperties(std::ostream & strm) const
{
	strm << " Start point = " << GetStartPoint().ToString()
		<< " End point = " << GetEndPoint().ToString();
}