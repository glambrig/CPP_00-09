#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base *test = generate();
	
	std::cout << std::endl << "Passing by pointer:" << std::endl;
	identify(test);
	std::cout << std::endl << "Passing by reference:" << std::endl;
	identify(*test);
	
	std::cout << std::endl;
	delete test;
	return (0);
}