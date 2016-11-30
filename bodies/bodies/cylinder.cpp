#include "stdafx.h"
#include "Cylinder.h"

CCylinder::CCylinder(double density, double baseRadius, double height)
	: CBody("Cylinder", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * m_baseRadius * m_baseRadius * m_height;
}

void CCylinder::AppendProperties(std::ostream &strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << '\n'
		<< "\theight = " << GetHeight() << '\n';
}