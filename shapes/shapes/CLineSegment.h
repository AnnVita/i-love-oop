#pragma once
#include "IShape.h"
#include "CPoint.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(const CPoint & start, const CPoint & end, const std::string & outlineColor);
	~CLineSegment() = default;

	float GetArea() const;
	float GetPerimeter() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	std::string GetOutlineColor() const;

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	CPoint m_begin;
	CPoint m_end;
	std::string m_outlineColor;
};

