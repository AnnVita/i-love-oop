#pragma once

#include "Body.h"

class CParallelepiped final : public CBody
{
public:
	CParallelepiped(double density, double length, double width, double height);
	~CParallelepiped();

	double GetVolume() const override;
	double GetLength() const;
	double GetWidth() const;
	double GetHeight() const;

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	double m_length;
	double m_width;
	double m_height;
};