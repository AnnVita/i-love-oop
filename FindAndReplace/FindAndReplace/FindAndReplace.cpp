#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

static const size_t NECESSARY_NUMBER_OF_ARGUMENTS = 3;

using namespace std;

string FindAndReplace(const string &subject, const string &search, const string &replace);

int main(int argc, char * argv[])
{
	if (argc != NECESSARY_NUMBER_OF_ARGUMENTS)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: FindAndReplace.exe <search-string> <replace-string>\n";
		return EXIT_FAILURE;
	}

	if (strlen(argv[1]) == 0)
	{
		cout << "Searching string cannot be empty!\n";
		return EXIT_FAILURE;
	}

	const string searchString = argv[1];
	const string replaceString = argv[2];
	string stringToChange;

	getline(cin, stringToChange);

	stringToChange = FindAndReplace(stringToChange, searchString, replaceString);

	cout << stringToChange << '\n';
	
	return EXIT_SUCCESS;
}

string FindAndReplace(const string &subject, const string &search, const string &replace)
{
	size_t prevPos = 0, currFoundedPos = 0;
	string result = "";

	while ((currFoundedPos = subject.find(search, prevPos)) != string::npos)
	{
		result += subject.substr(prevPos, currFoundedPos - prevPos);
		result += replace;
		prevPos = currFoundedPos + search.length();
	}
	return result += subject.substr(prevPos);
}
