#pragma once
#include "stdafx.h"

class CPoint final
{
public:
	CPoint(float x, float y);
	~CPoint() = default;

	std::string ToString() const;
	float GetX() const;
	float GetY() const;

private:
	float x = 0.0;
	float y = 0.0;
};

bool operator >> (std::istream & input, CPoint & point);