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
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = n << this->_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = toInt(f);
}

Fixed& Fixed::operator=(const Fixed& var)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &var)
		this->_fixed = var.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& var)
{
	// std::cout << "Insertion operator called" << std::endl;
	stream << var.toFloat(var.getRawBits());
	return (stream);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_fixed) / (float)(1 << this->_bits));
}

float	Fixed::toFloat(int i) const
{
	return ((float)(i) / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixed >> this->_bits);
}

int		Fixed::toInt(float f) const
{
	int	res =  roundf(f * (1 << this->_bits));
	return (res);
}