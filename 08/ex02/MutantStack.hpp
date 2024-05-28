#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack
{
private:
	std::stack<T>	_stack;
public:
	MutantStack();
	MutantStack(const MutantStack& copy);
	MutantStack& operator=(const MutantStack& rhs);
	~MutantStack();

	bool	empty(void) const;
	size_t	size(void) const;
	void	push(T elem);
	void	pop(void);
	T&		top(void) const;
};

// #include "MutantStack.tpp"