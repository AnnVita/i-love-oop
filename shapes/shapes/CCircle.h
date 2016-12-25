#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CCircle : public CSolidShape
{
public:
	CCircle(CPoint const & center, float radius, const std::string & outlineColor, const std::string & fillColor);

	float GetArea() const override final;
	float GetPerimeter() const override final;

	float GetRadius() const;
	CPoint const & GetCenter() const;

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	CPoint m_center;
	float m_radius;
};

bool operator >> (std::istream & input, std::shared_ptr<CCircle> & circle);