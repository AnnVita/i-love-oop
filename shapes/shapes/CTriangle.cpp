#include "stdafx.h"
#include "CSolidShape.h"
#include "CTriangle.h"
#include "CPoint.h"

CTriangle::CTriangle(CPoint const & firstVertex, CPoint const & secondVertex, CPoint const & thirdVertex, const std::string & outlineColor, const std::string & fillColor)
	: CSolidShape("Triangle", outlineColor, fillColor)
{
	m_vertices[0] = firstVertex;
	m_vertices[1] = secondVertex;
	m_vertices[2] = thirdVertex;
}

CPoint const & CTriangle::GetVertex(Vertices const & vertexId) const
{
	return m_vertices[vertexId];
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

bool operator >> (std::istream & input, std::shared_ptr<CTriangle> & triangle)
{
	CPoint firstVertex;
	CPoint secondVertex;
	CPoint thirdVertex;
	std::string outlineColor;
	std::string fillColor;

	if (input >> firstVertex && input >> secondVertex && input >> thirdVertex && input >> outlineColor && input >> fillColor)
	{
		triangle = std::make_shared<CTriangle>(firstVertex, secondVertex, thirdVertex, outlineColor, fillColor);
		return true;
	}
	return false;
}