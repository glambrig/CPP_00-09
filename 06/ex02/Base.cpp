#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base class destructor called." << std::endl;
}

Base	*generate(void)
{
	struct timeval	tv;
	size_t			rn;

 	gettimeofday(&tv, NULL);
	rn = tv.tv_sec - rand() + tv.tv_sec / 3;
	if (rn % 3 == 0)
	{
		A	*a = new A;
		std::cout << "Generating object of type A" << std::endl;
		return (a);
	}
	else if (rn % 2 == 0)
	{
		B	*b = new B;
		std::cout << "Generating object of type B" << std::endl;
		return (b);
	}
	else
	{
		C	*c = new C;
		std::cout << "Generating object of type C" << std::endl;
		return (c);
	}
	return (NULL);
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C".
void	identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << "Object of type A passed" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << "Object of type B passed" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << "Object of type C passed" << std::endl;
		return ;
	}
}

//	It prints the actual type of the object pointed to by p: "A", "B" or "C".
//	Using a pointer inside this function is forbidden.
void	identify(Base& p)
{
	int arr[3] = {0, 0, 0};

	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
	}
	catch (...)
	{
		arr[0] = 1;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
	}
	catch (...)
	{
		arr[1] = 1;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
	}
	catch (...)
	{
		arr[2] = 1;
	}
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == 0)
		{
			if (i == 0)
				std::cout << "Object of type A passed" << std::endl;
			if (i == 1)
				std::cout << "Object of type B passed" << std::endl;
			if (i == 2)
				std::cout << "Object of type C passed" << std::endl;
			return ;
		}
	}
}

