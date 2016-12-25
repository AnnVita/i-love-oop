#pragma once
#include "stdafx.h"
#include "ShapeInterface.h"

class CShape : public IShape
{
public:
	CShape(std::string const & type, std::string const & outlineColor);
	virtual ~CShape() = default;

	std::string ToString() const final;
	std::string GetOutlineColor() const final;

protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;

private:
	std::string m_type;
	std::string m_outlineColor;
};