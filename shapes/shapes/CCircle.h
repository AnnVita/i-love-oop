#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint const & center, float radius, std::string const & outlineColor, std::string const & fillColor);
	~CCircle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	float GetRadius() const;
	CPoint const & GetCenter() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	CPoint m_center;
	float m_radius;
	std::string m_outlineColor;
	std::string m_fillColor;
};

bool operator >> (std::istream & input, std::shared_ptr<CCircle> & circle);