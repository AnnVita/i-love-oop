#pragma once
#include <vector>
#include <set>

const unsigned MIN_PRIME = 2;
const unsigned MAX_BOUND_VALUE = 100000000;

bool InsideValidRange(int upperBound);
std::vector<bool> FillSieveVector(unsigned int upperBound);
std::set<int> GenerateSetOfPrimes(unsigned int upperBound);
