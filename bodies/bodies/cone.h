#pragma once
#include "Body.h"

class CCone final : public CBody
{
public:
	CCone(double density, double height, double baseRadius);
	
	double GetVolume() const override;
	double GetBaseRadius() const;
	double GetHeight() const;

protected:
	void AppendProperties(std::ostream &strm) const override;

private:
	double m_height;
	double m_baseRadius;
};