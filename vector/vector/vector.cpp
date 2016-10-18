#include "stdafx.h"
#include "vectorFunctions.h"

using namespace std;

int main(int argc, char * argv[])
{
	DoubleVector numbers;

	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(numbers));

	double averageOfPositive = GetAverageOfPositiveElements(numbers);
	AddToAllElements(numbers, averageOfPositive);
	sort(numbers.begin(), numbers.end());

	for (const double & element : numbers)
	{
		cout << element << ' ';
	}
	
	return EXIT_SUCCESS;
}