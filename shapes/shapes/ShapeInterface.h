#pragma once
#include "stdafx.h"
#include "ICanvasDrawable.h"

class IShape : public ICanvasDrawable
{
public:
	virtual ~IShape() = default;
	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual std::string GetOutlineColor() const = 0;
	virtual std::string ToString() const = 0;
};