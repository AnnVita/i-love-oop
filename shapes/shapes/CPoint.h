#pragma once

class CPoint
{
public:
	CPoint() = default;
	CPoint(float m_x, float m_y);

	std::string ToString() const;
	
	float x = 0.0f;
	float y = 0.0f;
};

bool operator >> (std::istream & input, CPoint & point);