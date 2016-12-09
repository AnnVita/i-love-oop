#pragma once

class CPoint
{
public:
	CPoint() = default;
	CPoint(float m_x, float m_y);
	~CPoint() = default;

	std::string ToString() const;
	
	float x = 0.0;
	float y = 0.0;
};

bool operator >> (std::istream & input, CPoint & point);