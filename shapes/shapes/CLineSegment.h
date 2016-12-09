#pragma once
#include "IShape.h"
#include "CPoint.h"

class CLineSegment : public IShape
{
public:
	CLineSegment() = default;
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
	CPoint m_begin = { 0, 0 };
	CPoint m_end = { 0, 0 };
	std::string m_outlineColor;
};

bool operator >> (std::istream & input, std::shared_ptr<CLineSegment> & line);