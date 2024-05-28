#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
T	*easyfind(T *n1, long long n2)
{
	int *pos;
	T	*begin, *end;

	begin = &n1[0];
	for (int i = 0; n1[i]; i++)
		end = &n1[i];
	pos = std::find(begin, end, n2);
	if (*pos == *end && *end != n2)
		throw ("easyfind::NoMatchException");
	return (pos);
}