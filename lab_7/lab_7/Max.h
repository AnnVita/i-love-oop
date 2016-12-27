#pragma once

template <class T, class Less>
bool FindMaxEx(std::vector<T> const & arr, T & maxValue, Less const & less)
{
	if (arr.empty())
	{
		return false;
	}

	for (const T & item : arr)
	{
		if (less(maxValue, item))
		{
			maxValue = item;
		}
	}
	return true;
}