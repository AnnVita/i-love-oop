#include "stdafx.h"
#include "Color.h"

sf::Color FromHex(const std::string & color)
{
	sf::Color result;
	result.r = static_cast<sf::Uint8>(std::stoi(color.substr(1, 3), 0, 16));
	result.g = static_cast<sf::Uint8>(std::stoi(color.substr(3, 3), 0, 16));
	result.b = static_cast<sf::Uint8>(std::stoi(color.substr(5, 3), 0, 16));
	return result;
}