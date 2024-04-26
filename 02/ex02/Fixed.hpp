#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
private:
	int					_fixed;
	static int const	_bits = 8;
public:
	Fixed(void);
	Fixed(const Fixed& copy);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);
	Fixed&	operator=(const Fixed& instance);
	bool	operator>(const Fixed& instance) const;
	bool	operator<(const Fixed& instance) const;
	bool	operator>=(const Fixed& instance) const;
	bool	operator<=(const Fixed& instance) const;
	bool	operator==(const Fixed& instance) const;
	bool	operator!=(const Fixed& instance) const;
	float	operator+(const Fixed& instance) const;
	float	operator-(const Fixed& instance) const;
	float	operator/(const Fixed& instance) const;
	float	operator*(const Fixed& instance) const;
	Fixed&	operator++();
	Fixed&	operator++(int);
	Fixed&	operator--();
	Fixed&	operator--(int);
	static Fixed&			min(Fixed& f1, Fixed& f2);
	static const Fixed&		min(const Fixed& f1, const Fixed& f2);
	static Fixed&			max(Fixed& f1, Fixed& f2);
	static const Fixed&		max(const Fixed& f1, const Fixed& f2);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	float	toFloat(int i) const;
	int		toInt(void) const;
	int		toInt(float f) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& var);

#endif