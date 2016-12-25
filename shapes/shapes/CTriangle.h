#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CTriangle : public CSolidShape
{
public:
	enum Vertices 
	{
		first = 0,
		second = 1,
		third = 2
	};

	CTriangle(CPoint const & firstVertex, CPoint const & secondVertex, CPoint const & thirdVertex, const std::string & outlineColor, const std::string & fillColor);
	
	float GetArea() const override final;
	float GetPerimeter() const override final;

	CPoint const & GetVertex(Vertices const & vertexId) const;
	float GetSideLength(CPoint const & firstVertex, CPoint const & secondVertex) const;

	void Draw(ICanvas & canvas) const override;
protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	std::vector<CPoint> m_vertices;
};

bool operator >> (std::istream & input, std::shared_ptr<CTriangle> & triangle);