#pragma once
#include "CShape.h"
#include "CPoint.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint & start, const CPoint & end, const std::string & outlineColor);

	float GetArea() const final;
	float GetPerimeter() const override final;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	void Draw(ICanvas & canvas) const override;
protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	CPoint m_begin;
	CPoint m_end;
	long int m_outlineColor;
};

bool operator >> (std::istream & input, std::shared_ptr<CLineSegment> & line);