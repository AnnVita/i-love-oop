/* replace.cpp : ��������� ������ ��������� � ��������� ����� �� ������ ������,
� ���������� ��������� � �������� ���� (�������� �� ��������).
������ ���������� ������: replace.exe <input file><output file><search string><replace string>
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "replace.exe <input file><output file><search string><replace string>\n";
		return 1;
	}

    return 0;
}

