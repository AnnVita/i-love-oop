#pragma once
#include "stdafx.h"

class IShape
{
public:
	IShape() = default;
	IShape(std::string const & type);
	virtual ~IShape() = default;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string GetOutlineColor() const = 0;
	std::string ToString() const;

protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;

private:
	std::string m_type;
};