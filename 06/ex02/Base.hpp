#pragma once

#include <iostream>
#include <cstdlib>
#include <sys/time.h>

class Base
{
public:
	virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base& p);