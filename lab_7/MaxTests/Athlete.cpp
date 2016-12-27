#include "stdafx.h"
#include "Athlete.h"

Athlete::Athlete(std::string name, float height, float weight)
	: name(name)
	, height(height)
	, weight(weight)
{
}

bool LessHeight(const Athlete & lAthlete, const Athlete & rAthlete)
{
	return lAthlete.height < rAthlete.height;
}

bool LessWeight(const Athlete & lAthlete, const Athlete & rAthlete)
{
	return lAthlete.weight < rAthlete.weight;
}