#include "stdafx.h"
#include "FindAndReplace.h"

std::string FindAndReplace(const std::string &subject, const std::string &search, const std::string &replace)
{
	size_t prevPos = 0, currFoundedPos = 0;
	std::string result = "";

	if (search.length() == 0)
	{
		return result;
	}

	while (((currFoundedPos = subject.find(search, prevPos)) != std::string::npos))
	{
		result += subject.substr(prevPos, currFoundedPos - prevPos);
		result += replace;
		prevPos = currFoundedPos + search.length();
	}
	return result += subject.substr(prevPos);
}
