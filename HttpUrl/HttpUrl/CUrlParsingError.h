#pragma once
#include "stdafx.h"

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string & message)
		: std::invalid_argument(message)
	{ };
private:
	std::string m_base;
};
