#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double baseRadius, double height)
	: CBody("Cone", density)
	, m_height(height)
	, m_baseRadius(baseRadius)
{
}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return M_PI * m_baseRadius * m_baseRadius * m_height / 3;
}

void CCone::AppendProperties(std::ostream &strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << '\n'
		<< "\theight = " << GetHeight() << '\n';
}