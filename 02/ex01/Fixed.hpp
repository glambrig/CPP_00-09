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
	Fixed&	operator=(const Fixed& var);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	float	toFloat(int i) const;
	int		toInt(void) const;
	int		toInt(float f) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& var);

#endif