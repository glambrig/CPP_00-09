#include "BitcoinExchange.hpp"

bool	s_date::operator<(const struct s_date rhs) const
{
	return (this->day < rhs.day || this->month < rhs.month || this->year < rhs.year);
}

Bitcoin::Bitcoin()
{

}

Bitcoin::~Bitcoin()
{

}

Bitcoin&    Bitcoin::operator=(const Bitcoin& rhs)
{
    (void)rhs;
    return (*this);
}

Bitcoin::Bitcoin(const Bitcoin& copy)
{
    if (this != &copy)
    {
        *this = copy;
    }
}

int	Bitcoin::parse(t_date &d, float f)
{
	long long i = static_cast<long long>(f);

	if (i < 0)
		return (1);
	if (i >= INT_MAX || i <= INT_MIN)
	{
		return (2);
	}
	if ((d.day > 31 || d.day < 1) || (d.month > 12 || d.month < 1) || d.year < 2009)
		return (3);
	if (d.day < 2 && d.month == 1 && d.year == 2009)
		return (3);
	if ((d.day > 29 && d.month >= 3 && d.year == 2022) || d.year > 2022)
	{
		d.day = 29;
		d.month = 3;
		d.year = 2022;
		d.sday = "29";
		d.smonth = "03";
		d.syear = "2022";
	}
	//also add: if we don't find a separator or there's no/invalid value afterwards, error
	return (0);
}

void    Bitcoin::putInMap(std::fstream &file)
{
    std::string buff;
    t_date      date;
	float		f;	//How many btcs we have (value after the | in input.txt)
	int			flag;

    while (std::getline(file, buff, '\n'))
    {
		//	Making the key
		date.year = atoi(buff.substr(0, 4).c_str());
		date.month = atoi(buff.substr(5, 2).c_str());
		date.day = atoi(buff.substr(8, 2).c_str());
		date.syear = buff.substr(0, 4);
		date.smonth = buff.substr(5, 2);
		date.sday = buff.substr(8, 2);

		size_t	pos = buff.find("|");
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input: no separator" << std::endl;
			continue ;
		}
		f = std::strtof(buff.substr(pos + 1, 12).c_str(), NULL);//this isn't the correct func to call, std::stof is better but i can't get it to work
		flag = Bitcoin::parse(date, f);
		if (flag > 0)
		{
			if (buff.compare("date | value") == 0)	//Skips the first line of input.txt
				continue ;
			if (flag == 1)
				std::cout << "Error: not a positive number : " << f << std::endl;
			if (flag == 2)
					std::cout << "Error: too large a number."  << std::endl;
			if (flag == 3)
				std::cerr << "Error: bad input => " << date.syear
					<< "-" << date.smonth << "-" << date.sday << std::endl;
			continue ;
		}
		_map.insert(std::make_pair(date, f));
		print(date, f);
    }
}

float	Bitcoin::getConversion(t_date &d, float amount) const
{
	std::ifstream	data("data.csv");	//to read from data.csv
	std::string		buff;
	std::string		last;
	std::string		targetDate;
	size_t			pos = std::string::npos;

	if (!data.is_open())
		throw ("Bitcoin::getConversion::errorOpeningFile") ;
	std::getline(data, buff);
	targetDate = d.syear + "-" + d.smonth + "-" + d.sday;
	while (std::getline(data, buff))
	{
		std::string currentLineDate = buff.substr(0, 10);
		if (currentLineDate == targetDate)
		{
			pos = buff.find(',');
			break ;
		}
		last = buff;
		if (currentLineDate > targetDate)
		{
			buff = last;
			pos = buff.find(',');
			break ;
		}
	}
	data.close();
	if (pos == std::string::npos)
	{
		std::cerr << "Error: no valid conversion rate found for date " << targetDate << std::endl;
		return (0.0);
	}
	float rate = std::strtof(buff.substr(pos + 1).c_str(), NULL);
	return (amount * rate);
}

void	Bitcoin::print(t_date &d, float amount) const
{
		std::cout << d.syear << "-" << d.smonth <<  "-" << d.sday
			<< " => " << amount << " = " << getConversion(d, amount) << std::endl; 
}