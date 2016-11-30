#include "stdafx.h"
#include "Compound.h"

CCompound::CCompound()
	: CBody("Compound", 0)
{
}

bool CCompound::AddChildBody(const std::shared_ptr<CBody> &body)
{
	if (this != body.get())
	{
		m_elements.push_back(body);
		m_density = GetMass() / GetVolume();
		return true;
	}

	return false;
}

void CCompound::AppendProperties(std::ostream &strm) const
{
	strm << "--- compound body elements: ---" << std::endl;

	for (auto &element : m_elements)
	{
		strm << element->ToString();
	}

	strm << "--- end of compound ---" << std::endl;
}

double CCompound::GetMass() const
{
	double totalMass = 0;

	for (const auto &element : m_elements)
	{
		totalMass += element->GetMass();
	}

	return totalMass;
}

double CCompound::GetVolume() const
{
	double totalVolume = 0;

	for (const auto &element : m_elements)
	{
		totalVolume += element->GetVolume();
	}

	return totalVolume;
}