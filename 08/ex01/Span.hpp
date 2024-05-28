#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	size_t				_maxStorageN;
	std::vector<int>	_arr;
public:
	Span();
	Span(size_t N);
	Span(const Span& copy);
	Span& operator=(const Span& rhs);
	~Span();

	void	printNumList(void) const;
	size_t	getMaxStorageN(void) const;

	void	addNumber(const int num);
	void	addMany(const std::vector<int> v);
	size_t	shortestSpan(void);
	size_t	longestSpan(void);
};