#include "MutantStack.hpp"

//REMEMEBER TO RENAME THIS TO .TPP INSTEAD OF .CPP

template <typename T>
MutantStack<T>::MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy)
{
	*this = copy;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
bool	MutantStack<T>::empty(void) const
{
	return (_stack.empty());
}

template <typename T>
size_t	MutantStack<T>::size(void) const
{
	return (_stack.size());
}

template <typename T>
void	MutantStack<T>::push(T elem)
{
	_stack.push(elem);
}

template <typename T>
void	MutantStack<T>::pop(void)
{
	_stack.pop();
}

template <typename T>
T&	MutantStack<T>::top(void) const
{
	return (_stack.top());
}
