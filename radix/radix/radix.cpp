#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

static const int DEC_RADIX = 10;
static const int MAX_RADIX = 36;
static const int MIN_RADIX = 2;

using namespace std;

int CharToInt(char const &ch);
bool CorrectInputRadix(int const &radix);
int StringToInt(const string &str, int radix, bool &wasError);

//void StringIntToString(int n, int radix, bool &wasError);
bool OverflowAtAddition(int const &addendum1, int const &addendum2);
bool OverflowAtMultiplication(int const &multiplier1, int const &multiplier2);
bool DigitValueBelongToRadix(int const &digitValue, int const &radix);
int Pow(int const &base, int const &exponent, bool &wasError);
//int TransferDecimalToAnother(int const &decimal, int const &destinationRadix);

int main(int argc, char * argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: radix.exe <source notation> <destination notation> <value>\n";
		return 1;
	}

	int result,
		sourceNotation = stoi(argv[1]),
		destinationNotation = stoi(argv[2]);
	string numValue = argv[3];
	bool wasError = false;

	if (!CorrectInputRadix(sourceNotation) || !CorrectInputRadix(destinationNotation))
	{
		cout << "Invalid notation values\n"
			 << "Values must be in the interval from " << MIN_RADIX << " to " << MAX_RADIX <<"\n";
		return 1;
	}

	result = StringToInt(numValue, sourceNotation, wasError);
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

bool CorrectInputRadix(int const &radix)
{
	return ((radix >= MIN_RADIX) && (radix <= MAX_RADIX));
}

bool OverflowAtAddition(int const &addendum1, int const &addendum2)
{
	return ((addendum1 > 0) && (addendum2 > 0) && (addendum1 > (INT_MAX - addendum2)));
}

bool OverflowAtMultiplication(int const &multiplier1, int const &multiplier2)
{
	return (multiplier1 >= INT_MAX / multiplier2);
}

int Pow(int const &base, int const &exponent, bool &wasError)
{
	int i, result = 1;
	for (i = exponent; i > 0; i--)
	{
		if (OverflowAtMultiplication(result, base))
		{
			result = -1;
			wasError = true;
			break;
		}
		else
			result *= base;
	}
	return result;
}

bool DigitValueBelongToRadix(int const &digitValue, int const &radix)
{
	return (digitValue < radix) && (digitValue >= 0);
}

int StringToInt(const string &str, int radix, bool &wasError)
{
	bool isNegative = (str[0] == '-');
	int i, digit, digitIndex, powOfTheRadix,
		result = 0;
	for (digitIndex = 0, i = str.length() - 1; (i >= (int)isNegative) && (!wasError); i--, digitIndex++)
	{
		digit = CharToInt(str[i]);
		wasError = !DigitValueBelongToRadix(digit, radix);
		powOfTheRadix = Pow(radix, digitIndex, wasError);
		wasError = (wasError) || (OverflowAtMultiplication(digit, powOfTheRadix));
		digit = (!wasError) ? digit * powOfTheRadix : -1 ;
		wasError = (wasError) || (OverflowAtAddition(result, digit));
		result = (!wasError) ? result + digit: -1 ;
	}
	return result;
}