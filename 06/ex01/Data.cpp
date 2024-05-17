#include "Data.hpp"

Data::Data(size_t num) : _data(num)
{

}

Data::Data()
{

}

Data::Data(const Data& copy)
{
	*this = copy;
}

Data& Data::operator=(const Data& rhs)
{
	this->_data = rhs.getData();
	return (*this);
}

Data::~Data()
{

}


size_t	Data::getData(void) const
{
	return (this->_data);
}