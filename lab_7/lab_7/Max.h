#pragma once

template <class T, class Less>
bool FindMaxEx(std::vector<T> const & arr, T & maxValue, Less const & less)
{
	if (arr.empty())
	{
		return false;
	}

	T tempMax = arr[0];
	for (const T & item : arr)
	{
		if (less(tempMax, item))
		{
			tempMax = item;
		}
	}

	maxValue = tempMax;

	return true;
}