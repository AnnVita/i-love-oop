#include "stdafx.h"
#include "vectorFunctions.h"

using namespace std;

int main(int argc, char * argv[])
{
	DoubleVector numbers;

	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(numbers));

	
	return EXIT_SUCCESS;
}