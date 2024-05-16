#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
public:
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter();
	static void	convert(std::string s);
};

#endif