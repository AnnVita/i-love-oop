#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double density, double width, double height, double length)
	: CBody("Parallelepiped", density)
	, m_length(length)
	, m_width(width)
	, m_height(height)
{
}

CParallelepiped::~CParallelepiped()
{
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetLength() const
{
	return m_length;
}

double CParallelepiped::GetVolume() const
{
	return  m_length * m_width * m_height;
}

void CParallelepiped::AppendProperties(std::ostream &strm) const
{
	strm << "\tlength = " << GetLength() << std::endl 
		<< "\twidth = " << GetWidth() << std::endl 
		<< "\theight = " << GetHeight() << std::endl;
}