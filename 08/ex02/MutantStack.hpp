#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container >
{
public:
	MutantStack(){}
	MutantStack(const MutantStack& copy)
	{
		*this = copy;
	}
	MutantStack& operator=(const MutantStack& rhs)
	{
		if (this != &rhs)
			*this = rhs;
		return (*this);
	}
	~MutantStack(){}

	typedef typename Container::iterator iterator;

	iterator	begin(void) {return (this->c.begin());}
	iterator	end(void) {return (this->c.end());}
};