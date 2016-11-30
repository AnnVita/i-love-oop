#pragma once

#include "Body.h"

class CCylinder final : public CBody
{
public:
	CCylinder(double density, double baseRadius, double height);

	double GetVolume() const override;
	double GetBaseRadius() const;
	double GetHeight() const;

protected:
	void AppendProperties(std::ostream &strm) const override;

private:
	double m_baseRadius;
	double m_height;
};