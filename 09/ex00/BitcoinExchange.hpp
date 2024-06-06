#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <climits>
#include <cstdlib>
#include <algorithm>

typedef struct s_date
{
    int day;
    int month;
    int year;
	std::string sday;
	std::string smonth;
	std::string syear;
	bool	operator<(const struct s_date rhs) const;
}   t_date;

class   Bitcoin
{
private:
    std::multimap<t_date, float>    _map;
public:
    Bitcoin();
    Bitcoin(const Bitcoin& copy);
    ~Bitcoin();
    Bitcoin&	operator=(const Bitcoin& rhs);

    void    		putInMap(std::fstream &file);
	static int		parse(t_date &date, float f);
	float			getConversion(t_date &d, float amount) const;
	void			print(t_date &d, float amount) const;
};