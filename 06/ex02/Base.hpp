#pragma once

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <typeinfo>

class Base
{
public:
	virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base& p);