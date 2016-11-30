#pragma once
#include "stdafx.h"

class CBody
{
public:
	CBody(const std::string & type, double density);
	virtual ~CBody();

	virtual double GetMass() const;
	double GetDensity() const;
	virtual double GetVolume() const = 0;
	std::string ToString() const;

protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
	double m_density;
private:
	std::string m_type;
};