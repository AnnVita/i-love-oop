#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h> 

using namespace std;

int CharToInt(char const &ch);
bool CheckInputRadix(int const &radix);
int StringToInt(const string &str, int radix, bool &wasError);

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
	return ((radix >= 2) && (radix <= 36));
}

int StringToInt(const string &str, int radix, bool &wasError)
{
	bool isNegate = (str[0] == '-');
	int i = (isNegate ? 1 : 0),
		result = 0,
		digit, digitIndex;
	for (digitIndex = 0; i <= str.length(); i++, digitIndex++)
	{
		digit = CharToInt(str[i]) * int(pow(radix, digitIndex));
		if (!((digit > 0) && (result > (INT_MAX - digit)))
		{
			result += digit;
		}
	}
}