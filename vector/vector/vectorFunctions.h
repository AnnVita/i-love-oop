#pragma once

using DoubleVector = std::vector <double>;
void ProcessVector(DoubleVector & vector);
double GetAverageOfPositiveElements(const DoubleVector & elements);
void AddToAllElements(DoubleVector & elements, double numberToAdd);