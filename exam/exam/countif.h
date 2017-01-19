#pragma once

template <class Pred, class It>
size_t CountIf(It first, const It last, Pred const & pred)
{
	size_t result = 0;
	for (; first != last; ++first)
	{
		if (pred(*first))
		{
			++result;
		}
	}
	return result;
}