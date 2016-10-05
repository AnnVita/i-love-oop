#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

static const int DEC_RADIX = 10;
static const int MAX_RADIX = 36;
static const int MIN_RADIX = 2;

using namespace std;

int CharToInt(char ch);
int StringToInt(const string &str, int radix, bool &wasError);
bool CorrectInputRadix(int radix);
bool OverflowAtAddition(int addendum1, int addendum2);
bool OverflowAtMultiplication(int multiplier1, int multiplier2);
bool DigitValueBelongToRadix(int digitValue, int radix);
int Pow(int base, int exponent, bool &wasError);
char IntToChar(int integer);
string IntToString(int n, int radix, bool &wasError);

string TranslateFromOneRadixToAnother(int sourceNotation, int destinationNotation, string const& valueForTranslate);

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
	string valueToTranslate = argv[3], translatedValue;

	if (!CorrectInputRadix(sourceNotation) || !CorrectInputRadix(destinationNotation))
	{
		cout << "Invalid notation values\n"
			 << "Values must be in the interval from " << MIN_RADIX << " to " << MAX_RADIX <<"\n";
		return 1;
	}

	translatedValue = TranslateFromOneRadixToAnother(sourceNotation, destinationNotation, valueToTranslate);
	if (translatedValue.size() != 0)
	{
		cout << translatedValue;
	}
	else
	{
		cout << "An error has occurred.\nCheck your entries, please.\n";
		return 1;
	}
	
	return 0;
}

string TranslateFromOneRadixToAnother(int sourceNotation, int destinationNotation, string const& valueForTranslate)
{
	int decimalValue;
	string result;
	bool wasError = false;
	decimalValue = StringToInt(valueForTranslate, sourceNotation, wasError);
	if (wasError)
	{
		return "";
	}
	else
	{
		result = IntToString(decimalValue, destinationNotation, wasError);
		if (wasError)
		{
			return "";
		}
	}
	return result;
}

int CharToInt(char ch)
{
	int number = -1;
	bool numericCh = ((ch >= '0') && (ch <= '9')),
		alphabeticCh = ((ch >= 'A') && (ch <= 'Z'));
	if (numericCh)
	{
		number = static_cast<int>(ch - '0');
	}
	else if (alphabeticCh)
	{
		number = int(ch) - int('A') + DEC_RADIX;
	}
	return number;
}

char IntToChar(int value)
{
	char ch = -1;
	bool numericCh = ((value >= 0) && (value <= 9)),
		alphabeticCh = ((value >= 10) && (value < MAX_RADIX));
	if (numericCh)
	{
		ch = static_cast<char>(value + '0');
	}
	else if (alphabeticCh)
	{
		ch = static_cast<char>(value + 'A' - DEC_RADIX);
	}
	return ch;
}

bool CorrectInputRadix(int radix)
{
	return ((radix >= MIN_RADIX) && (radix <= MAX_RADIX));
}

bool OverflowAtAddition(int addendum1, int addendum2)
{
	return ((addendum1 > 0) && (addendum2 > 0) && (addendum1 > (INT_MAX - addendum2)));
}

bool OverflowAtMultiplication(int multiplier1, int multiplier2)
{
	return (multiplier1 >= INT_MAX / multiplier2);
}

int Pow(int base, int exponent, bool &wasError)
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

bool DigitValueBelongToRadix(int digitValue, int radix)
{
	return (digitValue < radix) && (digitValue >= 0);
}

int StringToInt(const string &str, int radix, bool &wasError)
{
	bool isNegative = (str[0] == '-');
	int i, digit, digitIndex, powOfTheRadix, result = 0;
	for (digitIndex = 0, i = str.length() - 1; (i >= (isNegative)) && (!wasError); i--, digitIndex++)
	{
		digit = CharToInt(str[i]);
		wasError = !DigitValueBelongToRadix(digit, radix);
		powOfTheRadix = Pow(radix, digitIndex, wasError);
		wasError = (wasError) || (OverflowAtMultiplication(digit, powOfTheRadix));
		digit = (!wasError) ? digit * powOfTheRadix : -1 ;
		wasError = (wasError) || (OverflowAtAddition(result, digit));
		result = (!wasError) ? result + digit: -1 ;
	}
	return (isNegative) ? result * -1 : result;
}

string IntToString(int n, int radix, bool &wasError)
{
	bool isNegative = (n < 0);
	string result;
	int reside;
	char digit;
	if (isNegative)
	{
		n *= -1;
		result += '-';
	}
	reside = n % radix;
	while (n >= radix)
	{
		digit = IntToChar(reside);
		if (digit < 0)
		{
			wasError = true;
			break;
		}
		result += digit;
		n /= radix;
		reside = n % radix;
	}
	digit = IntToChar(reside);
	result += digit;
	reverse(result.begin() + (int)(isNegative), result.end()); 
	return result;
}