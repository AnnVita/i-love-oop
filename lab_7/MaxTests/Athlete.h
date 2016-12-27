#pragma once

struct Athlete
{
	Athlete() = default;
	Athlete(std::string name, float height, float weight);
	std::string name;
	float height;
	float weight;
};

bool LessHeight(const Athlete & lAthlete, const Athlete & rAthlete);
bool LessWeight(const Athlete & lAthlete, const Athlete & rAthlete);