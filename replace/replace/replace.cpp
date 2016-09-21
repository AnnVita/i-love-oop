#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Replace(const string &haystack, const string &needle, const string &replace);

int main(int argc, char * argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: replace.exe <input file><output file><search string><replace string>\n";
		return 1;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ofstream output(argv[2]);

	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	if (strlen(argv[3]) == 0)
	{
		cout << "Searching string cannot be empty!\n";
		return 1;
	}

	const string searchString = argv[3];
	const string replaceString = argv[4];
	string stringToChange;

	while (getline(input, stringToChange))
	{
		stringToChange = Replace(stringToChange, searchString, replaceString);
		output << stringToChange + '\n';
	}

	if (!output.flush())
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}

    return 0;
}

string Replace(const string &haystack, const string &needle, const string &replace)
{
	int prevPos = 0, currFoundedPos = 0;
	string result = "";

	while ((currFoundedPos = int(haystack.find(needle, prevPos))) != string::npos)
	{
		result += haystack.substr(prevPos, currFoundedPos - prevPos);
		result += replace;
		prevPos = currFoundedPos + int(needle.length());
	}
	return result += haystack.substr(prevPos);
}