#include "Span.hpp"

Span::Span() : _maxStorageN(10)
{

}

Span::Span(size_t N) : _maxStorageN(N)
{

}

Span::Span(const Span& copy)
{
	this->_maxStorageN = copy.getMaxStorageN();
}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_maxStorageN = rhs.getMaxStorageN();
	}
	return (*this);
}

Span::~Span()
{

}

void	Span::printNumList(void) const
{
	size_t	size = _arr.size();
	if (_arr.empty() == true)
		throw ("Span::printNumList::emptyArrException");
	for (size_t i = 0; i < size; i++)
	{
		std::cout << _arr[i] << std::endl;
	}
}

size_t	Span::getMaxStorageN(void) const
{
	return (this->_maxStorageN);
}

/*Cette classe aura une fonction membre appelée addNumber() afin d’ajouter un seul
nombre à la Span. On l’utilisera pour remplir cette dernière. Toute tentative d’ajouter
un nouvel élément s’il y en a déjà N autres stockés jettera une exception.*/
void	Span::addNumber(const int num)
{
	if (_arr.size() >= _maxStorageN)
		throw ("Span::addNumber::tooManyElementsException");
	_arr.push_back(num);
}

void	Span::addMany(const std::vector<int> v)
{
	if (v.size() + this->_arr.size() >= _maxStorageN )
		throw ("Span::addMany::addingTooManyElementsException");
	_arr.insert(_arr.end(), v.begin(), v.end());
}

size_t	Span::shortestSpan(void)
{
	if (_arr.empty() == true)
		throw ("Span::shortestSpan::arrayEmptyException");
	std::sort(_arr.begin(), _arr.end());

	int i = _arr[0];
	while (i == _arr[i])
		i++;
	if (i == _arr.back())
		return (0);
	return (_arr[i] - _arr[i - 1]);
}

size_t	Span::longestSpan(void)
{
	if (_arr.empty() == true)
		throw ("Span::longestSpan::arrayEmptyException");
	std::sort(_arr.begin(), _arr.end());
	return ( _arr.back() - _arr.front());
}