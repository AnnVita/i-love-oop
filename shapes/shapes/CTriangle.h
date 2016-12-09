#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint const & firstVertex, CPoint const & secondVertex, CPoint const & thirdVertex, std::string const & outlineColor, std::string const & fillColor);
	~CTriangle() = default;
	float GetArea() const override;
	float GetPerimeter() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint const & GetVertex1() const;
	CPoint const & GetVertex2() const;
	CPoint const & GetVertex3() const;

	float GetSideLength(CPoint const & firstVertex, CPoint const & secondVertex) const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_vertices[3];
	std::string m_outlineColor;
	std::string m_fillColor;
};

bool operator >> (std::istream & input, std::shared_ptr<CTriangle> & triangle);