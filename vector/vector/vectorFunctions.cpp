#include "stdafx.h"
#include "vectorFunctions.h"

double GetAverageOfPositiveElements(DoubleVector & elements)
{
	double result = 0;
	size_t positiveNumCounter = 0;
	for (const double & n : elements)
	{
		if (n > 0)
		{
			result += n;
			++positiveNumCounter;
		}
	}
	return (positiveNumCounter > 0) ? result / positiveNumCounter : result;
}

void AddToAllElements(DoubleVector & elements, double numberToAdd)
{
	for (double & n : elements)
	{
		n += numberToAdd;
	}
}