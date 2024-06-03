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


/*not quite right but too lazy to fix rn*/
int	Bitcoin::parse(t_date &d, float f)
{
	if (f < 0 || (f >= static_cast<float>(INT_MAX) || f <= static_cast<float>(INT_MIN)))
	{
		// std::cout << "f = " << f << std::endl;
		return (1);
	}
	if ((d.day > 31 || d.day < 1) || (d.month > 12 || d.month < 1) || (d.year < 2009 || d.year > 2022))
	{
		// if (d.day > 31 || d.day < 1)
		// 	std::cout << "aaaa" << std::endl;
		// if (d.month > 12 || d.month < 1)
		// 	std::cout << "bbbb" << std::endl;
		// if (d.year < 2009 || d.year > 2022)
		// 	std::cout << "ccccc" << std::endl;
		// std::cout << "d.day " << d.day << std::endl
		// 	<< "d.month " << d.month << std::endl
		// 	<< "d.year " << d.year << std::endl << "-----------" << std::endl;
		return (1);
	}
	if (d.day < 2 && d.month == 1 && d.year == 2009)
	{
		std::cout << "cccccc" << std::endl;
		return (1);
	}
	if (d.day > 29 && d.month >= 3 && d.year >= 2022)
	{
		d.day = 29;
		d.month = 3;
		d.year = 2022;
	}
	//also add: if we don't find a separator or there's no/invalid value afterwards, error

	return (0);
}

void    Bitcoin::putInMap(std::fstream &file)
{
    std::string buff;
    t_date      date;
	float		f;	//How many btcs we have (value after the comma in data.csv)

    while (std::getline(file, buff, '\n'))
    {
		//	Making the key
		date.year = atoi(buff.substr(0, 4).c_str());
		date.month = atoi(buff.substr(5, 2).c_str());
		date.day = atoi(buff.substr(8, 2).c_str());

		size_t	pos = buff.find("|");
		if (pos == std::string::npos)
			std::cout << "Error: bad input: no separator" << std::endl;///
		f = std::strtof(buff.substr(pos + 1, 10).c_str(), NULL);//this isn't the correct func to call, std::stof is better but i can't get it to work
		if (Bitcoin::parse(date, f) == 1)
		{
			if (buff.compare("date | value") == 0)	//Skips the first line of input.txt
				continue ;
			std::cerr << "Error: bad input => " << date.year
				<< "-" << date.month << "-" << date.day << std::endl;
			continue ;
		}
		// _map[date] = f * atoi(buff.substr(pos + 1, 10).c_str());	//Amount of btc we have * conversion rate
		_map.insert(std::make_pair(date, f));	//Amount of btc we have * conversion rate
    }
}

float	Bitcoin::getConversion(void)
{
	std::fstream	data;
	std::fstream	input;
	std::string		buff;
	float	f;
	
	data.open("data.csv", std::ios::in);
	if (!data)
	{
		std::cerr << "Error: error opening data file" << std::endl;
		return ;
	}
	while (std::getline(data, buff, '\n'))
	{
		if (buff.compare())
	}
	data.close();
}

void	Bitcoin::printAll(void) const
{
	//remember to implement something to add the '0' in the day/month if necessary (ex. "2011-01-03" instead of "2011-1-3")
	
	std::map<t_date, float>::const_iterator	it;

	for (it = _map.begin(); it != _map.end(); it++)
		std::cout << (*it).first.year << "-" << (*it).first.month <<  "-" << (*it).first.day << "=>" << (*it).second << std::endl; 
}