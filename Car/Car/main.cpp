#include "stdafx.h"
#include "car.h"
#include "carController.h"
#include <iostream>

int main()
{
	CCar car;
	CCarControl carController(car, std::cin, std::cout);

	while ((!std::cin.eof()) && (!std::cin.fail()))
	{
		std::cout << "> ";
		if (!carController.HandleCommand())
		{
			std::cout << "Unknown command!" << std::endl;
		}
	}

	return 0;
}

