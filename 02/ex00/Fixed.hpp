/**
 * @brief The Fixed class represents a fixed point number.
 * 
 * A fixed point number is a numeric data type that has a fixed number of digits
 * after the decimal point. It is used to represent decimal numbers with a fixed
 * precision, as opposed to floating point numbers which have a variable precision.
 * 
 * The Fixed class provides methods to store, retrieve, and manipulate fixed point numbers.
 * It also supports assignment, copy construction, and destruction operations.
 * 
 * The Fixed class has a private member variable '_fixed' which stores the value of the fixed point number.
 * The number of bits used to represent the fractional part of the fixed point number is defined as '_bits'.
 * 
 * Example usage:
 * 
 * Fixed number; // Create a Fixed object
 * number.setRawBits(1234); // Set the raw bits of the fixed point number
 * int raw = number.getRawBits(); // Get the raw bits of the fixed point number
 * 
 * @see https://en.wikipedia.org/wiki/Fixed-point_arithmetic
 */
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