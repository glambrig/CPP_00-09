#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed::Fixed(const int n)
{
	this->_fixed = n << this->_bits;
}

Fixed::Fixed(const float f)
{
	this->_fixed = toInt(f);
}

Fixed& Fixed::operator=(const Fixed& var)
{
	if (this != &var)
		this->_fixed = var.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& var)
{
	stream << var.toFloat(var.getRawBits());
	return (stream);
}

bool	Fixed::operator>(const Fixed& instance) const
{
	if (this->_fixed > instance._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& instance) const
{
	if (this->_fixed < instance._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& instance) const
{
	if (this->_fixed >= instance._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& instance) const
{
	if (this->_fixed <= instance._fixed)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& instance) const
{
	if (this->_fixed == instance._fixed)
		return(true);
	return(false);
}

bool	Fixed::operator!=(const Fixed& instance) const
{
	if (this->_fixed != instance._fixed)
		return(true);
	return(false);
}

float	Fixed::operator+(const Fixed& instance) const
{
	float a, b, res;

	a = toFloat(this->_fixed);
	b = toFloat(instance._fixed);
	res = a + b;
	return (res);
	// float a, b, res;
	// int	conv;

	// a = toFloat(this->_fixed);
	// b = toFloat(instance._fixed);
	// res = a + b;
	// conv = toInt(res);
	// return (conv >> this->_bits);
}

float	Fixed::operator-(const Fixed& instance) const
{
	float a, b, res;

	a = toFloat(this->_fixed);
	b = toFloat(instance._fixed);
	res = a - b;
	return (res);
	// float a, b, res;
	// int	conv;

	// a = toFloat(this->_fixed);
	// b = toFloat(instance._fixed);
	// res = a - b;
	// conv = toInt(res);
	// return (conv >> this->_bits);
}

float	Fixed::operator*(const Fixed& instance) const
{
	float a, b, res;

	a = toFloat(this->_fixed);
	b = toFloat(instance._fixed);
	res = a * b;
	return (res);
}

float	Fixed::operator/(const Fixed& instance) const
{
	float a, b, res;

	a = toFloat(this->_fixed);
	b = toFloat(instance._fixed);
	res = a / b;
	return (res);
	// float a, b, res;
	// int	conv;

	// a = toFloat(this->_fixed);
	// b = toFloat(instance._fixed);
	// res = a / b;
	// conv = toInt(res);
	// return (conv >> this->_bits);
}

Fixed& Fixed::operator++(void)
{
	this->_fixed++;
	return (*this);
}

/*Postfix*/
Fixed& Fixed::operator++(int)
{
	static Fixed temp(*this);

	this->_fixed++;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	this->_fixed--;
	return (*this);
}

/*Postfix*/
Fixed& Fixed::operator--(int)
{
	this->_fixed--;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
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

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}