#include "stdafx.h"
#include "vectorFunctions.h"

void ProcessVector(DoubleVector & vector)
{
	if (vector.size() > 1)
	{
		double averageOfPositive = GetAverageOfPositiveElements(vector);
		AddToAllElements(vector, averageOfPositive);
	}
}

double GetAverageOfPositiveElements(const DoubleVector & elements)
{
	double result = 0;
	size_t positiveNumCounter = 0;
	for (const double & element : elements)
	{
		if (element > 0)
		{
			result += element;
			++positiveNumCounter;
		}
	}
	return (positiveNumCounter > 0) ? result / positiveNumCounter : result;
}

void AddToAllElements(DoubleVector & elements, double numberToAdd)
{
	for (double & element : elements)
	{
		element += numberToAdd;
	}
}