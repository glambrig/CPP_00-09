#pragma once

#include <cstddef>

class Data
{
private:
	size_t _data;
	Data();
public:
	Data(size_t num);
	Data(const Data& copy);
	Data& operator=(const Data& rhs);
	~Data();

	size_t	getData(void) const;
};