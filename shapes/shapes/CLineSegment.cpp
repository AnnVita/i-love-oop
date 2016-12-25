#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(const CPoint & start, const CPoint & end, const std::string & outlineColor)
	:m_begin(start)
	, m_end(end)
	, CShape("Line", outlineColor)
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

void CLineSegment::AppendProperties(std::ostream & strm) const
{
	strm << " Start point = " << GetStartPoint().ToString()
		<< " End point = " << GetEndPoint().ToString();
}

void CLineSegment::Draw(ICanvas & canvas) const
{
	canvas.DrawLine(m_begin, m_end, FromHex(GetOutlineColor()));
}

bool operator >> (std::istream & input, std::shared_ptr<CLineSegment> & line)
{
	CPoint start;
	CPoint end;
	std::string outlineColor;
	if (input >> start && input >> end && input >> outlineColor)
	{
		line = std::make_shared<CLineSegment>(start, end, outlineColor);
		return true;
	}
	return false;
}