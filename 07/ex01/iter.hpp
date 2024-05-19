#pragma once

#include <iostream>
#include <cctype>

template <typename T1>
void	iter(T1 *arr, size_t len, void (*f)(T1 &elem_to_modify))
{
	for (size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}