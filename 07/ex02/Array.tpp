#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_arr = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_arr = new T[n + 1];
	for (unsigned int i = 0; i < n; i++)
	{
		this->_arr[i] = 0;
	}
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	if (this != &copy)
	{
		this->_arr = copy.getArr();
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> &rhs)
{
	this->_arr = rhs.getArr();
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->_size > 0)
		delete[] this->_arr;
	//Does this leak when default (empty) constructor is called?
}

template <typename T>
int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
T	*Array<T>::getArr(void) const
{
	return (this->_arr);
}

template <typename T>
T&	Array<T>::operator[](int index)
{
	if (index >= this->size() || index < 0)
		throw (ArrayException());
	return (this->_arr[index]);
}
