#pragma once
#include "CShape.h"

class CSolidShape : public CShape
{
public:
	CSolidShape(std::string const & type, std::string const & outlineColor, std::string const & fillColor);

	virtual ~CSolidShape() = default;
	std::string GetFillColor() const;

protected:
	void AppendProperties(std::ostream & strm) const;

private:
	std::string m_fillColor;
};