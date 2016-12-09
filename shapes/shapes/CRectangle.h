#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint const & leftTop, float width, float height, std::string const & outlineColor, std::string const & fillColor);
	~CRectangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint const & GetLeftTop() const;
	float GetWidth() const;
	float GetHeight() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	std::string m_outlineColor;
	std::string m_fillColor;
	CPoint m_leftTop;
	float m_width;
	float m_height;
};

bool operator >> (std::istream & input, std::shared_ptr<CRectangle> & rectangle);
