#include "stdafx.h"
#include "ISolidShape.h"
#include "CTriangle.h"
#include "CPoint.h"

CTriangle::CTriangle(CPoint const & firstVertex, CPoint const & secondVertex, CPoint const & thirdVertex, std::string const & outlineColor, std::string const & fillColor)
	:ISolidShape("Triangle"),
	m_fillColor(fillColor),
	m_outlineColor(outlineColor)
{
	m_vertices[0] = firstVertex;
	m_vertices[1] = secondVertex;
	m_vertices[2] = thirdVertex;
}

std::string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
};

std::string CTriangle::GetFillColor() const
{
	return m_fillColor;
};

CPoint const & CTriangle::GetVertex1() const
{
	return m_vertices[0];
}

CPoint const & CTriangle::GetVertex2() const
{
	return m_vertices[1];
}

CPoint const & CTriangle::GetVertex3() const
{
	return m_vertices[2];
}

float CTriangle::GetArea() const
{
	float semiperimeter = GetPerimeter() * 0.5f;
	return std::sqrt(semiperimeter*(semiperimeter - GetSideLength(m_vertices[0], m_vertices[1]))*
		(semiperimeter - GetSideLength(m_vertices[1], m_vertices[2]))*
		(semiperimeter - GetSideLength(m_vertices[2], m_vertices[0]))
	);
};

float CTriangle::GetPerimeter() const
{
	return GetSideLength(m_vertices[0], m_vertices[1]) +
		GetSideLength(m_vertices[1], m_vertices[2]) +
		GetSideLength(m_vertices[2], m_vertices[0]);
};

float CTriangle::GetSideLength(CPoint const & firstVertex, CPoint const & secondVertex) const
{
	return std::hypot(firstVertex.x - secondVertex.x, firstVertex.y - secondVertex.y);
};

void CTriangle::AppendProperties(std::ostream & strm) const
{
	strm << " FillColor = " << GetFillColor();
}