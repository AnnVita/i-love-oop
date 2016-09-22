#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

static const int DEC_RADIX = 10;
static const int MAX_RADIX = 36;
static const int MIN_RADIX = 2;

using namespace std;

int CharToInt(char const &ch);
bool CheckInputRadix(int const &radix);
int StringToInt(const string &str, int radix, bool &wasError);

void StringIntToString(int n, int radix, bool &wasError);
bool OwerflowAtAddition(int const &addendum1, int const &addendum2);
bool OwerflowAtMultiplication(int const &multiplier1, int const &multiplier2);
int Pow(int const &base, int const &pow, bool &wasError);
int TransferDecimalToAnother(int const &decimal, int const &destinationRadix);

int main(int argc, char * argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: radix.exe <source notation> <destination notation> <value>\n";
		return 1;
	}

	int sourceNotation = stoi(argv[1]),
		destinationNotation = stoi(argv[2]);
	string numValue;


	return 0;
}

int CharToInt(char const &ch)
{
	int number = -1;
	bool numericCh = ((ch >= '0') && (ch <= '9')),
		alphabeticCh = ((ch >= 'A') && (ch <= 'Z'));
	if (numericCh)
	{
		number = int(ch) - int('0');
	}
	else if (alphabeticCh)
	{
		number = int(ch) - int('A') + DEC_RADIX;
	}
	return number;
}

bool CheckInputRadix(int const &radix)
{
	return ((radix >= MIN_RADIX) && (radix <= MAX_RADIX));
}

bool OwerflowAtAddition(int const &addendum1, int const &addendum2)
{
	return ((addendum1 > 0) && (addendum2 > 0) && (addendum1 > (INT_MAX - addendum2)));
}

bool OwerflowAtMultiplication(int const &multiplier1, int const &multiplier2)
{
	return (multiplier1 >= INT_MAX / multiplier2);
}

int StringToInt(const string &str, int radix, bool &wasError)
{
	bool isNegative = (str[0] == '-');
	int i = (isNegative ? 1 : 0),
		result = 0,
		digit, digitIndex;
	for (digitIndex = 0; i <= str.length(); i++, digitIndex++)
	{
		digit = CharToInt(str[i]);
		digit *= Pow(radix, digitIndex);
		if (!)
		{
			result += digit;
		}
	}
}