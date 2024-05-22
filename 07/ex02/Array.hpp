#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T		*_arr;
	size_t	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& copy);
	Array& operator=(Array& rhs);
	~Array();

	int	size(void) const;
	T		*getArr(void) const;
	T 		&operator[](int index);

	class	ArrayException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("ArrayException::WrongIndexException");
		}
	};
};

#include "Array.tpp"