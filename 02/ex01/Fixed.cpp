#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n)
{
	//google: how to convert an int to fixed point
	std::cout << "Int constructor called" << std::endl;
	this->toFloat();
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->toInt();
}

Fixed& Fixed::operator=(const Fixed& var)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &var)
	{
		this->_fixed = var.getRawBits();
	}
	return (*this);
}

Fixed&	Fixed::operator<<(const std::ostream stream)
{
	std::cout << "Insertion operator called" << std::endl;
	stream << this->toFloat(this->_fixed) << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_fixed)) // this is just a guess
}

int		Fixed::toInt(void) const
{
	return (this->_fixed << this->_bits); // also a guess
}