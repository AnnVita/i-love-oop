#include "stdafx.h"
#include "vectorFunctions.h"

using namespace std;

int main(int argc, char * argv[])
{
	DoubleVector numbers;

	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(numbers));

	ProcessVector(numbers);

	sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));
	
	return EXIT_SUCCESS;
}