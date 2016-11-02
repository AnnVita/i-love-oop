#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using DoubleVector = std::vector <double>;
void ProcessVector(DoubleVector & vector);
double GetAverageOfPositiveElements(const DoubleVector & elements);
void AddToAllElements(DoubleVector & elements, double numberToAdd);