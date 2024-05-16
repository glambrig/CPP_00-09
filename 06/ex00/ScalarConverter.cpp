#include "ScalarConverter.hpp"

int	handleNan(const std::string str)
{
	std::string s = str;
	float	test = strtof(s.c_str(), NULL);
	int		i = atoi(s.c_str());

	for (int i = 0; str[i]; i++)
		s[i] = std::toupper(str[i]);
	if (s.compare("NAN") == 0 || s.compare("NANF") == 0 || isnan(test) == 1
		|| (i == 0 && s[0] != '0'))
	{
		std::cout << "as int: impossible" << std::endl;
		std::cout << "as char: impossible" << std::endl;
		std::cout << "as float: nanf" << std::endl;
		std::cout << "as double: nan" << std::endl;
		return (1);	
	}
	return (0);
}

int	handleInf(const std::string str)
{
	std::string s = str;
	double	test = strtod(s.c_str(), NULL);

	if (std::isfinite(test) == 0)
	{
		for (int i = 0; str[i]; i++)
			s[i] = std::toupper(str[i]);
		if (s.compare("+INF") == 0 || s.compare("+INFF") == 0)
		{
			std::cout << "as int: impossible" << std::endl;
			std::cout << "as char: impossible" << std::endl;
			std::cout << "as float: +Inff" << std::endl;
			std::cout << "as double: +Inf" << std::endl;
			return (1);	
		}
		else if (s.compare("-INF") == 0 || s.compare("-INFF") == 0)
		{
			std::cout << "as int: impossible" << std::endl;
			std::cout << "as char: impossible" << std::endl;
			std::cout << "as float: -Inff" << std::endl;
			std::cout << "as double: -Inf" << std::endl;
			return (1);	
		}
	}
	return (0);
}

void	checkInt(int num)
{
	long long i = static_cast<long long>(num);
	if (i >= INT_MAX || i <= INT_MIN)
	{
		std::cout << "as int: impossible" << std::endl;
		return ;
	}
	std::cout << "as int: " << i << std::endl;
}

void	checkChar(char c, int i)
{
	if ((i >= 0 && i <= 31) || i == 127)
		std::cout << "as char: non displayable" << std::endl;
	else if (i > 127 || i < 0)
		std::cout << "as char: impossible" << std::endl;
	else
		std::cout << "as char: " << '\'' << c << '\'' << std::endl;
}

int	checkFloat(float f, double d, std::string s)
{
	if (d >= DBL_MAX || d <= DBL_MIN)
	{
		std::cout << "as float: impossible" << std::endl;
		std::cout << "as double: impossible" << std::endl;
		return (1);
	}
	if (f >= FLT_MAX || f <= FLT_MIN)
	{
		std::cout << "as float: impossible" << std::endl;
		std::cout << "as double: " << d << std::endl;
		return (0);
	}
	if (s.find(".") != std::string::npos)	//If there's a decimal point
	{
		std::cout << "as float: " << f  << "f" << std::endl;
		std::cout << "as double: " << d << std::endl;
		return (0);
	}
	std::cout << "as float: " << f << ".0f" << std::endl;
	std::cout << "as double: " << d << ".0" << std::endl;
	return (0);
}

void	ScalarConverter::convert(std::string s)
{
	if (handleInf(s) == 1 || handleNan(s) == 1)
		return ;

	double	d = strtod(s.c_str(), NULL);
	float	f = static_cast<float>(d);
	int		i = static_cast<int >(d);
	char	c = static_cast<char >(d);
	
	checkChar(c, i);
	checkInt(i);
	checkFloat(f, d, s);
}