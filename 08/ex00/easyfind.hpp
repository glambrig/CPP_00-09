#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &arr, long long n2)
{
	typename T::iterator pos;

	pos = std::find(arr.begin(), arr.end(), n2);
	if (pos == arr.end())
		throw ("easyfind::NoMatchException");
	return (pos);
}