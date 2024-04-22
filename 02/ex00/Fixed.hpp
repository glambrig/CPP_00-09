#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
private:
	int					_fixed;
	static int const	_bits = 8;
public:
	Fixed(void);
	Fixed(const Fixed& copy);
	~Fixed(void);
	Fixed&	operator=(const Fixed& var);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif