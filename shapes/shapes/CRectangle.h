#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(CPoint const & leftTop, float width, float height, const std::string & outlineColor, const std::string & fillColor);

	float GetArea() const override final;
	float GetPerimeter() const override final;

	CPoint const & GetLeftTop() const;
	float GetWidth() const;
	float GetHeight() const;

	void Draw(ICanvas & canvas) const override;
protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	CPoint m_leftTop;
	float m_width;
	float m_height;
};

bool operator >> (std::istream & input, std::shared_ptr<CRectangle> & rectangle);
